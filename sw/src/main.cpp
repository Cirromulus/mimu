#include <config.hpp>
#include "userInterface.hpp"
#include "peripherals.hpp"
#include "mutehandling.hpp"
#include "sensorhandling.hpp"
#include "distanceStorage.hpp"

#include <Arduino.h>

static Mutehandling mute{};
static DistanceStorage switchingDistance;
static bool should_mute = false;
static bool isSettingDistance = false;
static uint8_t consecutive_equal_decisions = 0;
static uint8_t previousTimeOuts = 0;

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

    switchingDistance.loadFromEeprom();

    Wire.begin();
    Wire.setClock(100000);  // or 400000

    while(!mute.initDigipotUnmuted()) {
        ui::digipotCommunicationError();
    }

    initSensor();
    startMeasuring();

    ui::ready();
}

void loop() {
    bool previous_measurement_was_muted = should_mute;

    if constexpr (has_serial)
        if (Serial) Serial.println("Measuring...");

    const Distance_mm measured_distance_mm = sensor.readRangeContinuousMillimeters();
    if (sensor.timeoutOccurred()) {
        // Communication with Sensor did not succeed
        if(previousTimeOuts < CONSECUTIVE_TIMEOUTS_WARNING) {
            // do not blink error code yet
            previousTimeOuts++;
        } else {
            ui::sensorCommunicationError();
            ui::muted(should_mute); // ui function does not reset LED state
        }
        // Do not use the time-out measurement
        return;
    } else {
        // No timeout, so reset counter
        previousTimeOuts = 0;
    }

    // ---- set distance ----

    if (getButton()) {
        // unmute, but only once
        if(should_mute) {
            should_mute = false;
            mute.setMute(should_mute);
        }
        
        ui::settingDistance();
        isSettingDistance = true;
        return;
    } else {
        if (isSettingDistance)
        {
            // button pressing ended. Store to eeprom.
            switchingDistance.set(measured_distance_mm);
            isSettingDistance = false;
            // "restore" state to be overwitten by whatever is going on down there.
            ui::settingDistance(false);
        }
    }

    // ----

    // Decide if we should mute
    if(!previous_measurement_was_muted) {
        // was "on"
        if (measured_distance_mm > DEADZONE_LOW_MM) {
            //debounce
            should_mute = measured_distance_mm > (switchingDistance.get_mm() + DEBOUNCE_RANGE_MM);
        } else {
            // if lower than deadzone, no update happens
        }
    } else {
        // was "off"
        should_mute = measured_distance_mm > switchingDistance.get_mm();
    }

    // handle filtering counter
    if constexpr (FILTER_EQUAL_DECISIONS_NEEDED > 1) {
        if(previous_measurement_was_muted != should_mute) {
            consecutive_equal_decisions = 1;
        } else {
            if (consecutive_equal_decisions < FILTER_EQUAL_DECISIONS_NEEDED)
                consecutive_equal_decisions++;
        }
    }

    if constexpr (has_serial) {
        if (Serial)  {
            Serial.println("Measuring...");
            Serial.print(measured_distance_mm);
            Serial.print(" > ");
            Serial.print(switchingDistance.get_mm());
        }
    }

    // execute muting decision
    if (FILTER_EQUAL_DECISIONS_NEEDED > 1 && consecutive_equal_decisions < FILTER_EQUAL_DECISIONS_NEEDED) {
        // not yet enough equal measurements, stick to the "old" value
    } else {
        //waitForButtonPress(3);
        if(previous_measurement_was_muted != should_mute) {
            //waitForButtonPress(4);
            mute.setMute(should_mute);
        }
    }
}
