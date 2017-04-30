//加速度センサ

void setup(){
  Serial.begin(9600);
}

void loop(){
  const int accel_pin[] = {A1, A2, A3};
  int i, j;
  long accel_data[] = {0, 0, 0};
  int angle[] = {0, 0};
  
  //100回読み込んで平均値
  for(i=0; i<3; i++){
    for(j=0; j<100; j++){
  accel_data[i] = accel_data[i] + analogRead(accel_pin[i]);
    }
  }
  
  for(i=0; i<3; i++){
     accel_data[i] /= 100;
     /*
     Serial.print(accel_data[i]);
     Serial.print(", ");
  } 
  Serial.println("");
  */
  }
  
#if 1
     //角度計算
     angle[0] = atan2(accel_data[0]-511, accel_data[2]-555) / 3.14159 * 180.0;
     Serial.print("X = ");
     Serial.print(angle[0]);
     Serial.print(", ");
     angle[1] = atan2(accel_data[1]-533, accel_data[2]-555) / 3.14159 * 180.0;
     Serial.print("Y = ");
     Serial.println(angle[1]);
     
#endif
     
  delay(100);
  
}
