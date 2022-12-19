#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <avr/sleep.h>
#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"
#include "mutehandling.hpp"

VL53L0X sensor;
static volatile bool should_mute = false;
static uint8_t  consecutive_equal_measurements = 0;
static uint16_t switching_distance_mm = 20;

void setup() {
    pinMode(J0, OUTPUT);
    pinMode(J1, OUTPUT);
    pinMode(J2, OUTPUT);
    ui::init();
    initUnmuted();


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
    bool previous_measurement_was_muted = should_mute;

    if(has_serial && Serial) Serial.println("Measuring...");

    digitalWrite(J2, 1);
    uint16_t measured_distance = sensor.readRangeContinuousMillimeters();
    digitalWrite(J2, 0);
    if (sensor.timeoutOccurred())
    {
        // Communication with Sensor did not succeed
        if(has_serial && Serial) Serial.println("Timeout.");
        ui::sensorCommunicationError();
        return;
    }

    if(!previous_measurement_was_muted) {
        // was "on"
        if (measured_distance > DEADZONE_LOW_MM) {
            //debounce
            should_mute = measured_distance >  switching_distance_mm + DEBOUNCE_RANGE_MM;
        } else {
            // if lower than deadzone, no update happens
        }
    } else {
        // was "off"
        should_mute = measured_distance < switching_distance_mm;
    }

    if(previous_measurement_was_muted != should_mute) {
        consecutive_equal_measurements = 1;
    } else {
        if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED)
            consecutive_equal_measurements++;
    }

    if(has_serial && Serial)
    {
        Serial.print(measured_distance);
        Serial.print(" > ");
        Serial.print(switching_distance_mm);
    }

    if (consecutive_equal_measurements < FILTER_EQUAL_MEASUREMENTS_NEEDED) {
        // not yet enough equal measurements, stick to the "old" value
        //digitalWrite(MUTE, !should_mute); // not needed, GPIO has memory!
    } else {
        setMute(should_mute);
        ui::muted(should_mute);
    }
}
