#ifndef USB_PACKET_H
#define USB_PACKET_H
#include <cstddef>
#include <cstdint>
#include <cstring>

/**
 * \brief a container for managing data transferred across USB.
 *        This USB HID device transfers 64-byte packets, inside of which live
 *        the quaternion data of several BNO055 sensors.
 *        Which sensor's data is indicated by index field of the qPacket.
 */
class UsbPacket
{
public:
    struct quatData
    {
        float w;
        float x;
        float y;
        float z;
    };

    struct quatPacket
    {
        uint8_t index; // which BNO055 in the chain we're talking to.
        quatData qData;// that BNO's data.
    };


    UsbPacket();

    ~UsbPacket();

/**
 * \brief get the quaternion data living at the packet index.
 * \param packetIndex index in the packet
 * \param qPacket a reference by which to read in the qPacket in the usb packet
 */
    void getQuaternionPacket(size_t packetIndex, quatPacket& qPacket);

/**
 * \brief set the quaternion data at a particular index in the packet.
 * \param packetIndex index in the packet
 * \param qPacket the qPacket to stuff into the USB packet
 */
    void setQuaternionPacket(size_t packetIndex, quatPacket qPacket);


    static const size_t PACKET_SIZE_BYTES = 64;
    // Integer division is an implicit floor function.
    size_t QUATERNIONS_PER_PACKET = PACKET_SIZE_BYTES/sizeof(quatPacket);

    uint8_t packet_[PACKET_SIZE_BYTES];
};


#endif // USB_PACKET_H
