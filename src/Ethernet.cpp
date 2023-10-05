#include <string>

#include "Frame.h"
#include "Ethernet.h"
#include "FrameStringifyVisitor.h"

using namespace std;

Ethernet::Ethernet(string packet) : Frame(packet)
{
}

void Ethernet::parse()
{
    this->parsedData = this->payload;
}

string Ethernet::stringify(FrameStringifyVisitor *frameStringifyVisitor)
{
    return frameStringifyVisitor->stringify(*this);
}

string Ethernet::getParsedData()
{
    return this->parsedData;
}

Ethernet::~Ethernet()
{
}
