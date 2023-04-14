const int NUMBER_OF_PINS = 6;

long* micArr = new long[NUMBER_OF_PINS];
long* intArr = new long[NUMBER_OF_PINS];
int* led = new int[NUMBER_OF_PINS];
int pins[NUMBER_OF_PINS] = {3, 5, 6, 9, 10, 11};

void setup() {
  for (int i = 0; i < NUMBER_OF_PINS; ++i) {
    micArr[i] = 0;
    led[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }

  intArr[0] = 160000;
  intArr[1] = 50000;
  intArr[2] = 800000;
  intArr[3] = 400000;
  intArr[4] = 200000;
  intArr[5] = 100000;
}

void loop() {
  unsigned long micros_val = micros();

  for (int i = 0; i< 6; i++){
    if (micros_val - micArr[i] >= intArr[i]) {
    micArr[i] = micros_val;

    if (led[i] == LOW) {
      led[i] = HIGH;
    }
    else {
      led[i] = LOW;
    }

    digitalWrite(pins[i], led[i]);
  }
  }


}