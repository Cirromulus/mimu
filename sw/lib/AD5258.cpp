#include <Wire.h>

static constexpr bool ad5258_ad1 = false;
static constexpr bool ad5258_ad2 = false;
static constexpr uint8_t ad5258_addr = 
    0b0011000 + (ad5258_ad1 ? 0b10 : 0) + (ad5258_ad2 ? 0b1000000 : 0);
enum Instr : uint8_t {
    wiper = 0b00000000,
    eeprom = 0b00100000
};

static constexpr uint8_t max_wiper_val = 0b00111111;

void writeWiper(uint8_t val) {
    Wire.beginTransmission(ad5258_addr);
    Wire.write(Instr::wiper);
    Wire.write(val);
    uint8_t status = Wire.endTransmission();
    if(status != 0) {
        Serial.print("Oh noez, write was not successful: ");
        Serial.println(status);
    }
}
