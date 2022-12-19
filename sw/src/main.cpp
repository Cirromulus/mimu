#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <AD5258.hpp>
#include <avr/sleep.h>
#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"

VL53L0X sensor;
static volatile bool should_mute = false;
static uint32_t last_unmute;
static uint8_t  consecutive_equal_measurements = 0;

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
            ui::waiting();
        }
    }
    else
    {
        ui::switchOn();
    }

    if(has_serial && Serial) Serial.println("initing Sensor...");

    digitalWrite(J0, 1);
    sensor.setTimeout(SENSOR_COMM_TIMEOUT_MS);
    while (!sensor.init())
    {
        ui::waitingForSensor();
        if(has_serial && Serial) Serial.println("...");
    };

    if(has_serial && Serial) Serial.println("done");
    digitalWrite(J0, 0);
    digitalWrite(J1, 1);
    //minimum MCPS to report valid reading (default is 0.25 MCPS)
    sensor.setSignalRateLimit(1);     // increase to reduce stray measurements
    // (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 12);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 8);
    while(!sensor.setMeasurementTimingBudget(MEASUREMENT_TIMING_BUDGET_US))
    {
        ui::settingTimingBudget();
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

    ui::ready();
}

void loop() {

    if(has_serial && Serial) Serial.println("Measuring...");

    digitalWrite(J2, 1);
    uint16_t measured_distance = sensor.readRangeContinuousMillimeters();
    digitalWrite(J2, 0);
    uint16_t switching_distance = (static_cast<uint32_t>(analogRead(POT)) * MAX_RANGE_MM)/MAX_ANALOG_READ;
    if(!should_mute) //debounce
        switching_distance += DEBOUNCE_RANGE_MM;

    bool previous_measurement_was_muted = should_mute;

    if(switching_distance >= MAX_RANGE_MM-1) {
        // this creates an "always on / unmute" region
        // at the plus end of the poti
        should_mute = false;
    } else if (measured_distance  > DEADZONE_LOW_MM) {
        // if lower than deadzone, no update happens
        should_mute =  measured_distance > switching_distance;
    }

    if(previous_measurement_was_muted != should_mute) {
        consecutive_equal_measurements = 1;
    } else {
        if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED)
            consecutive_equal_measurements++;
    }
    if(!should_mute)
    {   // save last time we measured something near
        last_unmute = millis();
    }

    if(has_serial && Serial)
    {
        Serial.print(measured_distance);
        Serial.print(" > ");
        Serial.print((static_cast<uint32_t>(analogRead(POT)) * MAX_RANGE_MM)/MAX_ANALOG_READ);
    }
    if (sensor.timeoutOccurred())
    {
        // Communication with Sensor did not succeed
        if(has_serial && Serial) Serial.println("Timeout.");
        ui::sensorCommunicationError();
        return;
    }

    if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED) {
        // not yet enough equal measurements, stick to the "old" value
        //digitalWrite(MUTE, !should_mute); // not needed, GPIO has memory!
    } else {
        digitalWrite(MUTE, should_mute);
        ui::muted(should_mute);
    }
}
