#include <Arduino.h>
#include <VL53L0X.h>


static constexpr uint8_t MUTE = 23;
static constexpr uint8_t POT  = 24;
static constexpr uint8_t LED  = 25;

static constexpr uint16_t MAX_RANGE_MM = 300;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit

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
}

void loop() {
	uint8_t over = sensor.readRangeContinuousMillimeters() > (analogRead(POT) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    digitalWrite(MUTE, over);
    digitalWrite(LED, over);
}
