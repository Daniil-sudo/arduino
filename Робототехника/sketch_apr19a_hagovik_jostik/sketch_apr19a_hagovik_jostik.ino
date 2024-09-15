
int i1 = 0;
int i2 = 0;
int t = 0;

int t12 = 15; //НАСТРОЙКА!!!//
int t11 = 4;  //НАСТРОЙКА!!!//
int t22 = 0; //НАСТРОЙКА!!!//
int t21 = 0;  //НАСТРОЙКА!!!//

void setup() {
  //4,5,6,7 контакты для 1 двигателя
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //12,13,10,11 контакты для 2 двигателя
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); 
}

void prodlit11() { //функция для продления цикла
  if (analogRead (A0) < (520)) {
    i1++;
  }
  if (analogRead (A0) > (521) && analogRead (A0) < (999)) {
    i1--;
    t = t12;
  }
  if (analogRead (A0) > (1000)) {
    i1--;
    t = t11;
  }
}

void prodlit12() { //функция для продления цикла
  if (analogRead (A0) > (490)) {
    i1++;
  }
  if (analogRead (A0) > (51) && analogRead (A0) < (489)) {
    i1--;
    t = 12;
  }
  if (analogRead (A0) < (50)) {
    i1--;
    t = t11;
  }
}

void prodlit21() { //функция для продления цикла
  if (analogRead (A1) < (520)) {
    i2++;
  }
  if (analogRead (A1) > (521) && analogRead (A1) < (999)) {
    i2--;
    t = t22;
  }
  if (analogRead (A1) > (1000)) {
    i2--;
    t = t21;
  }
}

void prodlit22() { //функция для продления цикла
  if (analogRead (A1) > (490)) {
    i2++;
  }
  if (analogRead (A1) > (51) && analogRead (A1) < (489)) {
    i2--;
    t = t22;
  }
  if (analogRead (A1) < (50)) {
    i2--;
    t = t21;
  }
}

void stopPins() {
  digitalWrite(4, LOW); digitalWrite(5, LOW); digitalWrite(6, LOW);
  digitalWrite(7, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW);
  digitalWrite(12, LOW); digitalWrite(13, LOW); delay(100);
}

void loop() {
  if (analogRead (A0) > (521)) {
    t = t12;
    while (i1 < 1) { //цикл для вращения мотора 1 вправо
      digitalWrite(7, HIGH); digitalWrite(5, LOW); delay(t);
      digitalWrite(6, HIGH); digitalWrite(4, LOW); delay(t);
      digitalWrite(5, HIGH); digitalWrite(7, LOW); delay(t);
      digitalWrite(4, HIGH); digitalWrite(6, LOW); delay(t - 2);
      i1++; prodlit11();
    } i1 = 0; stopPins();
  }
  
  if (analogRead (A0) < (489)) {
    t = t12;
    while (i1 < 1) { //цикл для вращения мотора 1 влево
      digitalWrite(4, HIGH); digitalWrite(6, LOW); delay(t);
      digitalWrite(5, HIGH); digitalWrite(7, LOW); delay(t);
      digitalWrite(6, HIGH); digitalWrite(4, LOW); delay(t);
      digitalWrite(7, HIGH); digitalWrite(5, LOW); delay(t - 2);
      i1++; prodlit12();
    } i1 = 0; stopPins();
  }
  
  if (analogRead (A1) > (521)) {
    t = t22;
    while (i2 < 1) { //цикл для вращения мотора 2 вправо
      digitalWrite(13, HIGH); digitalWrite(11, LOW); delay(t);
      digitalWrite(12, HIGH); digitalWrite(10, LOW); delay(t);
      digitalWrite(11, HIGH); digitalWrite(13, LOW); delay(t);
      digitalWrite(10, HIGH); digitalWrite(12, LOW); delay(t - 2);
      i2++; prodlit21();
    } i2 = 0; stopPins();
  }
  
  if (analogRead (A1) < (489)) {
    t = t22;
    while (i2 < 1) { //цикл для вращения мотора 2 влево
      digitalWrite(10, HIGH); digitalWrite(12, LOW); delay(t);
      digitalWrite(11, HIGH); digitalWrite(13, LOW); delay(t);
      digitalWrite(12, HIGH); digitalWrite(10, LOW); delay(t);
      digitalWrite(13, HIGH); digitalWrite(11, LOW); delay(t - 2);
      i2++; prodlit22();
    } i2 = 0; stopPins();
  }
}
