#ifndef I2C_WRAPPER_HPP_
#define I2C_WRAPPER_HPP_
#include <Arduino.h>
#include <i2c_t3.h>
#include <array>

void i2cInit();

/// 8-bit register address versions
/**
 * \brief for i2c peripherals that follow the
            WRITE_START <device address> <starting reg address> STOP
            WRITE_START <data0> ... <dataN> STOP
          paradigm OR
            WRITE_START <device address> <starting reg address> STOP
            READ_START <data0> ... <dataN> STOP
          this fn writes the starting register_address to the specified device_address
 */
uint8_t setStartingRegisterAddress(const uint8_t device_address,
                                   const uint8_t register_address);

uint8_t i2cReadByte(const uint8_t device_address, const uint8_t mem_address,
                    uint8_t& value);

uint8_t i2cWriteByte(const uint8_t device_address, const uint8_t mem_address,
                     uint8_t value);

uint8_t i2cRead(const uint8_t device_address, const uint8_t mem_address,
             const uint8_t num_bytes, uint8_t * const arrayPtr);

uint8_t i2cWrite(const uint8_t device_address, const uint8_t mem_address,
                 const uint8_t num_bytes, uint8_t const * arrayPtr);

/// 16-bit register address versions

/**
 * \brief performs identically to setStartingRegisterAddress above except this fn
 *        writes a 2-byte address.
 * \note for use with devices that have a larger register map that spans
 *       an address space beyond the typical 8 bits.
 */
uint8_t setStartingRegisterAddress(const uint8_t device_address,
                                   const uint16_t mem_address);

uint8_t i2cReadByte(const uint8_t device_address, const uint16_t mem_address,
                    uint8_t& value);

uint8_t i2cWriteByte(const uint8_t device_address, const uint16_t mem_address,
                     uint8_t value);

uint8_t i2cRead(const uint8_t device_address, const uint16_t mem_address,
                const uint8_t num_bytes, uint8_t * const arrayPtr);

uint8_t i2cWrite(const uint8_t device_address, const uint16_t mem_address,
                 const uint8_t num_bytes, uint8_t const * arrayPtr);
#endif /// I2C_WRAPPER_HPP_
