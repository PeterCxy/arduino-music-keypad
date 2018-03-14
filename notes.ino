#include "notes.h"

void playNote(int pin, int len, int freq) {
  int my_len = (1 + (freq - 440) / 440.0) * len;
  unsigned long sleep_interval = 1000000 / freq / 2; 
  for (int i = 0; i < my_len; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(sleep_interval);
    digitalWrite(pin, LOW);
    delayMicroseconds(sleep_interval);
  }
}

int octaveMove(int freq, int octaves) {
    return freq * pow(2, octaves);
}

int noteSharp(int freq) {
    return freq * HALF_NOTE;
}

int noteFlat(int freq) {
    return freq / HALF_NOTE;
}