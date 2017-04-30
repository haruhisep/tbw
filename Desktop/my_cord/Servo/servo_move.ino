#include <Servo.h>

Servo myservo;

void setup()
{
   myservo.attach(10);
}

void loop()
{
 for (int i = 20; i < 160; i++){
   myservo.write(i);
   delay(200);
 }
}  
