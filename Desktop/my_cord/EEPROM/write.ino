#include <EEPROM.h>

void setup()
{
  int n = 10;
  EEPROM.write(5, n);  
}

void loop()
{
  
}

