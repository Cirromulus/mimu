#include <Arduino.h>
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

static constexpr uint16_t ramptime_ms = 20;
static constexpr uint16_t delay_microseconds_for_ramptime = (1000*ramptime_ms)/max_wiper_val;

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

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Wire.begin();
    //Wire.setClock(400000);  // MORE GAIN

    Serial.begin(115200);
    while (!Serial) {
        digitalWrite(LED_BUILTIN, 1);
        delay(250);
        digitalWrite(LED_BUILTIN, 0);
        delay(25);
    }

    Serial.print("AD5258 I2C Addr: ");
    Serial.println(ad5258_addr);
}

void loop() {
    static uint8_t val = 0;
    static bool fast = false;
    static bool up = true;
    writeWiper(val);

    if(fast) {
        delayMicroseconds(delay_microseconds_for_ramptime);
    } else {
        //Serial.print("Wrote val ");
        //Serial.println(val);
        delay(10);
    }

    if(up)
        val++;
    else
        val--;
    digitalWrite(LED_BUILTIN, val % 2);
    
    if(val > max_wiper_val) {
        delay(1000);
        up = !up;
        if(up) {
            fast = !fast;
        }
        
        if(up)
            val = 0;
        else
            val = max_wiper_val;
        
        Serial.print("Now ");
        Serial.print(up ? "Up" : "Down");
        Serial.println(fast ? " fast" : "");
    }
}
