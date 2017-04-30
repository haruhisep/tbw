#include <Servo.h>

Servo servo;

void setup(){
  servo.attach(4);
}

void loop(){
  
for(int val=0; val<=180; val++){
  servo.write(val);
}

delay(1000);

for(int val=180; 0<val; val--){
  servo.write(val);
}

delay(1000);

}  

