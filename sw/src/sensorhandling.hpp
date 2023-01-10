#pragma once
#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"

#include <Arduino.h>
#include <VL53L0X.h>

VL53L0X sensor;

inline void initSensor() {
    sensor.setTimeout(SENSOR_COMM_TIMEOUT_MS);

    while (!sensor.init())
    {
        ui::waitingForSensor();
        if constexpr (has_serial)
            if (Serial) Serial.println("Initing Sensor...");
    };

    if constexpr (has_serial)
        if (Serial) Serial.println("done");
    
    //minimum MCPS to report valid reading (default is 0.25 MCPS)
    sensor.setSignalRateLimit(1);     // increase to reduce stray measurements

    // (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 12);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 8);

    while(!sensor.setMeasurementTimingBudget(MEASUREMENT_TIMING_BUDGET_US))
    {
        ui::settingTimingBudget();
    }
}

inline void startMeasuring(){
    if constexpr (has_serial)
        if (Serial) Serial.println("Start Measuring...");

    sensor.startContinuous(TOT_MEAS_CYCLE_MS);
    setDebugLine(1, false);

    if constexpr (has_serial) {
        if( Serial) {
            Serial.println("Configured Sensor.");
            Serial.print("SignalRateLimit: ");
            Serial.println(sensor.getSignalRateLimit());
            Serial.print("MeasurementTimingBudget: ");
            Serial.println(sensor.getMeasurementTimingBudget());
        }
    }
}
