#include <iostream>
#include <string>

#include "Frame.h"
#include "ECPRI.h"
#include "Ethernet.h"
#include "FramePlainTextVisitor.h"

using namespace std;

int main()
{
    freopen ("input_packets", "r", stdin);
    freopen ("output_packets", "w", stdout);

    string packet;
    int i = 0;

    while(cin >> packet)
    {
        string type = packet.substr(40, 4);

        Frame *frame;

        if(type == "AEFE")
        {
            frame = new ECPRI(packet);
        }
        else
        {
            frame = new Ethernet(packet);
        }

        frame->parse();

        FrameStringifyVisitor *framePlainTextVisitor = new FramePlainTextVisitor();

        cout << "Packet #" << i++ << ":\n" << frame->stringify(framePlainTextVisitor) << endl << endl;

        for(int j=0; j<200; j++)
        {
            cout << "*";
        }

        cout << endl << endl;


        delete framePlainTextVisitor;
        delete frame;
    }

    return 0;
}
