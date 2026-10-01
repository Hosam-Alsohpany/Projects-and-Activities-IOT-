#include <LiquidCrystal.h>  
#include <Keypad.h>  // إعداد شاشة LCD
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);  
const byte ROWS = 4; // عدد الصفوف
const byte COLS = 6; // عدد الأعمدة
char keys[ROWS][COLS] = {  
  {'O', '7', '8', '9', '*', '/'},  
  {'N', '4', '5', '6', '-', 'M'},  
  {'%', '1', '2', '3', '+', 'm'},  
  {' ', '0', ' ', '=', '+', ' '}  
};
byte rowPins[ROWS] = {9, 10, 11, 12}; // أطراف الصفوف
byte colPins[COLS] = {6, 7, 8, A0, A1, A2}; // أطراف الأعمدة
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int num1 = 0, num2 = 0;
char operation = '\0';//لتخزين العمليه
bool calculating = false;
void setup() {  
    lcd.begin(16, 2);  // إعداد شاشة LCD بحجم 16x2
    lcd.setCursor(0, 0);
    lcd.print("start ready");
    delay(1000);
    lcd.clear();   
}
void loop() {
    char key = mykeypad.getKey(); // قراءة المفتاح المضغوط
    // key = -
    if (key) { // إذا تم الضغط على مفتاح
        lcd.setCursor(1, 0);
        //----------
        if (key >= '0' && key <= '9')
         { // إذا كان رقمًا
            if (!calculating ) {
                num1 = num1 * 10 + (key - '0'); 
                lcd.print(num1);// بناء الرقم الأول
            } else {
                num2 = num2 * 10 + (key -'0'); // بناء الرقم الثاني
           lcd.setCursor(3, 0);
           lcd.clear();
           lcd.print(num1);lcd.print(operation);lcd.print(num2);
           }
        } else if (key == '+' || key == '-' || key == '*' || key == '%' || key == '/') 
           { // العمليات الأساسية
            if (!calculating) { // في حالة عدم حساب
                operation = key;//operation= -
                calculating = true;
                if (key !='M'){
                lcd.print(num1);}

                lcd.print(operation);
            }   
        }
         else if (key == '=')
           { // إذا كان زر النتيجة
            lcd.setCursor(0, 1); // الانتقال للسطر الثاني
            lcd.print("= ");            
            int result = 0;//لتخزين النتيجه المحسوبه 
            if (operation == '+') result = num1 + num2;
            else if (operation == '-') result = num1 - num2;
            else if (operation == '*') result = num1 * num2;
            else if (operation == '/') result = num1 / num2;
            else if (operation == '%') {
                if (num2 != 0) result = num1 % num2;
                else {
                    lcd.print("Err"); // خطأ القسمة على صفر
                    delay(2000);
                    resetCalculator();
                    return;                    }
                                        }
            lcd.print(result); // طباعة النتيجة
            delay(1000); // انتظار
            resetCalculator(); // إعادة ضبط الآلة الحاسبة
        } 
        else if (key == 'O') { // إذا كان زر ON/C
            resetCalculator();
     }
    }
}
void resetCalculator() {
    lcd.clear();
    num1 = 0;
    num2 = 0;
    operation = '\0';
    calculating = false;
    lcd.setCursor(0, 0);
    lcd.print("reday");
     delay(1000);
    lcd.clear();
}
