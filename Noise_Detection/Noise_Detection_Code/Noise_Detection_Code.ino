// مكتبه الشاشه
#include <LiquidCrystal.h>
// تعريف دبابيس LCD:
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
// تعريف دبابيس المستشعر، البازر، والـ LED:
const int SENSOR_PIN = 2;  // دبابيس المستشعر
const int BUZZER_PIN = 7;  // دبابيس البازر
const int LED_PIN = 6;     // دبابيس الـ LED
void setup()  
{   
  pinMode(SENSOR_PIN, INPUT);   // تعيين دبوس المستشعر كمداخل
  pinMode(BUZZER_PIN, OUTPUT);  // تعيين دبوس البازر كمخرجات
  pinMode(LED_PIN, OUTPUT);     // تعيين دبوس الـ LED كمخرجات
  lcd.begin(20, 4);             // تهيئة شاشة LCD بـ 20 عمودًا و 4 صفوف
  lcd.setCursor(0, 0);          // تعيين مكان الكتابة في الصف الأول، العمود الأول
  lcd.print("  THE BRIGHT LIGHT    ");
  lcd.setCursor(0, 1);          // تعيين مكان الكتابة في الصف الثاني
  lcd.print("NOISE MONITORING SYS");
  lcd.setCursor(0, 3);          // تعيين مكان الكتابة في الصف الرابع
  lcd.print("      NO SOUND        ");
}
void loop()  
{
  int Sensor_Val = digitalRead(SENSOR_PIN);  // قراءة قيمة المستشعر
  if (Sensor_Val == HIGH)  // إذا تم اكتشاف صوت
  {
    lcd.setCursor(0, 3);               // تعيين مكان الكتابة في الصف الرابع
    lcd.print("   SOUND DETECTED     ");  // عرض رسالة على الشاشة: "تم اكتشاف صوت"
    digitalWrite(BUZZER_PIN, HIGH);    // تشغيل البازر
    digitalWrite(LED_PIN, LOW);        // إيقاف الـ LED (إيقاف الضوء)
  }
  else  // إذا لم يتم اكتشاف صوت
  {
    lcd.setCursor(0, 3);               // تعيين مكان الكتابة في الصف الرابع
    lcd.print("      NO SOUND        ");  // عرض رسالة على الشاشة: "لا يوجد صوت"
    digitalWrite(BUZZER_PIN, LOW);     // إيقاف البازر
    digitalWrite(LED_PIN, HIGH);       // تشغيل الـ LED (إضاءة الضوء)
    }}
