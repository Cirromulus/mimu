#pragma once
#include <pins.hpp>

typedef uint16_t Distance_mm;

static constexpr uint32_t CPU_FREQ = F_CPU;
static constexpr Distance_mm MAX_RANGE_MM = 700;
static constexpr Distance_mm DEBOUNCE_RANGE_MM = 10;
static constexpr Distance_mm DEADZONE_LOW_MM = 40;         // How long is the average microphone? :D
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
// Default: 33ms. Min 20ms, Max ~200ms
static constexpr uint32_t MEASUREMENT_TIMING_BUDGET_US = 80000;
static constexpr uint8_t  MEASUREMENT_EXTRA_DELAY_MS = 20;   // to save power
static constexpr uint16_t TOT_MEAS_CYCLE_MS =
        MEASUREMENT_TIMING_BUDGET_US / 1000 + MEASUREMENT_EXTRA_DELAY_MS;
static constexpr uint16_t SENSOR_COMM_TIMEOUT_MS =
        max(100, 1.1*TOT_MEAS_CYCLE_MS);
static constexpr uint8_t  FILTER_EQUAL_DECISIONS_NEEDED = 1;

// TODO: Make this presets
struct MuteProfile {
    typedef uint16_t Time_ms;
    typedef uint8_t Dampening;
    static constexpr Dampening max_dampening = 0xff;

    Distance_mm trigger_distance_mm;
    Time_ms mute_ramp_on_time_ms;
    Time_ms mute_ramp_off_time_ms;
    Dampening dampening_when_microphone_off;
    Dampening dampening_when_microphone_on;
;
};

// TODO: Read/Write from EEPROM
static constexpr MuteProfile default_mute_profile = MuteProfile {
    .trigger_distance_mm = 250,
    .mute_ramp_on_time_ms = 10,
    .mute_ramp_off_time_ms = 205,
    .dampening_when_microphone_off = MuteProfile::max_dampening-1,
    .dampening_when_microphone_on = 0
};

template <auto val>
constexpr void static_print() {
    #if !defined(__GNUC__) || defined(__clang__)
        int static_print_is_implemented_only_for_gcc = 0;
    #else
        int unused = 0;
    #endif
};