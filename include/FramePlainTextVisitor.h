#ifndef FRAMEPLAINTEXTVISITOR_H
#define FRAMEPLAINTEXTVISITOR_H

#include <string>

#include "FrameStringifyVisitor.h"

using namespace std;

class FramePlainTextVisitor : public FrameStringifyVisitor
{

public:
    string stringify(Ethernet frame);
    string stringify(ECPRI frame);
};

#endif // FRAMEPLAINTEXTVISITOR_H
