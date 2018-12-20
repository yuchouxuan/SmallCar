#ifndef _F_CAR_H__
#define _F_CAR_H__

#include <Arduino.h>
#include <Fruler.h>
#include <moter.h>
#include <MySer.h>
#include <ruler.h>

class Car
{
    private:
    Moter mot;
    FRuler fruS; //指向性测距
    ruler  fru; //前测距
    MySer ser;
    int SpeedNow();
    
    public:
    Car();
    void init(); //初始化
    void setSpeed(int sp); //调速
    void setAngle(int ag); //轮子角度
    void setFRAngle(int ag); //雷达角度
    int Fmm(); //主测距仪
    int getSpeed(); //取速度
    void printInf(); //测试函数

};
#endif