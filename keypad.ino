#include "keypad.h"

void initializeKeyboard(int pin_start) {
  for (int i = pin_start; i <= pin_start + 3; i++) {
    pinMode(i, INPUT);
  }
  
  for (int i = pin_start + 4; i <= pin_start + 7; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}

void readKeyboard(int *keys, int pin_start) {
  int x, y = -1;
  int last_index = 0;
  for (int i = pin_start; i <= pin_start + 3; i++) {
    x = i - pin_start;
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    for (int j = pin_start + 4; j <= pin_start + 7; j++) {
      if (digitalRead(j) == LOW) {
        y = j - pin_start - 4;
        keys[last_index] = keyboard[x][y];
        last_index++;

        if (last_index >= MAX_KEYS) {
          pinMode(i, INPUT);
          break;
        }
      }
    }
    pinMode(i, INPUT);
  }
}