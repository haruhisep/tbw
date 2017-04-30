volatile int sum = 0;


void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, c, RISING);
}

void loop()
{
  delay(1000);
  Serial.println(sum/400);
  sum = 0;
}

void c(){
  sum += 1;
}
