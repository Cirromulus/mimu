#pragma once
#include <pins.hpp>

static constexpr uint32_t CPU_FREQ = F_CPU;
static constexpr uint16_t MAX_RANGE_MM = 700;
static constexpr uint16_t DEBOUNCE_RANGE_MM = 10;
static constexpr uint16_t DEADZONE_LOW_MM = 40;         // How long is the average microphone? :D
static constexpr uint32_t IDLE_TIMEOUT_WARN_S = 30*60;  // thirty minutes before
static constexpr bool     IDLE_MUTE_STATE = true;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
// Default: 33ms. Min 20ms, Max ~200ms
static constexpr uint32_t MEASUREMENT_TIMING_BUDGET_US = 80000;
static constexpr uint8_t  MEASUREMENT_EXTRA_DELAY_MS = 20;   // to save battery
static constexpr uint16_t TOT_MEAS_CYCLE_MS =
        MEASUREMENT_TIMING_BUDGET_US / 1000 + MEASUREMENT_EXTRA_DELAY_MS;
static constexpr uint16_t SENSOR_COMM_TIMEOUT_MS =
        max(100, 1.1*TOT_MEAS_CYCLE_MS);
static constexpr uint8_t  FILTER_EQUAL_MEASUREMENTS_NEEDED = 1;