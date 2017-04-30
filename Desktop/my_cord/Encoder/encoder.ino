volatile int encoder;

void setup()
{
 Serial.begin(9600);
 attachInterrupt(0,a,RISING);
}

void loop()
{
 digitalRead(encoder);
}  

void a()
{
  
}
