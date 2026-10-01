
 
 byte seg[]={0b0111111,0b000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
int d1,d2;
void setup() {



byte i;
for (i = 0; i <= 6; i++)
{
pinMode(i,OUTPUT);
}
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);}

void loop() {
int i;
for (i=1;i<=99;i++){

d1=i%10;
d2=(i/10)%10;
for (int j=0;j<=10;j++){
  digitalWrite(7,1);
  digitalWrite(8,0);
  de(d1);
// delay(10);
  digitalWrite(8,1);
  digitalWrite(7,0);
  de(d2);
// delay(10);


}





}


}
void de (int v){
  int i;
  for (i=0;i<7;i++){
digitalWrite(i,bitRead(seg[v],i));}
delay(5);

}
