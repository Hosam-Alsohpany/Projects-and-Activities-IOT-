void setup() {
  byte i;
  for(i=0;i<=3;i++){
  pinMode(i,OUTPUT);
  }

}

void loop() {
byte i;
for(i=0;i<=3;i++){

digitalWrite(i,1);
delay(1000);
  }
for(i=0;i<=3;i++){
digitalWrite(i,0);
  }
delay(1000);


}