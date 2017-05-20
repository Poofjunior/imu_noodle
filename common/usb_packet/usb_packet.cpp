#include "usb_packet.h"

USBPacket::USBPacket()
{}


USBPacket::~USBPacket()
{}


void USBPacket::getQuaternionPacket(size_t packetIndex, USBPacket::quatPacket& qPacket)
{
    memcpy((void *) &qPacket,
           (void *) &packet_[packetIndex * sizeof(quatPacket)],
           sizeof(qPacket));
}


void USBPacket::setQuaternionPacket(size_t packetIndex, USBPacket::quatPacket qPacket)
{
    memcpy((void *) &packet_[packetIndex * sizeof(quatPacket)],
           (void *) &qPacket,
           sizeof(qPacket));
}

