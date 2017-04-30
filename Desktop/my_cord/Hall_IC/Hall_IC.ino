volatile unsigned long time1, time2 = 0, diff;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, c, RISING);
}

void loop()
{
  Serial.println(diff);
}

void c(){
  time1 = millis();  
  diff = 60000 / (time1 - time2);
  time2 = time1;
  }