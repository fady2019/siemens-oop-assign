#include <sstream>

#include "FramePlainTextVisitor.h"

string FramePlainTextVisitor::stringify(Ethernet frame)
{
    stringstream strstream;

    strstream << frame.getPacket() << endl;
    strstream << "Preamble: " << frame.getPreamble() << endl;
    strstream << "Destination Address: " << frame.getDestAddress() << endl;
    strstream << "Source Address: " << frame.getSrcAddress() << endl;
    strstream << "Type: " << frame.getType() << endl;
    strstream << "Data: " << frame.getParsedData() << endl;
    strstream << "CRC: " << frame.getFcs();

    return strstream.str();
}

string FramePlainTextVisitor::stringify(ECPRI frame)
{
    stringstream strstream;

    strstream << frame.getPacket() << endl;
    strstream << "Preamble: " << frame.getPreamble() << endl;
    strstream << "Destination Address: " << frame.getDestAddress() << endl;
    strstream << "Source Address: " << frame.getSrcAddress() << endl;
    strstream << "Type: " << frame.getType() << endl;
    strstream << "Protocol Version: " << frame.getParsedData().protocolVersion << endl;
    strstream << "Concatenation Indicator: " << frame.getParsedData().concatenationIndicator << endl;
    strstream << "Message Type: " << frame.getParsedData().messageType << endl;
    strstream << "Payload Size: " << frame.getParsedData().payloadSize << endl;
    strstream << "RTC ID: " << frame.getParsedData().rtcId << endl;
    strstream << "Sequence ID: " << frame.getParsedData().sequenceId << endl;
    strstream << "CRC: " << frame.getFcs();

    return strstream.str();
}
