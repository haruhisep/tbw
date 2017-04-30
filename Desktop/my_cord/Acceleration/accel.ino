int x;
int y;
int z;
int count = 0;
long sum_x, sum_y, sum_z;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  
  sum_x = x;
  sum_y = y;
  sum_z = z;
  
  count++;
  
  if(count==100){
    sum_x = sum_x / 100;
    sum_y = sum_y / 100;
    sum_z = sum_z / 100;
  
  Serial.print(sum_x);
  Serial.print(" ,");
  Serial.print(sum_y);
  Serial.print(" ,");
  Serial.println(sum_z);
  
  count = 0;
  
  sum_x = 0;
  sum_y = 0;
  sum_z = 0;
  }
  
}
