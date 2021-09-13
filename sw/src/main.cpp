#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <avr/sleep.h>
#include <config.hpp>

VL53L0X sensor;
static volatile uint8_t  blink = batt_low_num_blinks;   //blink activated with = 0
static volatile uint8_t blink_cycles = 0;
static volatile bool needBatteryCheck = false;
static volatile bool over_threshold = false;
static uint32_t last_unmute;
static uint8_t  consecutive_equal_measurements = 0;


void switchOnBlink()
{
    for(uint8_t i = 0; i < 2; i++)  // Switch-on blink
    {
        digitalWrite(LED, 1);
        digitalWrite(J2, 1);
        delay(100);
        digitalWrite(LED, 0);
        digitalWrite(J2, 0);
        delay(50);
    }
}

void readyBlink()
{
    digitalWrite(LED, 1);
    digitalWrite(J2, 1);
    delay(100);
    digitalWrite(LED, 0);
    digitalWrite(J2, 0);
    delay(50);
}

void initBattCheckTimer()
{
    cli();	//disable interrupts
    //set timer1 interrupt
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0

    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS12 and CS10 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // set compare match register
    static_assert((BATT_BLINK_CYCLE_DURATION_S*CPU_FREQ)/1024 < (uint32_t(1) << 17), "battery check timer would overflow");
    OCR1A = static_cast<uint16_t>((BATT_BLINK_CYCLE_DURATION_S*CPU_FREQ)/1024); //(x sec * 1MHz)/1024 = 244

    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();	//allow interrupts
}

ISR(TIMER1_COMPA_vect)
{
    if(blink < batt_low_num_blinks)
    {
        digitalWrite(LED, over_threshold ^ (blink & 1));
        blink ++;
    }

    // time between battery checks is measured in blink cycles
    // (to save timers)
    if(blink_cycles++ >= BATT_MEASURE_CYCLES)
    {
        needBatteryCheck = true;
        blink_cycles = 0;
    }
}

void setup() {
    pinMode(J0, OUTPUT);
    pinMode(J1, OUTPUT);
    pinMode(J2, OUTPUT);
    pinMode(MUTE, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(POT, INPUT);

    Wire.begin();
    //Wire.setClock(400000);  // MORE GAIN

    if(has_serial)
    {
        Serial.begin(115200);
        while (!Serial) {
            digitalWrite(LED, 1);
            delay(250);
            digitalWrite(LED, 0);
            delay(25);
        }
    }
    else
    {
        switchOnBlink();
    }

    if(has_serial && Serial) Serial.println("initing Sensor...");

    digitalWrite(J0, 1);
    sensor.setTimeout(SENSOR_COMM_TIMEOUT_MS);
    while (!sensor.init())
    {
        digitalWrite(LED, 1);
        delay(50);
        digitalWrite(LED, 0);
        delay(50);
        if(has_serial && Serial) Serial.println("...");
    };

    if(has_serial && Serial) Serial.println("done");
    digitalWrite(J0, 0);

    digitalWrite(J1, 1);
    // (default is 0.25 MCPS)
    //sensor.setSignalRateLimit(0.1);
    // (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 12);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 8);
    if(!sensor.setMeasurementTimingBudget(MEASUREMENT_TIMING_BUDGET_US))
    {
        while(true)
        {
            digitalWrite(LED, 1);
            delay(350);
            digitalWrite(LED, 0);
            delay(100);
        }
    }

    last_unmute = millis();
    sensor.startContinuous(TOT_MEAS_CYCLE_MS);
    digitalWrite(J1, 0);

    if(has_serial && Serial)
    {
        Serial.println("Configured Sensor.");
        Serial.print("SignalRateLimit: ");
        Serial.println(sensor.getSignalRateLimit());
        Serial.print("MeasurementTimingBudget: ");
        Serial.println(sensor.getMeasurementTimingBudget());
    }

    if(NUM_BATTERIES > 0)
    {
        initBattCheckTimer();
    }

    readyBlink();
}

/*
@return values 0 - ~5000
*/
uint16_t readVcc_mV() {
  uint16_t result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return result;
}

bool isBatteryOk()
{
    if(NUM_BATTERIES > 0)
        return readVcc_mV() > WRN_VOLTAGE_ALKALINE_mV*NUM_BATTERIES;
    else
        return true;
}

void loop() {

    if(has_serial && Serial) Serial.println("Measuring...");

    digitalWrite(J2, 1);
    uint16_t distance = sensor.readRangeContinuousMillimeters();
    digitalWrite(J2, 0);
    uint16_t switching_distance = (static_cast<uint32_t>(analogRead(POT)) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    if(!over_threshold) //debounce
        switching_distance += DEBOUNCE_RANGE_MM;

    bool previous_measurement_over_threshold = over_threshold;


    if(switching_distance >= MAX_RANGE_MM-1) {
        // this creates an "always on / unmute" region
        // at the plus end of the poti
        over_threshold = false;
    } else if (distance > DEADZONE_LOW_MM) {
        // if lower than deadzone, no update happens
        over_threshold =  distance > switching_distance;
    }

    if(previous_measurement_over_threshold != over_threshold) {
        consecutive_equal_measurements = 1;
    } else {
        if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED)
            consecutive_equal_measurements++;
    }
    if(!over_threshold)
    {   // save last time we measured something near
        last_unmute = millis();
    }

    if(has_serial && Serial)
    {
        Serial.print(distance);
        Serial.print(" > ");
        Serial.print((static_cast<uint32_t>(analogRead(POT)) * MAX_RANGE_MM)/MAX_ANALOG_READ);
    }
    if (sensor.timeoutOccurred())
    {
        // Communication with Sensor did not succeed
        if(has_serial && Serial) Serial.println("Timeout.");
        for(uint8_t i = 0; i < 2; i++)
        {
            digitalWrite(LED, 1);
            delay(100);
            digitalWrite(LED, 0);
            delay(100);
        }
        return;
    }

    if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED) {
        // not yet enough equal measurements, stick to the "old" value
        //digitalWrite(MUTE, !over_threshold); // not needed, GPIO has memory!
    } else {
        digitalWrite(MUTE, over_threshold);
        if(blink >= batt_low_num_blinks)    //we are not blinking right now
            digitalWrite(LED, over_threshold);
    }

    // Warn if going to shut down
    if(millis() - last_unmute > (IDLE_TIMEOUT_S-IDLE_TIMEOUT_WARN_S)*1000)
    {
        blink = 0;
        if(millis() - last_unmute > IDLE_TIMEOUT_S*1000)
        {
            sensor.stopContinuous();
            digitalWrite(MUTE, IDLE_MUTE_STATE);
            digitalWrite(LED, 0);
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            ADCSRA &= ~(1<<ADEN); // disable ADC (before power-off)
            sleep_enable();
            sleep_cpu();
        }
    }

    if(needBatteryCheck && !isBatteryOk())
    {
        blink = 0;                      // starts blinking
        needBatteryCheck = false;       // reset time for next check
    }
}
