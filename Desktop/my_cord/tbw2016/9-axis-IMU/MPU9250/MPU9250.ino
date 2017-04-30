#include <Wire.h>

#define MPU9250_ADDR 0x68

#define GYRO_FULL_SCALE_250 00
#define GYRO_FULL_SCALE_500 01
#define GYRO_FULL_SCALE_1000 10
#define GYRO_FULL_SCALE_2000 11

#define ACCEL_FULL_SCALE_2 00
#define ACCEL_FULL_SCALE_4 01
#define ACCEL_FULL_SCALE_8 10
#define ACCEL_FULL_SCALE_16 11

void I2C_read(uint8_t Address, uint8_t Register, uint8_t Byte, uint8_t *Data){
   //setting register addr
  Wire.beginTransmission(Address);
   Wire.write(Register);
   Wire.endTransmission();
    
  //reading Nbyte  
   Wire.requestFrom(Address, Byte);
   int index = 0;
   while(Wire.available()){
     Data[index++] = Wire.read(); 
   }
}

void I2C_Addr_Write(uint8_t Address, uint8_t Register, uint8_t data){
   Wire.beginTransmission(Address);
   Wire.write(Register);
   Wire.write(data);
   Wire.endTransmission();
}
  
void setup(){
  Wire.begin();
  Serial.begin(9600);
  //pull up SDA and CLK pin
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
 
  //Gyro_setup
  I2C_Addr_Write(MPU9250_ADDR, 27, GYRO_FULL_SCALE_2000);
  //Accel_setup
  I2C_Addr_Write(MPU9250_ADDR, 28, ACCEL_FULL_SCALE_16); 
  // Mag_setup
//  I2C_Addr_Write(MPU9250_ADDR, 0x37, 0x02);
  //use A/D conversion(8Hz)
//  I2C_Addr_Write(MPU9250_ADDR, 0x0A, 0x12);
}

void loop(){
  
  //reading accel and gyro
  //0x3Bからの14バイトに加速度xyz、ジャイロxyzのデータが入る
  uint8_t Buf[14];
  I2C_read(MPU9250_ADDR, 0x3B, 14, Buf);
  
  //16bit data <- 8bit + 8bit
  
  //accel
  int16_t accel_x = (Buf[0] << 8 | Buf[1]);
  int16_t accel_y = (Buf[2] << 8 | Buf[3]);
  int16_t accel_z = (Buf[4] << 8 | Buf[5]);
  
  //Buf[6],Buf[7]は温度センサの値
  
  //gyro
  int16_t gyro_x = (Buf[8] << 8 | Buf[9]);
  int16_t gyro_y = (Buf[10] << 8 | Buf[11]);
  int16_t gyro_z = (Buf[12] << 8 | Buf[13]);
  
  Serial.print("accel(x, y, z) = (");
  Serial.print(accel_x, DEC);
  Serial.print(", ");
  Serial.print(accel_y, DEC);
  Serial.print(", ");
  Serial.print(accel_z, DEC);
  Serial.println(")");
  
  Serial.println("");
  
  Serial.print("gyro(x, y, z) = (");
  Serial.print(gyro_x, DEC);
  Serial.print(", ");
  Serial.print(gyro_y, DEC);
  Serial.print(", ");
  Serial.print(gyro_z, DEC);
  Serial.println(")");
  
  //Magnet
  
  
  
}
