#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"
#include "mutehandling.hpp"
#include "sensorhandling.hpp"

#include <Arduino.h>

static volatile bool should_mute = false;
static uint8_t  consecutive_equal_decisions = 0;
// TODO: Read/Write from EEPROM
static uint16_t switching_distance_mm = default_mute_profile.trigger_distance_mm;

void setup() {
    ui::init();
    initButton();
    initDebugLines();

    if constexpr (has_serial)
    {
        Serial.begin(115200);
        while (!Serial) {
            ui::waitingForSerial();
        }
    }
    else
    {
        ui::switchOn();
    }

    Wire.begin();
    //Wire.setClock(400000);  // MORE GAIN

    while(!initDigipotUnmuted()) {
        ui::digipotCommunicationError();
    }

    initSensor();
    startMeasuring();
 
    while(true) {
        ui::ready();
        delay(500);
    }
}

void loop() {
    bool previous_measurement_was_muted = should_mute;

    if constexpr (has_serial)
        if (Serial) Serial.println("Measuring...");

    setDebugLine(2, true);
    Distance_mm measured_distance_mm = sensor.readRangeContinuousMillimeters();
    setDebugLine(2, false);
    if (sensor.timeoutOccurred())
    {
        // Communication with Sensor did not succeed
        ui::sensorCommunicationError();
        return;
    }

    // Button handling
    if(getButton()) {
        ui::settingDistance();
        switching_distance_mm = measured_distance_mm;
    } else {
        ui::settingDistance(false);
    }

    if(!previous_measurement_was_muted) {
        // was "on"
        if (measured_distance_mm > DEADZONE_LOW_MM) {
            //debounce
            should_mute = measured_distance_mm >  switching_distance_mm + DEBOUNCE_RANGE_MM;
        } else {
            // if lower than deadzone, no update happens
        }
    } else {
        // was "off"
        should_mute = measured_distance_mm < switching_distance_mm;
    }

    if(previous_measurement_was_muted != should_mute) {
        consecutive_equal_decisions = 1;
    } else {
        if (consecutive_equal_decisions < FILTER_EQUAL_DECISIONS_NEEDED)
            consecutive_equal_decisions++;
    }

    if constexpr (has_serial) {
        if (Serial) Serial.println("Measuring...");
        {
            Serial.print(measured_distance_mm);
            Serial.print(" > ");
            Serial.print(switching_distance_mm);
        }
    }

    if (consecutive_equal_decisions < FILTER_EQUAL_DECISIONS_NEEDED) {
        // not yet enough equal measurements, stick to the "old" value
    } else {
        if(previous_measurement_was_muted != should_mute) {
            setMute(should_mute);
            ui::muted(should_mute);
        }
    }
}
