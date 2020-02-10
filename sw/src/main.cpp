#include <Arduino.h>
#include <VL53L0X.h>


static constexpr uint8_t MUTE = 23;
static constexpr uint8_t POT  = 24;
static constexpr uint8_t LED  = 25;

static constexpr uint16_t MAX_RANGE_MM = 300;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
static constexpr uint8_t NUM_BATTERIES = 3;
static constexpr uint16_t MAX_VOLTAGE_ALKALINE_mV = 1500;
static constexpr uint16_t MIN_VOLTAGE_ALKALINE_mV = 1000;

VL53L0X sensor;

void setup() {
    sensor.setTimeout(500);
    while (!sensor.init()){};

    // lower the return signal rate limit (default is 0.25 MCPS)
    sensor.setSignalRateLimit(0.1);
    // increase laser pulse periods (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

    // increase timing budget to 200 ms
    sensor.setMeasurementTimingBudget(200000);

    pinMode(MUTE, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(POT, INPUT);
    sensor.startContinuous(0);

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
}

static volatile bool needBatteryCheck = false;

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
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
	uint8_t over = sensor.readRangeContinuousMillimeters() > (analogRead(POT) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    digitalWrite(MUTE, over);
    digitalWrite(LED, over);
    if(needBatteryCheck && !isBatteryOk())
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
