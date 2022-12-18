#pragma once
#include <inttypes.h>

namespace ad5258 {

static constexpr uint8_t base_addr = 0b0011000;
// ad1 and ad2 are the address pins 
static constexpr uint8_t getAddr(bool ad1 = false, bool ad2 = false) {
    return base_addr + (ad1 ? 0b10 : 0) + (ad2 ? 0b1000000 : 0);
}

enum Instr : uint8_t {
    wiper = 0b00000000,
    eeprom = 0b00100000,
    write_prot = 0b01000000,
    nop = 0b10000000,
    restore_from_eeprom = 0b10100000,
    store_wiper = 0b11000000
};

static constexpr uint8_t max_wiper_val = 0b00111111;

};