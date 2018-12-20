#include <car.h>

Car mycar;

void setup() {
  mycar.init();
  Serial.begin(9600);
  pinMode(31,OUTPUT);
  // put your setup code here, to run once:
}
void printInf()
{
  Serial.print(mycar.Fmm());
  Serial.print(":");
  Serial.println(mycar.getSpeed());

}
bool flag = true;
void loop() {
  //printInf();


  delay(100);
  int  dist = mycar.Fmm();
  if(dist > 300 ) mycar.setSpeed(100);
  // if(dist < 200 ) mycar.setSpeed(150);
  //if(dist < 150 ) mycar.setSpeed(100);
  if(dist < 250 ) mycar.setSpeed(0);
  if(dist < 100 ) mycar.setSpeed(-100);

}
