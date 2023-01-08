#include <inttypes.h>
#include <Arduino.h>

static constexpr uint8_t MUTE_DRIVE = 17;   //PC0
static constexpr uint8_t BUTTON     = 16;   //PC7
static constexpr uint8_t LEDG       = 19;   //PC2
static constexpr uint8_t LEDR       = 20;   //PC3
static constexpr uint8_t J0   = 0;
static constexpr uint8_t J1   = 1;
static constexpr uint8_t J2   = 2;

static constexpr bool has_serial = false;
