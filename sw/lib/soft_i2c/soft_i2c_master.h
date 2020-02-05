#ifndef SOFT_I2C_MASTER_H
#define  SOFT_I2C_MASTER_H

#include <stdint.h>
#include <stdbool.h>

// Implementierung eines I2C Master mittels Bit-Banging für AVR.
// Autor: Stefan Frings <stefan@stefanfrings.de>
// Datum: 04.12.2018

// Pull-Up Widerstände nicht vergessen!

// Sendet beliebig viele Bytes an den adressierten Slave und empfängt
// anschließend beliebig viele Bytes von dem Slave.

// slave_address ist die Adresse des Slave in 7bit Schreibweise (0-127).
// send_data zeigt auf die zu sendenden Daten, z.B. ein Array von Bytes.
// send_bytes gibt an, wieviele Bytes gesendet werden sollen.
// rcv_data zeigt auf einen Puffer, wo die empfangenen Daten abgelegt werden
// sollen, z.B. ein Array von Bytes.
// rcv_Bytes gibt an, wieviele Bytes empfangen werden sollen.

// Der Rückgabewert zeigt an, wie viele Bytes tatsächlich empfangen wurden.

// Wenn man nur senden will, gibt man rcv_data=0 und rcv_bytes=0 an.
// Wenn man nur empfangen will, gibt man send_data=0 und send_bytes=0 an.
// Es ist erlaubt, bei send_bytes und rcv_bytes Zeiger auf den selben Puffer zu übergeben.

uint8_t i2c_communicate(uint8_t slave_address, uint8_t* send_data, uint8_t send_bytes, uint8_t* rcv_data, uint8_t rcv_bytes);


// Alternativ dazu kannman die folgenden Unterfunktionen verwenden:

// Sende START Signal
void i2c_start(void);
// if read == true, a read is initialized
bool i2c_start_addr(uint8_t addr, bool read);

// Sende STOP Signal
void i2c_stop(void);

// Sende ein Byte und liefere das ACK zurück.
bool i2c_send(uint8_t byte);

// Empfange ein byte und sende ACK (oder NAK)
uint8_t i2c_receive(bool ack);

#endif  /* SOFT_I2C_MASTER_H */
