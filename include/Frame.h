#ifndef FRAME_H
#define FRAME_H

#include <string>

class FrameStringifyVisitor;

using namespace std;

class Frame
{
protected:
    string packet;
    string preamble;
    string destAddress;
    string srcAddress;
    string type;
    string payload;
    string fcs;

public:
    Frame(string packet);

    virtual void parse() = 0;
    virtual string stringify(FrameStringifyVisitor *frameStringifyVisitor) = 0;

    string getPacket();
    string getPreamble();
    string getDestAddress();
    string getSrcAddress();
    string getType();
    string getPayload();
    string getFcs();

    virtual ~Frame();
};

#endif // FRAME_H
