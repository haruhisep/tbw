#include <Wire.h>
#define MPU_9250 0x68
#define WHO_AM_I 0x75

char *c;

int MPU_9250_read(int start, char *buffer, int size)
{
  int i, n, error;

//send
  Wire.beginTransmission(MPU_9250);
  n = Wire.write(start);
  if (n != 1)
    return (-10);

  n = Wire.endTransmission(false);
  if (n != 0)
    return (n);

//receive
  Wire.requestFrom(MPU_9250, size, true);
  i = 0;
  while(Wire.available() && i<size)
  {
    buffer[i++]=Wire.read();
  }
  if ( i != size)
    return (-11);

  return (0);                  // return: no error
}


void setup(){
  pinMode(A4, INPUT_PULLUP);  //SDL_pin
  pinMode(A5, INPUT_PULLUP);  //SCL_pin
  Serial.begin(9600);
  Wire.begin();
}

void loop(){
  MPU_9250_read(WHO_AM_I, c, 1); //read WHO_AM_I
  Serial.println(*c, HEX); //returned "0x71": ok
}

