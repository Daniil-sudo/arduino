#include <IRremote.h>
#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // Укажите пины подключения шагового двигателя

// Пульт ДУ коды
const unsigned int IR_UP = 2078930586;
const unsigned int IR_DOWN = 0xFD807F;
const unsigned int IR_LEFT = 0xFD40BF;
const unsigned int IR_RIGHT = 0xFDA05F;

IRrecv irrecv(7); // Пин для приема инфракрасных сигналов

void setup() {
  irrecv.enableIRIn(); // Инициализация приемника инфракрасных сигналов
}

void loop() {
  decode_results results;

  if (irrecv.decode(&results)) {
    switch (results.value) {
      case IR_UP:
        myStepper.step(50); // Шаг вперед
        break;
      case IR_DOWN:
        myStepper.step(-50); // Шаг назад
        break;
      case IR_LEFT:
        myStepper.step(-10); // Шаг налево
        break;
      case IR_RIGHT:
        myStepper.step(10); // Шаг направо
        break;
    }

    irrecv.resume(); // Продолжаем прием инфракрасного сигнала
  }
}
