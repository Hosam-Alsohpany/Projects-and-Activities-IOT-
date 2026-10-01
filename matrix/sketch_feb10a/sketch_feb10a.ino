void setup() { 
  byte i; 
  for (i = 0; i <= 12; i++) 
    pinMode(i,OUTPUT); 

  for (i = 7; i <= 12; i++) 
    digitalWrite(i,0); 
} 
void loop() { 
digitalWrite(7,1); PORTA(0b0000000); delay(5); digitalWrite(7,0); 
digitalWrite(8,1); PORTA(0b1110111); delay(5); digitalWrite(8,0); 

digitalWrite(9,1); PORTA(0b1110111); delay(5); digitalWrite(9,0); 

digitalWrite(10, 1); PORTA(0b1110111); delay(5); digitalWrite(10, 0); 

digitalWrite(11, 1); PORTA(0b0000000); delay(5); digitalWrite(11, 0); 


} 
void PORTA(byte value) 
{ 
  byte i; 
  for (i = 0; i <= 6; i++)  
    digitalWrite(i, bitRead(value, i)); 
} 
