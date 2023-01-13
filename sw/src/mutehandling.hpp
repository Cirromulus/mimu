#pragma once
#include "config.hpp"
#include <AD5258.hpp>

// TODO: namespace/class?
struct DeviceSpecificMuteProfile {
    typedef uint32_t Time_us;

    Time_us mute_ramp_on_delay_per_step_us;
    Time_us mute_ramp_off_delay_per_step_us;
    AD5258::Value value_when_microphone_off;
    AD5258::Value value_when_microphone_on;
    bool extra_drive_opto;
};

static constexpr AD5258::Value dampeningToAD5258WiperPos(const MuteProfile::Dampening dampening) {
    // scale to max val
    // FIXME: Float is ugly. How to do completely in integer?
    return (dampening) * ((1.0 * AD5258::max_wiper_val) / MuteProfile::max_dampening);
}

static constexpr DeviceSpecificMuteProfile calculateValuesFromMuteProfile(const MuteProfile& profile){
    // Assumption: High value -> High resistance -> Low optocoupler -> low dampening -> microphone "on"
    AD5258::Value value_when_microphone_off = dampeningToAD5258WiperPos(profile.dampening_when_microphone_off);
    AD5258::Value value_when_microphone_on = dampeningToAD5258WiperPos(profile.dampening_when_microphone_on);
    AD5258::Value on_off_diff = abs(value_when_microphone_off - value_when_microphone_on);
    bool extra_drive_opto = profile.dampening_when_microphone_off == MuteProfile::max_dampening;

    DeviceSpecificMuteProfile::Time_us mute_ramp_on_delay_per_step_us =
                        (static_cast<DeviceSpecificMuteProfile::Time_us>(profile.mute_ramp_on_time_ms) * 1000) / on_off_diff;
    DeviceSpecificMuteProfile::Time_us mute_ramp_off_delay_per_step_us =
                        (static_cast<DeviceSpecificMuteProfile::Time_us>(profile.mute_ramp_off_time_ms) * 1000) / on_off_diff;

    // error: non-constant condition for static assertion
    // error: the value of 'value_when_microphone_on' is not usable in a constant expression
    /*
    static_assert(value_when_microphone_on < AD5258::max_wiper_val,
                  "value_when_microphone_on may not be bigger than max wiper val");
    static_assert(value_when_microphone_off < AD5258::max_wiper_val,
                  "value_when_microphone_off may not be bigger than max wiper val");
    */

    return DeviceSpecificMuteProfile {
        .mute_ramp_on_delay_per_step_us = mute_ramp_on_delay_per_step_us,
        .mute_ramp_off_delay_per_step_us = mute_ramp_off_delay_per_step_us,
        .value_when_microphone_off = value_when_microphone_off,
        .value_when_microphone_on = value_when_microphone_on,
        .extra_drive_opto = extra_drive_opto
    };
}

static constexpr DeviceSpecificMuteProfile calculated_mute_profile = calculateValuesFromMuteProfile(default_mute_profile);

void enableExtraOptoDriver(const bool on);

// @return isOk
bool initDigipotUnmuted();
void setMute(const bool mute);