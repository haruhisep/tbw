#include <SD.h>

const int CSpin = 4;
const int SSpin = 10;

void setup(){
  Serial.println("Start setup.");
  Serial.begin(9600);
  SD.begin();
  
  //SSpinを出力状態にしておかねばならない
  pinMode(SSpin, OUTPUT); 
  
  //ライブラリの初期化
  if(!SD.begin(CSpin)){
     Serial.println("setting failed");
     while(1);
  } 
  Serial.println("Setup is comp.");
}


void loop(){
  //ファイルオープン
  Serial.println("File open.");
  File datafile = SD.open("test.txt", FILE_WRITE);
  
  //0~9までを足し算した値を書き込む
  Serial.println("Writing start.");

  if(datafile){
    int i = 0;
    i += 10;
    datafile.println(i);
    datafile.println("writing comp.");

     //成功
      Serial.println("Writing comp.");
      
      //ファイルクローズ
      Serial.println("File close.");
      datafile.close();
   } else {
     //失敗
     Serial.println("File open error.");
   }
   //1s待機
   Serial.println("Waiting....");
   delay(1000);
}
