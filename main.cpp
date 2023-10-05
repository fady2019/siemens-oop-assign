#include <iostream>
#include <string>

#include "Frame.h"
#include "ECPRI.h"
#include "Ethernet.h"
#include "FramePlainTextVisitor.h"

using namespace std;

int main()
{
    string packet = "FB555555555555D50000000000C1ECCD655507D9AEFE1002001480680080900000000101D10000100000FFFE7E0400000000000000000000000000000000000000000000B329AA60";

    ECPRI *frame = new ECPRI(packet);

    frame->parse();
    cout << frame->stringify(new FramePlainTextVisitor()) << endl;

    return 0;
}
