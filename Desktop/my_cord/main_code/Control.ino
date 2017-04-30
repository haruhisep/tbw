#include <Servo.h>
#include <EEPROM.h>

//digitalpin
const int elev_pin = 6; //servo_elevstor
const int ladd_pin = 7; //servo_ladder
//analogpin
const int joy1_pin = A0; //joy_elevator
const int joy2_pin = A3; //joy_ladder

Servo elevator;
Servo ladder;

void setup(){
  Serial.begin(9600);
  elevator.attach(elev_pin);  //ピンをサーボに割り当て
  ladder.attach(ladd_pin);
}

void loop(){
  int elev_val = map(analogRead(joy1_pin), 0, 1023, 30, 120);
  int ladd_val = map(analogRead(joy2_pin), 0, 1023, 30, 120);
  
  elevator.write(elev_val);
  ladder.write(ladd_val);
  
  }
