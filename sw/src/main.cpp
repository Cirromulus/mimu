#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <avr/sleep.h>
#include <pins.hpp>

static constexpr uint32_t CPU_FREQ = F_CPU;
static constexpr uint16_t MAX_RANGE_MM = 700;
static constexpr uint16_t DEBOUNCE_RANGE_MM = 10;
static constexpr uint32_t IDLE_TIMEOUT_S = 2*60*60;     // two hours
static constexpr uint32_t IDLE_TIMEOUT_WARN_S = 30*60;  // thirty minutes before
static constexpr bool     IDLE_MUTE_STATE = false;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
static constexpr float    BATT_BLINK_S = 0.25;
static constexpr uint16_t BATT_MEASURE_S = 60;
static constexpr uint16_t BATT_MEASURE_CYCLES = BATT_MEASURE_S/BATT_BLINK_S;
static constexpr uint8_t  MEASUREMENT_DELAY_MS = 20;
static constexpr uint8_t  NUM_BATTERIES = 3;
static constexpr uint16_t MAX_VOLTAGE_ALKALINE_mV = 1500;
static constexpr uint16_t WRN_VOLTAGE_ALKALINE_mV = 1100;
static constexpr uint16_t MIN_VOLTAGE_ALKALINE_mV = 1000;
static constexpr uint8_t  batt_low_num_blinks = 4*2;  //important: needs to be dividable by 2

VL53L0X sensor;
static volatile uint8_t  blink = batt_low_num_blinks;   //blink activated with = 0
static volatile uint16_t blink_cycles = 0;
static volatile bool needBatteryCheck = false;
static volatile uint8_t over_threshold = false;
static uint32_t last_unmute;


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
    OCR1A = static_cast<uint8_t>((BATT_BLINK_S*CPU_FREQ)/1024); //(x sec * 1MHz)/1024 = 244

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
    sensor.setTimeout(100);
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
    if(hi_range)
    {
        // lower the return signal rate limit (default is 0.25 MCPS)
        sensor.setSignalRateLimit(0.1);
        // increase laser pulse periods (defaults are 14 and 10 PCLKs)
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
        // increase timing budget to 200 ms (default is about 33 ms)
        sensor.setMeasurementTimingBudget(200000);
    }
    else
    {
        /*
        // No special increase in speed
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 12);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 8);
        */

        // lower timing budget to absoulte minimum (default is about 33 ms)
        if(!sensor.setMeasurementTimingBudget(20000))
        {
            while(true)
            {
                digitalWrite(LED, 1);
                delay(250);
                digitalWrite(LED, 0);
                delay(100);
            }
        }
        //increase SignalRateLimit
        //sensor.setSignalRateLimit(0.5);   //no significant speedup
    }
    last_unmute = millis();
    sensor.startContinuous(MEASUREMENT_DELAY_MS);
    digitalWrite(J1, 0);

    if(has_serial && Serial)
    {
        Serial.println("Configured Sensor.");
        Serial.print("SignalRateLimit: ");
        Serial.println(sensor.getSignalRateLimit());
        Serial.print("MeasurementTimingBudget: ");
        Serial.println(sensor.getMeasurementTimingBudget());
    }

    if(use_batt_check)
    {
        initBattCheckTimer();
    }

    readyBlink();
}

long readVcc_mV() {
  long result;
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
	return readVcc_mV() > WRN_VOLTAGE_ALKALINE_mV*NUM_BATTERIES;
}

void loop() {

    if(has_serial && Serial) Serial.println("Measuring...");

    digitalWrite(J2, 1);
    uint16_t distance = sensor.readRangeContinuousMillimeters();
    digitalWrite(J2, 0);
    uint16_t switching_distance = (static_cast<uint32_t>(analogRead(POT)) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    if(!over_threshold) //debounce
        switching_distance += 10;

    //this creates an "always on" region at the plus end of the poti
    over_threshold = switching_distance >= MAX_RANGE_MM-1 ? 0 : distance > switching_distance;
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

    digitalWrite(MUTE, over_threshold);
    if(blink >= batt_low_num_blinks)    //we are not blinking right now
        digitalWrite(LED, over_threshold);

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
            while(true)     // TODO: Is this code reachable? Probably not.
            {
                digitalWrite(LED, 1);
                delay(10);
                digitalWrite(LED, 0);
                delay(200);
            }
        }
    }

    if(needBatteryCheck && !isBatteryOk())
    {
        blink = 0;                      //starts blinking
    }
}
