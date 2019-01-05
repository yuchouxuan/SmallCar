#include <car.h>

int Leds[3] ={38,39,40};

Car mycar;


void setup() {
  mycar.init();
  Serial.begin(9600);
  pinMode(31,OUTPUT);

  pinMode(Leds[0],OUTPUT);
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
  for(int a = 0; a < 3;a++)
    {
      digitalWrite(Leds[a],LOW);
    }
  int  dist = mycar.Fmm();
  if(dist > 300 ) 
    {
      mycar.setSpeed(100);
      digitalWrite(Leds[0],HIGH);
    }
  if(dist < 250 ) 
  {
    mycar.setSpeed(0);
    digitalWrite(Leds[1],HIGH);
  }
  if(dist < 100 )
  { 
    mycar.setSpeed(-100);
    digitalWrite(Leds[2], HIGH);
  }
