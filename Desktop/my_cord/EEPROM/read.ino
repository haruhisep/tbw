#include <EEPROM.h>

int value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = EEPROM.read(5); 
  Serial.println(value);
 }
