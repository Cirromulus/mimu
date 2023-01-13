#include "mutehandling.hpp"
#include "userInterface.hpp"

static AD5258 digipot{AD5258::calculateAddress(), Wire};

void enableExtraOptoDriver(const bool on){
    // Active low, as we are high side switching
    digitalWrite(MUTE_DRIVE, !on);
}

// @return isOk
bool initDigipotUnmuted(){
    pinMode(MUTE_DRIVE, OUTPUT);
    enableExtraOptoDriver(false);
    const AD5258::TwiReturnStatus ret = digipot.writeWiper(calculated_mute_profile.value_when_microphone_on);
    if(ret != AD5258::TwiReturnStatus::success) {
        ui::digipotCommunicationError(ret);
        return false;
    } else {
        return true;
    }
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
                const auto ret = digipot.writeWiper(val);
                if(ret != AD5258::TwiReturnStatus::success) {
                    ui::digipotCommunicationError(ret);
                    return;
                }
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
                const auto ret = digipot.writeWiper(val);
                if(ret != AD5258::TwiReturnStatus::success) {
                    ui::digipotCommunicationError(ret);
                    return;
                }
                delayMicroseconds(calculated_mute_profile.mute_ramp_off_delay_per_step_us);
        }
    }
}