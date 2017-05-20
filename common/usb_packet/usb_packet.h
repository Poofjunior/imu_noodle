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
class USBPacket
{
public:
/*
 * \brief container for storing raw quaternion data.
 */
#pragma pack(push, 1)
    struct quatData
    {
        float w;
        float x;
        float y;
        float z;
    };
#pragma pack(pop)

/**
 * \details container for storing both quaternion data and the index identifying
 *          the corresponding sensor id.
 * \details this container is necessary for the usbPacket_ such that the
 *          usbPacket_ may be stuffed with data from arbitrary sensors.
 */
#pragma pack(push, 1)
    struct quatPacket
    {
        uint8_t index; // which BNO055 in the chain we're talking to.
        quatData qData;// that BNO's data.
    };
#pragma pack(pop)


    USBPacket();

    ~USBPacket();

/**
 * \brief get the quaternion data living at the packet index.
 * \param packetIndex which quatPacket slot in the packet_ that the
 *                    quatPacket will be inserted
 * \param qPacket a reference by which to read in the qPacket in the usb packet
 */
    void getQuaternionPacket(size_t packetIndex, quatPacket& qPacket);

/**
 * \brief set the quaternion data at a particular index in the packet.
 * \param packetIndex which quatPacket slot in the packet_ that the
 *                    quatPacket will be inserted
 * \param qPacket the qPacket to stuff into the USB packet
 */
    void setQuaternionPacket(size_t packetIndex, quatPacket qPacket);


    static const size_t PACKET_SIZE_BYTES = 64;
    // Integer division is an implicit floor function.
    static const size_t QUATERNIONS_PER_PACKET = PACKET_SIZE_BYTES/sizeof(quatPacket);

    uint8_t packet_[PACKET_SIZE_BYTES];
};


#endif // USB_PACKET_H
