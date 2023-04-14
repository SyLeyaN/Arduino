#include <TaskManagerIO.h>

#define NUMBER_OF_PINS 6

int* led = new int[NUMBER_OF_PINS];
int pins[NUMBER_OF_PINS] = {3, 5, 6, 9, 10, 11};
long* intArr = new long[NUMBER_OF_PINS];

void setup() {
  for (int i = 0; i < NUMBER_OF_PINS; ++i) {
    led[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }

  intArr[0] = 160000;
  intArr[1] = 50000;
  intArr[2] = 800000;
  intArr[3] = 400000;
  intArr[4] = 200000;
  intArr[5] = 100000;
  taskid_t taskId[6];
  for (int i = 0; i < 6; i++){
    taskId[i] = taskManager.scheduleFixedRate(intArr[i], [] {
    if (led[i] == LOW) {
      led[i] = HIGH;
    }
    else {
      led[i] = LOW;
    }

    digitalWrite(pins[i], led[i]);
  }, TIME_MICROS);
  }
}

void loop() {
  taskManager.runLoop();
}