#include <SoftwareSerial.h>
#ifndef _XRULER_H__
#define _XRULER_H__
#define RX01  10
#define TX01 11
/*Not all pins on the Mega and Mega 2560 support change interrupts, 
so only the following can be used for RX: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, 
A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69).
*/


class XRuler 
{
    
    private:
    SoftwareSerial sf = SoftwareSerial(152,153);
    SoftwareSerial ss=SoftwareSerial(RX01,TX01);
    int rx;
    int tx;
    int getdis();
    public:
    XRuler();
    XRuler(int irx, int itx);
    void init();
    int mm();
};
#endif
