

int USSpin = 1;

void setup(){
  Serial.begin(9600);
  
}

void loop(){
  int distance = USS_do(USSpin);
  Serial.print(distance);
  Serial.println(" m");
  
  
}

int USS_do(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  
  pinMode(pin, INPUT);
  int p = pulseIn(pin,INPUT);
  long round_trip = 340 * p / 1000000;
  int ans = round_trip / 2;
 
}
