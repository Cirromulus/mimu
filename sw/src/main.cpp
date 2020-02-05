#include <Arduino.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup() {

    sensor.setTimeout(500);
    if (!sensor.init())
    {
        while (1) {}
    }
    // lower the return signal rate limit (default is 0.25 MCPS)
    sensor.setSignalRateLimit(0.1);
    // increase laser pulse periods (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

    // increase timing budget to 200 ms
    sensor.setMeasurementTimingBudget(200000);
}

void loop() {
    // put your main code here, to run repeatedly:
    uint16_t dist = sensor.readRangeSingleMillimeters());
    if (sensor.timeoutOccurred()) {

    }
}
