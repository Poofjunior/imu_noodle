#include "usb_packet.h"

UsbPacket::UsbPacket()
{}


UsbPacket::~UsbPacket()
{}


void UsbPacket::getQuaternionPacket(size_t packetIndex, UsbPacket::quatPacket& qPacket)
{
    memcpy((void *) &qPacket,
           (void *) &packet_[packetIndex],
           sizeof(qPacket));
}


void UsbPacket::setQuaternionPacket(size_t packetIndex, UsbPacket::quatPacket qPacket)
{
    memcpy((void *) &packet_[packetIndex],
           (void *) &qPacket,
           sizeof(qPacket));
}

