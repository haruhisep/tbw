#include <SD.h>

int ans;
const int SD_pin = 10; //SDカードピン
const int CS_pin = 4; //ChipSelectピン

void setup(){
  
 Serial.begin(9600);
  
  pinMode(SD_pin, OUTPUT);
  if(!SD.begin(CS_pin)){
      Serial.println("SDcard error");
    } else {
      Serial.println("Card initialized.");
    }
    
    ans = 100 + 100;
    
   SD_write(ans);
   
}

void loop(){
  
}

int SD_write(int x){
  
  File logData = SD.open("test2.txt", FILE_WRITE);
  if(logData){
  logData.print("Height: ");
  Serial.print("Height: ");
  logData.println(x);
  Serial.println(x);
  logData.close();
  } else {
    Serial.println("file open error");
} 
}
