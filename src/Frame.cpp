#include <string>

#include "Frame.h"

using namespace std;

Frame::Frame(string packet)
{
    this->packet = packet;

    this->preamble = packet.substr(0, 16);
    this->destAddress = packet.substr(16, 12);
    this->srcAddress = packet.substr(28, 12);
    this->type = packet.substr(40, 4);
    this->payload = this->packet.substr(44, packet.length() - 52);
    this->fcs = packet.substr(packet.length() - 8, 8);
}

string Frame::getPacket()
{
    return this->packet;
}

string Frame::getPreamble()
{
    return this->preamble;
}

string Frame::getDestAddress()
{
    return this->destAddress;
}

string Frame::getSrcAddress()
{
    return this->srcAddress;
}

string Frame::getType()
{
    return this->type;
}

string Frame::getPayload()
{
    return this->payload;
}

string Frame::getFcs()
{
    return this->fcs;
}

Frame::~Frame()
{
}
