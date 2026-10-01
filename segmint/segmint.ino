// byte seg[]={B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B10111110,B11111110,B11110110};
   //byte seg[]={B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,B1111111,B1111011};
    byte seg[]={0b0111111,0b000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
void setup() {
byte i;
for (i = 0; i <= 6; i++)
{
pinMode(i,OUTPUT);
}
// DDRD=B11111110;
//DDRD=B1111111;
 }


void loop() {

for(int i=0;i<10;i++){
  seven(seg[i]);
  delay(1100);
}}
void seven (int v){
  for (int i=0;i<=6;i++){
    digitalWrite(i,bitRead(v,i));
  }
}
// PORTA(B0111111);

// delay(1000);

// PORTA(B0000110);

// delay(1000);

// PORTA(B1011011);

// delay(1000);

// PORTA(B1001111);

// delay(1000);

// PORTA(B1100110);

// delay(1000);

// PORTA(B1101101);

// delay(1000);
// PORTA(B1111101);

// delay(1000);

// PORTA(B0000111);

// delay(1000);

// PORTA(B1111111);

// delay(1000);

// PORTA(B1101111);

// delay(1000);



// void PORTA (byte value){
// byte i;
// for(i=0;i<=6;i++){
//   digitalWrite(i,bitRead(value,i));
// }

// }