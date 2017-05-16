#ifndef NODE_USB_H
#define NODE_USB_H
#include "qpose/src/quaternion.hpp"
#include <libusb-1.0/libusb.h>
#include <iostream>
#include <cstring>

class NodeUsbDriver
{
 public:

    NodeUsbDriver();

    ~NodeUsbDriver();

    void updateNodes();

    libusb_device_handle* devHandle_;
    libusb_context* ctx_;

    static const size_t NUM_NODES = 4;  // total number of nodes
    static const size_t NUM_BYTES = 64; // teensy bulk transfer size.

    /// The angles of each imu node.
    Quaternion<float> orientations_[NUM_NODES];

    struct quaternionData
    {
        float w;
        float x;
        float y;
        float z;
    };

private:
    static const uint16_t TEENSY_VID = 0x16C0;
    static const uint16_t TEENSY_PID = 0x0486;
    uint8_t receivedBytes_[NUM_BYTES];
};
#endif //NODE_USB_H

