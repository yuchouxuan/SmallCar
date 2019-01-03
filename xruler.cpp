#include <Arduino.h>
#include "xruler.h"

XRuler::XRuler()
{
	rx = RX01;
	tx = TX01; 
}

XRuler::XRuler(int irx, int itx)
{
	rx = irx;
	tx = itx;
}
void XRuler::init()
{   
    ss  = SoftwareSerial(rx,tx);
	sf.begin(9600);
	ss.begin(9600);
    delay(1);    
  ss.write(0XA5); 
  ss.write(0X53);    //初始化,连续输出模式
  ss.write(0XF8);    //初始化,连续输出模式


}

int XRuler::mm()
{
   unsigned char i=0,sum=0;
   uint16_t distance=0;
  unsigned char re_Buf[11],counter=0;
   unsigned char sign=0;
   byte data_Buf[3]={0};
   ss.listen();  
   while (ss.available()) {   
    re_Buf[counter]=(unsigned char)ss.read();
    if(counter==0&&re_Buf[0]!=0x5A) return;      // 检查帧头         
    counter++;       
    if(counter==8)                //接收到数据
    {    
       counter=0;                 //重新赋值，准备下一帧数据的接收 
       sign=1;
    }      
  }


  if(sign)
  {   
     sign=0;
     for(i=0;i<7;i++)
      sum+=re_Buf[i]; 
     if(sum==re_Buf[i] )        //检查帧头，帧尾
     {  	       
          data_Buf[0]=re_Buf[4];
          data_Buf[1]=re_Buf[5];
          distance=data_Buf[0]<<8|data_Buf[1];
       
	      
   }
  } 
  sf.listen();
  return distance;


}