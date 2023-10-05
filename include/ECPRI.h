#ifndef ECPRI_H
#define ECPRI_H

#include <string>

#include "Frame.h"

using namespace std;

typedef struct ECPRIData
{
    string protocolVersion;
    string concatenationIndicator;
    string messageType;
    string payloadSize;
    string rtcId;
    string sequenceId;
} ECPRIData;

class ECPRI : public Frame
{
private:
    ECPRIData *parsedData = nullptr;

public:
    ECPRI(string packet);

    void parse();
    string stringify(FrameStringifyVisitor *frameStringifyVisitor);

    ECPRIData &getParsedData();

    ~ECPRI();
};

#endif // ECPRI_H
