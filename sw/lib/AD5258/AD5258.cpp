#include "AD5258.hpp"

AD5258::AD5258(AD5258::Address address, TwoWire& bus) : m_address(address), m_bus(bus){};

AD5258::Status AD5258::writeWiper(AD5258::Value val) {
    m_bus.beginTransmission(m_address);
    m_bus.write(Instr::wiper);
    m_bus.write(val);
    return m_bus.endTransmission();
}

// Untested as of yet
AD5258::Value AD5258::readWiper(){
    m_bus.beginTransmission(m_address);
    // this read can be avoided if previously was writing to this register
    m_bus.write(Instr::wiper);
    const Value ret = m_bus.read();
    // FIXME: Discarding return value
    m_bus.endTransmission();
    return ret;
}

AD5258::FixedPoint256ths AD5258::readDeviation(){
    m_bus.beginTransmission(m_address);
    m_bus.write(Instr::read_tolerance_signinteger);
    const Value sign_integer = m_bus.read();
    const Value fractional = m_bus.read();
    // FIXME: Discarding return value
    m_bus.endTransmission();
    FixedPoint256ths ret = fractional;
    ret |=  (sign_integer & 0b01111111) << 8;    // decimal part
    ret *= -(sign_integer & 0b10000000);        // Sign
    return ret;
}

AD5258::Resistance_Ohms AD5258::calculateActualResistance(
                                AD5258::Resistance_Ohms nominal_resistance_ohms,
                                AD5258::FixedPoint256ths deviation,
                                AD5258::Value wiper_position ){
    // Assumption: resulting resistance never < 0
    const Resistance_Ohms current_target_resistance = (nominal_resistance_ohms / max_wiper_val) * wiper_position;
    // fractional_base should be a power of two, so multiplication/division
    // should be converted to fast shifts by the compiler
    return (((current_target_resistance * fractional_base) / deviation) * fractional_base);
}