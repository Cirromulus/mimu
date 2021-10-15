#pragma once

#include <Wire.h>

class Max5395 {

  uint8_t _addr;

public:

static constexpr uint8_t ADDR = 0b0101000;
static constexpr uint8_t ADDR_GND = ADDR;
static constexpr uint8_t ADDR_NC  = ADDR | 0b01;
static constexpr uint8_t ADDR_VDD = ADDR | 0b11;

Max5395(uint8_t addr = ADDR_NC) : _addr(addr){};

/**
  The data byte writes to the wiper register and the
  potentiometer moves to the appropriate position. D[7:0]
  indicates the position of the wiper. D[7:0] = 0x00 moves
  the wiper to the position closest to L. D[7:0] = 0xFF moves
  the wiper closest to H.
  D[7:0] = 0x80 following power-on.
**/
bool setWiper(uint8_t value) {
  Wire.beginTransmission(_addr);
  Wire.write(0x00); //"value_command"
  Wire.write(value);
  return Wire.endTransmission();
}

/**
  Removes any existing shutdown condition. Connects all
  potentiometer terminals and returns the wiper to the value
  stored in the wiper register. The command does not affect
  the current status of the charge pump.
**/
bool clear() {
  Wire.beginTransmission(_addr);
  Wire.write(0b10000000);
  return Wire.endTransmission();
}

/**
  Opens the W terminal keeping the internal tap position
  the same as the wiper register. Writes cannot be made
  to the wiper registers while shutdown mode is engaged.
  Clearing shutdown mode will return the wiper to the
  position contained in the wiper register and close W
  terminal. A RST will also deassert shutdown mode and
  return the wiper to midscale (0x80). This command does
  not affect the charge-pump status.
**/
bool openWiper() {
  Wire.beginTransmission(_addr);
  Wire.write(0b10000100); //1 0 0 0 0 1 X X
  return Wire.endTransmission();
}

/**
  QP_OFF Command
  Disables the onboard charge pump and places device in
  low power mode. Low supply voltage is limited to 2.6V.
  QP_ON Command
  Enables the onboard charge pump to allow low-supply
  voltage operation. This is the power-on default condition.
  Low supply voltage is 1.7V.
**/
bool enableChargepump(bool on = true) {
  Wire.beginTransmission(_addr);
  Wire.write(0b10100000 | on ? 1 : 0);
  return Wire.endTransmission();
}

};
