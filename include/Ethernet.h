#ifndef ETHERNET_H
#define ETHERNET_H

#include <string>

#include "Frame.h"

using namespace std;

class Ethernet : public Frame
{
private:
    string parsedData;

public:
    Ethernet(string packet);

    void parse();
    string stringify(FrameStringifyVisitor *frameStringifyVisitor);

    string getParsedData();

    ~Ethernet();
};

#endif // ETHERNET_H
