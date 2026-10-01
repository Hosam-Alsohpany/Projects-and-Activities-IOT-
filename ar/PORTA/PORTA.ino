void setup()
{
byte i;
for(i=0;i<=7;i++)
{
  pinMode(i,OUTPUT);
  }
}
void loop ()

{

PORTA(B11111111);

delay(1000);

PORTA(B00000000);

delay(1000);

}
void PORTA(byte value){
  byte i;
  for(i=0;i<=7;i++)
{
  digitalWrite(i,bitRead(value,i));
  }
}
