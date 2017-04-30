int STB_pin = 1;
int CLK_pin = 2;
int DATA_pin = 3;
int data;

void setup(){
  pinMode(STB_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT); 
  pinMode(DATA_pin, OUTPUT);
}

void loop(){
  for(int i=0; i<10; i++){ 
  digitalWrite(STB_pin, HIGH);
  data = shiftIn(DATA_pin, CLK_pin, MSBFIRST);
  digitalWrite(CLK_pin, LOW);
  }
  delay(100);
}
