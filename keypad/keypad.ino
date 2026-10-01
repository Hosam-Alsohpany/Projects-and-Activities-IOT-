#include <LiquidCrystal.h>

#include <Key.h>
#include <Keypad.h>


LiquidCrystal lcd(0,1,2,3,4,5);


   const byte raw=4;
  const byte colm=3;

  char key [raw][colm]{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
  };

byte rawPins[raw]={9,10,11,12};
  byte colmPins[colm]={6,7,8};
 
Keypad mykeypad=Keypad(makeKeymap(key),rawPins,colmPins,raw,colm);
  
byte x;
void setup(){
  pinMode(13, OUTPUT);
 digitalWrite(13, LOW);
lcd.begin(16,2);
lcd.setCursor(1,0);


x=3;

}

void loop(){

char pass[4];
byte i;
lcd.print("enter password");
lcd.setCursor(1,2);

for (i=0;i<=3;i++){
pass[i]=mykeypad.waitForKey();
lcd.blink();
lcd.print(pass[i]);
}
if (pass[0]=='7'&&pass[1]=='0'&&pass[2]=='0'&&pass[3]=='3'){
  lcd.clear();
  lcd.setCursor(1,0);

  lcd.print(" Password True");
  digitalWrite(13,1);
  delay(1000);
  lcd.clear();

}
else {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wrong Password");
  delay(500);
  digitalWrite(13,0);
  lcd.clear();
  x=x-1;
  lcd.setCursor(0, 0);

  lcd.print("you have to try");
    lcd.setCursor(1, 2);
  lcd.print(x);
  delay(1000);
  lcd.clear();
  if (x==0){
      lcd.setCursor(0, 0);
      lcd.print("it's over try");
      digitalWrite(13, 1);
char k=mykeypad.getKey();
if (k=='*'){
  lcd.clear();
  
  x=3;

}
  }

}
  


}




// #include <LiquidCrystal.h>  
// LiquidCrystal lcd(0,1,2,3,4,5);  

// #include <Keypad.h>  

// const byte ROWS = 4; 
// const byte COLS = 3; 
// char keys[ROWS][COLS] = {  
// {'1','2','3'},  
//   {'4','5','6'},  
//   {'7','8','9'},  
//   {'*','0','#'}  
// };
// byte rowPins[ROWS] = {9, 10, 11, 12}; 
// byte colPins[COLS] = {6, 7, 8};   
// Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);  

// byte x;  

// void setup() {  
//     pinMode(13, OUTPUT);  
//     digitalWrite(13, LOW);  
//     lcd.begin(16, 2);  
//     lcd.setCursor(0, 0);  
//     x = 0;  
// }  

// void loop() {  
//     char password[4];  
//     byte i;  
//     lcd.print(" Enter Password ");  
//     lcd.setCursor(6, 1);  
//     for (i = 0; i <= 3; i++) {  
//         password[i] = mykeypad.waitForKey();  
//         lcd.print(password[i]);  
//     }  
//     lcd.setCursor(0, 0);  
//     if (password[0] == '1' && password[1] == '2' && password[2] == '3' && password[3] == '4') {  
//         lcd.print(" Password True ");  
//         digitalWrite(13, HIGH);  
//     } else {  
//         lcd.print(" Password False ");  
//         x = x + 1;  
//         if (x == 3) {  
// lcd.print("is over ")
//             digitalWrite(13, HIGH);  
//         }  
//         delay(2000);  
//         lcd.clear();  
//     }  
// }