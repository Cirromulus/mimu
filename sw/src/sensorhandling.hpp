#pragma once
#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"

#include <Arduino.h>
#include <VL53L0X.h>

VL53L0X sensor;
static constexpr uint16_t VL53L0X_ERROR_RANGE = 65535;  // VL53L0X.cpp:821

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
    if(!sensor.setSignalRateLimit(1)) {     // increased to reduce stray measurements
        ui::errorSettingSensorSetting();
    }

    // (defaults are 14 and 10 PCLKs)
    // Decreased for faster measurement
    if(!sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 12)){
        ui::errorSettingSensorSetting();
    }
    if(!sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 8)){
        ui::errorSettingSensorSetting();
    }
    while(!sensor.setMeasurementTimingBudget(MEASUREMENT_TIMING_BUDGET_US))
    {
        ui::errorSettingSensorSetting();
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
