#pragma once
#include <pins.hpp>

static constexpr uint32_t CPU_FREQ = F_CPU;
static constexpr uint16_t MAX_RANGE_MM = 700;
static constexpr uint16_t DEBOUNCE_RANGE_MM = 10;
static constexpr uint16_t DEADZONE_LOW_MM = 40;         // How long is the average microphone? :D
static constexpr uint32_t IDLE_TIMEOUT_S = 2*60*60;     // two hours
static constexpr uint32_t IDLE_TIMEOUT_WARN_S = 30*60;  // thirty minutes before
static constexpr bool     IDLE_MUTE_STATE = false;
static constexpr uint16_t MAX_ANALOG_READ = 0x3FF;	//10 bit
static constexpr float    BATT_BLINK_CYCLE_DURATION_S = 0.25;
static constexpr uint16_t BATT_MEASURE_EVERY_S = 20;
static constexpr uint8_t  BATT_MEASURE_CYCLES =
        BATT_MEASURE_EVERY_S/BATT_BLINK_CYCLE_DURATION_S;
// Default: 33ms. Min 20ms, Max ~200ms
static constexpr uint32_t MEASUREMENT_TIMING_BUDGET_US = 80000;
static constexpr uint8_t  MEASUREMENT_EXTRA_DELAY_MS = 20;   // to save battery
static constexpr uint16_t TOT_MEAS_CYCLE_MS =
        MEASUREMENT_TIMING_BUDGET_US / 1000 + MEASUREMENT_EXTRA_DELAY_MS;
static constexpr uint16_t SENSOR_COMM_TIMEOUT_MS =
        max(100, 1.1*TOT_MEAS_CYCLE_MS);
static constexpr uint8_t  FILTER_EQUAL_MEASUREMENTS_NEEDED = 1;

#ifdef BATTERY_POWERED  //from pio env compiler insertion
    static constexpr uint8_t  NUM_BATTERIES = 3;
#else
    static constexpr uint8_t  NUM_BATTERIES = 0;
#endif
static constexpr uint16_t MAX_VOLTAGE_ALKALINE_mV = 1500;
static constexpr uint16_t WRN_VOLTAGE_ALKALINE_mV = 1100;
static constexpr uint16_t MIN_VOLTAGE_ALKALINE_mV = 1000;


static constexpr uint8_t  batt_low_num_blinks = 8*2;
static_assert(batt_low_num_blinks % 2 == 0,
    "needs to be dividable by 2, "
    "because it includes the \"off \" switches as well");
