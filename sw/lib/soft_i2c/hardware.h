#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>

#define SCL_LOW      { PORTB &= ~(1<<PB3); DDRB |=  (1<<PB3); }
#define SCL_HIGH     { PORTB |=  (1<<PB3); DDRB &= ~(1<<PB3); }
#define SCL          ( PINB &= (1<<PB3) )

#define SDA_LOW      { PORTB &= ~(1<<PB4); DDRB |=  (1<<PB4); }
#define SDA_HIGH     { PORTB |=  (1<<PB4); DDRB &= ~(1<<PB4); }
#define SDA          ( PINB &= (1<<PB4) )

#define I2C_DELAY    _delay_us(4);

#endif // HARDWARE_H