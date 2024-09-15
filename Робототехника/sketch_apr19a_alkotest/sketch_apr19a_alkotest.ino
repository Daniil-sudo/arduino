
#include <TroykaMQ.h>                    // библиотека для MQ датчиков

#include <Wire.h>                             // библиотека для протокола I2C
#include <LiquidCrystal_I2C.h>       // библиотека для LCD 1602 
LiquidCrystal_I2C LCD(0x27,20,2);  // присваиваем имя дисплею

MQ3 mq3(A1);

void setup() {
   Serial.begin(9600);   // запускаем монитор порта
   LCD.init();                   // инициализация дисплея
   LCD.backlight();         // включение подсветки
   mq3.calibrate();        // калибровка датчика MQ3
 }

void loop() {
   Serial.print("Alcohol: ");
   Serial.print(mq3.readAlcoholMgL());    // выводим значение на монитор
   Serial.println(" mG/L");

   Serial.print("Alcohol: ");
   Serial.print(mq3.readAlcoholPpm());    // выводим значение на монитор
   Serial.println(" ppm");

   LCD.setCursor(0,0);
   LCD.print("Alcohol: ");
   LCD.print(mq3.readAlcoholMgL());        // выводим значение на дисплей
   LCD.print(" mG/L");

   LCD.setCursor(0,1);
   LCD.print("Alcohol: ");
   LCD.print(mq3.readAlcoholPpm());        // выводим значение на дисплей
   LCD.print(" ppm");

   delay(900);
   LCD.clear();  // очищаем экран дисплея
}
