#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

static constexpr uint8_t J0   = 0;
static constexpr uint8_t J1   = 1;
static constexpr uint8_t J2   = 2;
static constexpr uint8_t LED  = 19;    //PC2

VL53L0X sensor;

void setup() {
    pinMode(J0, OUTPUT);
    pinMode(J1, OUTPUT);
    pinMode(J2, OUTPUT);
    pinMode(LED, OUTPUT);

    Wire.begin();

    digitalWrite(J0, 1);
    sensor.setTimeout(1000);
    while (!sensor.init())
    {
        digitalWrite(LED, 1);
        delay(100);
        digitalWrite(LED, 0);
        delay(300);
    };
    digitalWrite(J0, 0);
    digitalWrite(J1, 1);

    if(!sensor.setMeasurementTimingBudget(20000))
    {
        while(true)
        {
            digitalWrite(LED, 1);
            delay(300);
            digitalWrite(LED, 0);
            delay(100);
        }
    }
    sensor.startContinuous(0);
    digitalWrite(J1, 0);
}

void loop() {
    digitalWrite(J2, 1);
    uint16_t distance = sensor.readRangeContinuousMillimeters();
    digitalWrite(J2, 0);
    if (sensor.timeoutOccurred())
    {
        return;
    }
    digitalWrite(LED, distance > 40);
}
