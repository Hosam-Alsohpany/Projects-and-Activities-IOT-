void setup() {
  byte i;
    for(i=0;i<=4;i++){
  pinMode(i,INPUT_PULLUP);
  }
  pinMode(9,INPUT_PULLUP);

  for(i=4;i<=8;i++){
  pinMode(i,OUTPUT);
  }
  }

void loop() {
boolean x1,x2,x3,x4,X9;
x1=digitalRead(0);
x2=digitalRead(1);
x3=digitalRead(2);
x4=digitalRead(3);
X9= digitalRead(9);
if (x1==LOW){
  digitalWrite(4,1);
  
}else{
    digitalWrite(4,0);
   
}
if (x2==LOW){
  digitalWrite(5,1);
;
}else{
    digitalWrite(5,0 );
  
}
if (x3==LOW){
  digitalWrite(6,1);
  
}else{
    digitalWrite(6,0);
  
}
if (x4==LOW){
  digitalWrite(7,1);
 
}else{
    digitalWrite(7,0 );
   
}
if (X9==LOW){
byte i;
for (i=4;i<=8;i++)
digitalWrite(i,HIGH);

}else 
for (byte i=4;i<=8;i++)
digitalWrite(i,LOW);
}



