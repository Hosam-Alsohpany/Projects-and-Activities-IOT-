#include <LiquidCrystal.h>
const int rs=8,en=9,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int sensorpin =A0;
int greenLED= 2 ;
 int redLED= 3;
void setup(){
 pinMode(greenLED, OUTPUT);
 pinMode(redLED, OUTPUT);
      lcd.begin(16,2); 
}
  
void loop(){
 int sensorvolue = analogRead(sensorpin);
 float mv = (sensorvolue *1024.0)*5000;
 float cel =(mv/10);
if(cel>=30){
  digitalWrite(redLED,HIGH);
  digitalWrite(greenLED,LOW);

  }else{
      digitalWrite(redLED,LOW);
  digitalWrite(greenLED,HIGH);
    
    }
        lcd.setCursor(0, 0); 
        lcd.print ("Temp in cel");
        lcd.setCursor(0, 1); 
        lcd.print (cel);
        delay(1000);


}
