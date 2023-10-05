#ifndef FRAMESTRINGIFYVISITOR_H
#define FRAMESTRINGIFYVISITOR_H

#include <string>

#include "Ethernet.h"
#include "ECPRI.h"

using namespace std;

class FrameStringifyVisitor
{
public:
    virtual string stringify(Ethernet frame) = 0;
    virtual string stringify(ECPRI frame) = 0;

    ~FrameStringifyVisitor();
};

#endif // FRAMESTRINGIFYVISITOR_H
