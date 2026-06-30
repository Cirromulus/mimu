#pragma once
#include "config.hpp"
#include <AD5258.hpp>
// avr-gcc does not seem to have that :(
// #include <limits>

// TODO: presets?
struct MuteProfile {
    using Time_ms = uint16_t;
    using Damping = uint8_t;
    static constexpr Damping max_damping = 0xff;

    Time_ms mute_ramp_on_time_ms;
    Time_ms mute_ramp_off_time_ms;
    Damping damping_when_microphone_off;
    Damping damping_when_microphone_on;
};

static constexpr MuteProfile default_mute_profile {
    .mute_ramp_on_time_ms = 10,
    .mute_ramp_off_time_ms = 200,
    .damping_when_microphone_off = MuteProfile::max_damping,
    .damping_when_microphone_on = 0
};

class Mutehandling
{
    struct DeviceSpecificMuteProfile {
        using Time_us = uint32_t;
        // because of no <limits> :(
        static constexpr size_t maxTimeUsValue {static_cast<size_t>(static_cast<Time_us>(-1))};

        Time_us mute_ramp_on_delay_per_step_us;
        Time_us mute_ramp_off_delay_per_step_us;
        AD5258::Value value_when_microphone_off;
        AD5258::Value value_when_microphone_on;
        bool extra_drive_opto;
    };

    static constexpr AD5258::Value dampingToAD5258WiperPos(const MuteProfile::Damping& damping) {
        // scale to max val
        // FIXME: Float is ugly. How to do completely in integer?
        return (damping) * ((1.0 * AD5258::max_wiper_val) / MuteProfile::max_damping);
    }

    static constexpr DeviceSpecificMuteProfile calculateValuesFromMuteProfile(const MuteProfile& profile){
        // Assumption: High value -> High resistance -> Low optocoupler -> low damping -> microphone "on"
        const AD5258::Value value_when_microphone_off = dampingToAD5258WiperPos(profile.damping_when_microphone_off);
        const AD5258::Value value_when_microphone_on = dampingToAD5258WiperPos(profile.damping_when_microphone_on);
        const AD5258::Value on_off_diff = abs(value_when_microphone_off - value_when_microphone_on);
        const bool extra_drive_opto = profile.damping_when_microphone_off == MuteProfile::max_damping;

        const DeviceSpecificMuteProfile::Time_us mute_ramp_on_delay_per_step_us =
                            (static_cast<DeviceSpecificMuteProfile::Time_us>(profile.mute_ramp_on_time_ms) * 1000) / on_off_diff;
        const DeviceSpecificMuteProfile::Time_us mute_ramp_off_delay_per_step_us =
                            (static_cast<DeviceSpecificMuteProfile::Time_us>(profile.mute_ramp_off_time_ms) * 1000) / on_off_diff;

        return DeviceSpecificMuteProfile {
            .mute_ramp_on_delay_per_step_us = mute_ramp_on_delay_per_step_us,
            .mute_ramp_off_delay_per_step_us = mute_ramp_off_delay_per_step_us,
            .value_when_microphone_off = value_when_microphone_off,
            .value_when_microphone_on = value_when_microphone_on,
            .extra_drive_opto = extra_drive_opto
        };
    }

public:
    static constexpr bool
    isProfileValid(const MuteProfile& profile)
    {
        constexpr auto maxValue = DeviceSpecificMuteProfile::maxTimeUsValue; // std::numeric_limits<DeviceSpecificMuteProfile::Time_us>::max();
        if (profile.mute_ramp_on_time_ms * 1000 > maxValue)
        {
            // ramp_on_time overflow
            return false;
        }

        const DeviceSpecificMuteProfile generated = calculateValuesFromMuteProfile(profile);

        if(generated.value_when_microphone_on > AD5258::max_wiper_val)
        {
            // value_when_microphone_on may not be bigger than max wiper val
            return false;
        }
                
        if(generated.value_when_microphone_off > AD5258::max_wiper_val)
        {
            // value_when_microphone_off may not be bigger than max wiper val
            return false;
        }

        if (generated.value_when_microphone_on > generated.value_when_microphone_off)
        { 
            // "The loop expects the value of _off to be bigger than _on"
            return false;
        }

        return true;
    }

    constexpr Mutehandling() :
        calculated_mute_profile{calculateValuesFromMuteProfile(default_mute_profile)}
    {}

    constexpr bool loadMuteProfile(const MuteProfile& profile)
    {
        // TODO: checks etc.
        calculated_mute_profile = calculateValuesFromMuteProfile(profile);
        return true;
    }

    void enableExtraOptoDriver(const bool on);

    // @return isOk
    bool initDigipotUnmuted();
    void setMute(const bool mute);

private:
    DeviceSpecificMuteProfile calculated_mute_profile;
};

namespace test
{
    static_assert(Mutehandling::isProfileValid(default_mute_profile));
}