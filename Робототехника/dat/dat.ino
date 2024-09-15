
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<DHT.h>

// Инициализация объекта для работы с LCD-дисплеем по I2C
LiquidCrystal_I2C lcd(0x27,20,2);

// Инициализация объекта для работы с датчиком DHT11
DHT dht(2, DHT11);

void setup() {
  // Инициализация LCD-дисплея
  lcd.init();
  lcd.backlight();
  
  // Включение сериальной коммуникации с скоростью 9600 бит/с
  Serial.begin(9600);
  
  // Инициализация датчика DHT11
  dht.begin();
}

void loop() {
  // Чтение значения температуры и влажности с датчика
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  delay(2000);

  // Отправка значений влажности и температуры через сериальный порт
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.print("   Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  
  // Отображение значений на LCD-дисплее
  lcd.setCursor(0,0);
  lcd.print(temperature);
  lcd.setCursor(5, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print(humidity);
  lcd.setCursor(5, 1);
  lcd.print("%");
}
