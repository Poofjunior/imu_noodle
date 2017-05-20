/*
 * \project usb_node_device.ino
 * \author Joshua Vasquez
 */

#include <bno055.h>
#include <i2c_wrapper.h>
#include <usb_packet.h>

const uint8_t NUM_BNOS = 5;
BNO055 bno_array[NUM_BNOS];
uint8_t addresses[NUM_BNOS] = {0x2F, 0x2C, 0x2E, 0x2D, BNO055::ALTERNATE_ADDRESS};

USBPacket usbPacket;

size_t sensorIndex = 0;

void setup(){
    i2cInit();
    delay(1000);
    for (uint8_t index = 0; index < NUM_BNOS; ++index)
    {
        bno_array[index].init(BNO055::NDOF, (BNO055::address_t)addresses[index]);
    }
}

/// Continuously read all the BNO055s in order and output their
/// data over usb.
void loop(void)
{
    int16_t w, x, y, z;
    USBPacket::quatPacket qPacket;
    /// Stuff as many quaternion packets into the usb packet per transfer.
    for (uint8_t packetIndex = 0;
         packetIndex < USBPacket::QUATERNIONS_PER_PACKET; ++packetIndex)
    {
        bno_array[sensorIndex].readRawQuaternion(w, x, y, z);
        qPacket.index = sensorIndex;
        qPacket.qData.w = w/float(BNO055::QUAT_BITS_TO_FLOAT);
        qPacket.qData.x = x/float(BNO055::QUAT_BITS_TO_FLOAT);
        qPacket.qData.y = y/float(BNO055::QUAT_BITS_TO_FLOAT);
        qPacket.qData.z = z/float(BNO055::QUAT_BITS_TO_FLOAT);

        usbPacket.setQuaternionPacket(packetIndex, qPacket);
        ++sensorIndex;
        if (sensorIndex == NUM_BNOS)
        {
            sensorIndex = 0;
        }
    }
    RawHID.send(usbPacket.packet_, 0);
    delay(6);
}
