int pin = 2, a;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
}
  
void loop()
{
  a = digitalRead(pin);
  Serial.println(a);
}



