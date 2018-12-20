#include <Servo.h>
#ifndef _MYSER_H__
#define _MYSER_H__
class MySer {
    
    private:
    Servo myservo;
    public:
    int ang =  0;
    int angs[9] = {20,30,40,50,65,80,90,100,110};
    int SerPin = 11;
    
    void init();
    MySer();
    void setAngle(int a);
    int rev = 1;

};
#endif