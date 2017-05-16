/*
 * \project usb_node_device.ino
 * \author Joshua Vasquez
 */

#include "pinouts.h"
#include <bno055.h>
#include <i2c_wrapper.h>

const uint8_t NUM_BNOS = 4;
BNO055 bno_array[NUM_BNOS];
uint8_t addresses[NUM_BNOS] = {0x2F, 0x2C, 0x2E, /*0x2D*/ BNO055::ALTERNATE_ADDRESS};

uint8_t outgoingPacket_[64];

void setup(){
    i2cInit();
    delay(1000);
    for (uint8_t index = 0; index < NUM_BNOS; ++index)
    {
        bno_array[index].init(BNO055::NDOF, (BNO055::address_t)addresses[index]);
    }
}

void loop(void)
{
    for (uint8_t byteIndex = 0; byteIndex < 64; ++byteIndex)
    {
        outgoingPacket_[byteIndex] = byteIndex;
    }
    int16_t w, x, y, z;
    float scaledW, scaledX, scaledY, scaledZ;
    for (uint8_t bnoIndex = 0; bnoIndex < NUM_BNOS; ++bnoIndex)
    {
        bno_array[bnoIndex].readRawQuaternion(w, x, y, z);
        scaledW = w/float(BNO055::QUAT_BITS_TO_FLOAT);
        memcpy((void*) &outgoingPacket_[bnoIndex * 16],
               (void*) &scaledW, 4);
        scaledX = x/float(BNO055::QUAT_BITS_TO_FLOAT);
        memcpy((void*) &outgoingPacket_[bnoIndex * 16 + 4],
               (void*) &scaledX, 4);
        scaledY = y/float(BNO055::QUAT_BITS_TO_FLOAT);
        memcpy((void*) &outgoingPacket_[bnoIndex * 16 + 8],
               (void*) &scaledY, 4);
        scaledZ = z/float(BNO055::QUAT_BITS_TO_FLOAT);
        memcpy((void*) &outgoingPacket_[bnoIndex * 16 + 12],
               (void*) &scaledZ, 4);
    }
    RawHID.send(outgoingPacket_, 0);
    delay(33);
}
