#include "mutehandling.hpp"

static AD5258 digipot{AD5258::calculateAddress(), Wire};

void enableExtraOptoDriver(const bool on){
    // Active low, as we are high side switching
    digitalWrite(MUTE_DRIVE, !on);
}

// @return isOk
bool initDigipotUnmuted(){
    pinMode(MUTE_DRIVE, OUTPUT);
    enableExtraOptoDriver(false);
    return digipot.writeWiper(0) == 0;
}

void setMute(const bool mute) {
    // Print calculated values of mute profile
    /*
    static_print<calculated_mute_profile.mute_ramp_on_delay_per_step_us>();
    static_print<calculated_mute_profile.mute_ramp_off_delay_per_step_us>();
    static_print<calculated_mute_profile.value_when_microphone_on>();
    static_print<calculated_mute_profile.value_when_microphone_off>();
    static_print<calculated_mute_profile.extra_drive_opto>();
    */

    static_assert(calculated_mute_profile.value_when_microphone_on > calculated_mute_profile.value_when_microphone_off,
                  "The loop expects the value of _on to be bigger than _off");

    // Assumption: High value -> High resistance -> Low optocoupler -> low dampening -> microphone "on"
    if(mute){
        for(AD5258::SignedValue val = calculated_mute_profile.value_when_microphone_on;
            val != calculated_mute_profile.value_when_microphone_off;
            val--) {
                digipot.writeWiper(val);
                delayMicroseconds(calculated_mute_profile.mute_ramp_off_delay_per_step_us);
        }
        if(calculated_mute_profile.extra_drive_opto) {
            enableExtraOptoDriver(true);
        }
    } else {
        enableExtraOptoDriver(false);
        for(AD5258::SignedValue val = calculated_mute_profile.value_when_microphone_off;
            val != calculated_mute_profile.value_when_microphone_on;
            val++) {
                digipot.writeWiper(val);
                delayMicroseconds(calculated_mute_profile.mute_ramp_off_delay_per_step_us);
        }
    }
}