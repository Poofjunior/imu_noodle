#include "i2c_wrapper.h"

#define TIMEOUT_MS 20

void i2cInit()
{
/*
/// Initialize I2C for Teensy 3 as master (with dummy slave address).
    uint8_t dummyAddress = 0x00;
    Wire.begin(I2C_MASTER, dummyAddress, I2C_PINS_18_19, I2C_PULLUP_EXT,
               I2C_RATE_400);
*/
    Wire.begin();
}

uint8_t setStartingRegisterAddress(const uint8_t device_address,
                           const uint8_t register_address)
{
    Wire.beginTransmission(device_address);
    Wire.write(register_address);
    return Wire.endTransmission();
}

uint8_t i2cReadByte(const uint8_t device_address, const uint8_t register_address,
                    uint8_t& value)
{
    const uint8_t num_bytes = 1;
    uint8_t temp_array[num_bytes];
    uint8_t status_byte = i2cRead(device_address, register_address,
                                 num_bytes, temp_array);
    value = temp_array[0];
    return status_byte;
}

uint8_t i2cWriteByte(const uint8_t device_address, const uint8_t register_address,
                     uint8_t value)
{
    uint8_t num_bytes = 1;
    uint8_t temp_array[num_bytes];
    temp_array[0] = value;
    return i2cWrite(device_address, register_address, num_bytes, temp_array);
}

uint8_t i2cRead(const uint8_t device_address, const uint8_t register_address,
                const uint8_t num_bytes, uint8_t * const arrayPtr)
{
    uint8_t status_byte = setStartingRegisterAddress(device_address, register_address);
    if (!status_byte)
    {
        Wire.requestFrom(device_address, num_bytes);
        for (uint8_t data_index = 0; data_index < num_bytes; ++data_index)
        {
            int t = millis();
            while((!Wire.available()) && (millis() < t+TIMEOUT_MS));
            arrayPtr[data_index] = Wire.read();
        }
    }
    return status_byte;
}

uint8_t i2cWrite(const uint8_t device_address, const uint8_t register_address,
                 const uint8_t num_bytes, uint8_t const * arrayPtr)
{
    Wire.beginTransmission(device_address);
    Wire.write(register_address);
    for (uint8_t data_index = 0; data_index < num_bytes; ++data_index)
    {
        Wire.write(arrayPtr[data_index]);
    }
    return Wire.endTransmission();
}

/*** 16-bit register addresses ***/
uint8_t setStartingRegisterAddress(const uint8_t device_address,
                        const uint16_t register_address)
{
    Wire.beginTransmission(device_address);
    Wire.write(uint8_t(0xFF & (register_address >> 8)));
    Wire.write(uint8_t(0xFF & register_address));
    return Wire.endTransmission();
}

uint8_t i2cReadByte(const uint8_t device_address, const uint16_t register_address,
                    uint8_t& value)
{
    const uint8_t num_bytes = 1;
    uint8_t temp_array[num_bytes];
    uint8_t status_byte = i2cRead(device_address, register_address,
                                  num_bytes, temp_array);
    value = temp_array[0];
    return status_byte;
}

uint8_t i2cWriteByte(const uint8_t device_address, const uint16_t register_address,
                uint8_t value)
{
    uint8_t num_bytes = 1;
    uint8_t temp_array[num_bytes];
    temp_array[0] = value;
    return i2cWrite(device_address, register_address, num_bytes, temp_array);
}

uint8_t i2cRead(const uint8_t device_address, const uint16_t register_address,
                const uint8_t num_bytes, uint8_t * const arrayPtr)
{
    uint8_t status_byte = setStartingRegisterAddress(device_address, register_address);
    if (!status_byte)
    {
        Wire.requestFrom(device_address, num_bytes);
        for (uint8_t data_index = 0; data_index < num_bytes; ++data_index)
        {
            int t = millis();
            while((!Wire.available()) && (millis() < t+TIMEOUT_MS));
            arrayPtr[data_index] = Wire.read();
        }
    }
    return status_byte;
}

uint8_t i2cWrite(const uint8_t device_address, const uint16_t register_address,
                 const uint8_t num_bytes, uint8_t const * arrayPtr)
{
    Wire.beginTransmission(device_address);
    Wire.write(uint8_t(0xFF & (register_address >> 8)));
    Wire.write(register_address);
    for (uint8_t data_index = 0; data_index < num_bytes; ++data_index)
    {
        Wire.write(arrayPtr[data_index]);
    }
    return Wire.endTransmission();
}

