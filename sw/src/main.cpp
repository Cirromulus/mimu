#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

#include <pins.hpp>

static constexpr uint16_t MAX_RANGE_MM = 300;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
static constexpr uint8_t  NUM_BATTERIES = 3;
static constexpr uint16_t MAX_VOLTAGE_ALKALINE_mV = 1500;
static constexpr uint16_t MIN_VOLTAGE_ALKALINE_mV = 1000;

VL53L0X sensor;

void setup() {
    pinMode(MUTE, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(POT, INPUT);
    Wire.begin();

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
        digitalWrite(LED, 1);
        delay(500);
        digitalWrite(LED, 0);
    }


    if(has_serial) Serial.println("initing Sensor...");

    sensor.setTimeout(500);
    while (!sensor.init())
    {
        /*
        digitalWrite(LED, 1);
        delay(50);
        digitalWrite(LED, 0);
        delay(50);
        */
        if(has_serial) Serial.println("...");
    };

    if(has_serial) Serial.println("done");

    // lower the return signal rate limit (default is 0.25 MCPS)
    if(!sensor.setSignalRateLimit(0.1))
    {
        if(has_serial) Serial.println("could not set signal rate limit");
    }
    // increase laser pulse periods (defaults are 14 and 10 PCLKs)
    if(!sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18))
    {
        if(has_serial) Serial.println("could not set VcselPeriodPreRange");
    }

    if(!sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14))
    {
        if(has_serial) Serial.println("could not set VcselPeriodFinalRange");
    }
    // increase timing budget to 200 ms
    if(!sensor.setMeasurementTimingBudget(200000))
    {
        if(has_serial) Serial.println("could not set MeasurementTimingBudget");
    }
    //sensor.startContinuous(0);

    if(has_serial)
    {
        Serial.println("Configured Sensor.");
        Serial.print("SignalRateLimit: ");
        Serial.println(sensor.getSignalRateLimit());
        Serial.print("MeasurementTimingBudget: ");
        Serial.println(sensor.getMeasurementTimingBudget());
    }

    /*
    cli();	//disable interrupts
    //set timer1 interrupt at 1Hz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set compare match register for 1/30hz increments
	OCR1A = (16*10^6) / (1024/30) - 1; 	//(must be <65536)
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS12 and CS10 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
	sei();	//allow interrupts
    */
}

static volatile bool needBatteryCheck = false;

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz
	needBatteryCheck = true;
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
	return readVcc_mV() > MIN_VOLTAGE_ALKALINE_mV*NUM_BATTERIES;
}

void loop() {

    if(has_serial) Serial.println("Measuring...");

    //uint8_t over = sensor.readRangeContinuousMillimeters() > 40; //(analogRead(POT) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    uint16_t distance = sensor.readRangeSingleMillimeters();
    uint8_t over = distance > 50; //(analogRead(POT) * MAX_RANGE_MM)/MAX_ANALOG_READ;

    if(has_serial) Serial.println(distance);
    if (sensor.timeoutOccurred())
    {
        if(has_serial) Serial.println("Timeout.");

        for(unsigned i = 0; i < 2; i++)
        {
            digitalWrite(LED, 1);
            delay(100);
            digitalWrite(LED, 0);
            delay(100);
        }
        return;
    }

    //digitalWrite(MUTE, over);
    digitalWrite(LED, over);


    if(false && needBatteryCheck && !isBatteryOk())
    {
    	for(unsigned i = 0; i < 5; i++)
    	{
			digitalWrite(LED, 0);
			delay(500);
			digitalWrite(LED, 1);
    	}
    	needBatteryCheck = false;
    }
}
