#include <Servo.h>
#include <SD.h>

const int hall_IC_pin = 2; //ホールICピン 
const int USS_pin = 7; //超音波センサピン
const int height_meter_pin = 4; //高度計メータピン
const int RPS_meter_pin = 5; //RPSメータピン
const int SD_pin = 10; //SDカードピン
const int CS_pin = 4; //ChipSelectピン

Servo RPS_meter;

volatile unsigned long RPS;

volatile unsigned long time;
volatile unsigned long last = 0;

//ホールIC 割り込み
void rotation(){
  time = millis();
  RPS = cal(time, last);
  last = time;
}

//回転数の計算
int cal(int Time, int Last){
  double val;
  val = 60000 / (Time - Last);
  
  return val;
}

//超音波センサ
int USS(int pin){
/*  pinMode(pin,OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW); */
  
  pinMode(pin, INPUT);
  int p = pulseIn(pin,INPUT);
  Serial.print("p:");
  Serial.println(p);
  //ここで距離の計算をする
  //ans = map();
  
  return ans;
}

  //回転数メーター出力
void R_Meter_write(Servo* servo, int r_val, int Low, int High){
  int val;
  const int Lowest = 30;
  const int Highest = 160;
  if(r_val < Low){
    r_val = Low;
  } else if(r_val > High){
    r_val = High;
  } else {
  val = map(r_val, Low, High, Lowest, Highest);
  servo -> write(val);
  } 
}

  //高度計メータ
void LED_Meter_write(int h_val, int Low, int High){
  int val;
  const int Lowest = 0;
  const int Highest = 100;
  if(h_val < Low){
     h_val = Low; 
  } else if(h_val > High){
     h_val = High;
  } else {
    val = map(h_val, Low, High, Lowest, Highest);
  }
}

//SDカード　書き込み
int SD_write(int h_val, int rs_val){
  
  File logData = SD.open("datelog.csv", FILE_WRITE);
  if(!logData){
    return 1;
  } else {
  logData.print("Height: ");
  Serial.print("Height: ");
  logData.print(h_val);
  Serial.print(h_val);
  logData.print("RPS: ");
  Serial.print("RPS: ");
  logData.print(rs_val);
  Serial.print(rs_val);
  logData.close();
  }
}

void setup(){
  RPS_meter.attach(RPS_meter_pin);
  Serial.begin(9600);
  pinMode(SD_pin, OUTPUT);
  pinMode(hall_IC_pin, INPUT_PULLUP);
  attachInterrupt(0, rotation, RISING); 
  SD.begin(CS_pin);

}

void loop(){
  int height = USS(USS_pin);

  //Serial.println(RPS);
  Serial.println(height);
  
  R_Meter_write(&RPS_meter, RPS, 0, 100);
  LED_Meter_write(height, 0, 600);
  SD_write(height, RPS);  
}
