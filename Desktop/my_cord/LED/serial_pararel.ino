int STB_pin = 1;
int CLK_pin = 2;
int DATA_pin = 3;
int CLR_pin = 4;
long data[11] = {0b0000000000000000,
                 0b1000000000000000,
                 0b1100000000000000,
                 0b1110000000000000,
                 0b1111000000000000,
                 0b1111100000000000,
                 0b1111110000000000,
                 0b1111111000000000,
                 0b1111111100000000,
                 0b1111111110000000,
                 0b1111111111000000};

void setup(){
  pinMode(STB_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT); 
  pinMode(DATA_pin, OUTPUT);
  pinMode(CLR_pin, OUTPUT);
  digitalWrite(CLR_pin, HIGH);
}

void loop(){
  for(int i=0; i<11 ; i++){ 
  digitalWrite(STB_pin, HIGH);
  shiftOut(DATA_pin, CLK_pin, LSBFIRST, data[i]);
  shiftOut(DATA_pin, CLK_pin, LSBFIRST, data[i] >> 8);
  digitalWrite(STB_pin, LOW);
  delay(100);
  }
   for(int i=10; i>=0 ; i--){ 
  digitalWrite(STB_pin, HIGH);
  shiftOut(DATA_pin, CLK_pin, LSBFIRST, data[i]);
  shiftOut(DATA_pin, CLK_pin, LSBFIRST, data[i] >> 8);
  digitalWrite(STB_pin, LOW);
  delay(100);
  }
}
