// تعريف المنافذ
const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int relayPin = 5;
const int soundSensorPin = A0; // منفذ مستشعر الصوت
const int buttonPin = 6; // زر التفعيل

// تحديد مدى الأمان
const long safeDistance = 10; // بالسنتمترات

bool soundDetectionEnabled = false; // متغير للتحكم في تفعيل مستشعر الصوت

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // زر التفعيل
    pinMode(soundSensorPin, INPUT); // مستشعر الصوت
    Serial.begin(9600);
}

void loop() {
    // قراءة حالة الزر
    if (digitalRead(buttonPin) == LOW) {
        soundDetectionEnabled = true; // تفعيل مستشعر الصوت عند الضغط على الزر
        Serial.println("Sound detection enabled!");
        delay(300); // تأخير لتجنب تكرار القراءة بسبب الاهتزاز
    }

    // قياس المسافة باستخدام الحساس
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (0.034 * duration) / 2;

    // طباعة المسافة
    Serial.print("Distance: ");
    Serial.println(distance);

    // استشعار الصوت فقط إذا تم الضغط على الزر مسبقًا
    int soundValue = analogRead(soundSensorPin);
    Serial.print("Sound Value: ");
    Serial.println(soundValue);

    if (soundDetectionEnabled && soundValue > 500) { // 500 قيمة تجريبية، يمكن تعديلها
        Serial.println("Sound detected! Activating buzzer.");
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(relayPin, HIGH);
        delay(1000); // تشغيل الجرس لمدة ثانية
        digitalWrite(buzzerPin, LOW);
        digitalWrite(relayPin, LOW);
        soundDetectionEnabled = false; // إيقاف التفعيل بعد الاستجابة
    }

    delay(500);
}
