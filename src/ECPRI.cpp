#include <string>

#include "ECPRI.h"
#include "Frame.h"
#include "FrameStringifyVisitor.h"

using namespace std;

ECPRI::ECPRI(string packet) : Frame(packet)
{
}

void ECPRI::parse()
{
    this->parsedData = new ECPRIData({
        .protocolVersion = this->payload.substr(0, 1),
        .concatenationIndicator = this->payload.substr(1, 1),
        .messageType = this->payload.substr(2, 2),
        .payloadSize = this->payload.substr(4, 4),
        .rtcId = this->payload.substr(8, 4),
        .sequenceId = this->payload.substr(12, 4)
    });
}

string ECPRI::stringify(FrameStringifyVisitor *frameStringifyVisitor)
{
    return frameStringifyVisitor->stringify(*this);
}

ECPRIData &ECPRI::getParsedData()
{
    return *(this->parsedData);
}

ECPRI::~ECPRI()
{
    delete this->parsedData;
}
