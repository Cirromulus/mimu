#pragma once
#include <inttypes.h>
#include <Wire.h>

class AD5258 {
public:
    typedef uint8_t Address;
    typedef uint8_t Value;
    typedef int8_t SignedValue; // for convenience in counting

    typedef uint8_t Status;
    typedef uint32_t Resistance_Ohms;
    enum Resistance : Resistance_Ohms {
        option1k = 1000,
        option10k = 10000,
        option50k = 50000,
        option100k = 100000
    };

    // Measured in 256ths, so divide by 256 to get "1s"
    typedef int16_t FixedPoint256ths;
    static constexpr FixedPoint256ths fractional_base = 256;

    static constexpr Value max_wiper_val = 0b00111111;
    /* FIXME: Arduino has no numeric_limits
    static_assert(std::numeric_limits<SignedValue>::max() >= max_wiper_val,
        "SignedValue counter can't handle max_wiper_val, increase its size"
    );
    */

private:
    static constexpr Address base_addr = 0b0011000;
    static constexpr Address ad1_addr = 0b10;
    static constexpr Address ad2_addr = 0b1000000;

    enum Instr : uint8_t {
        wiper = 0b00000000,
        eeprom = 0b00100000,
        write_prot = 0b01000000,
        nop = 0b10000000,
        restore_from_eeprom = 0b10100000,
        store_wiper = 0b11000000,
        read_tolerance_signinteger = 0b00111110,
        // called "decimal", but is probably two's complement
        read_tolerance_decimal = 0b00111110,
    };

    const Address m_address;
    TwoWire& m_bus;

public:
    // @input
    // ad1 and ad2 are the address pins on the chip
    static constexpr Address calculateAddress(bool ad1 = false, bool ad2 = false) {
        return base_addr + (ad1 ? ad1_addr : 0) + (ad2 ? ad2_addr : 0);
    }

    static Resistance_Ohms calculateActualResistance(
                                                     Resistance_Ohms nominal_resistance_ohms,
                                                     FixedPoint256ths deviation,
                                                     Value wiper_position
                                                    );

    AD5258(Address, TwoWire&);
    Status writeWiper(Value);
    // TODO: How to report status?
    Value readWiper();
    FixedPoint256ths readDeviation();

};

