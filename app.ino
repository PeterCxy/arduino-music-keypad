#include "notes.h"
#include "keypad.h"

#define MIN_INTERVAL 10
#define BUZZER 11
#define KEYBOARD_START 2

void setup() {
  pinMode(BUZZER, OUTPUT);
  initializeKeyboard(KEYBOARD_START);
}

bool sharp = false;
bool flat = false;
int octave = 0;
bool octave_up_pressed = false;
bool octave_down_pressed = false;

void loop() {
  int keys[MAX_KEYS] = {KEY_NULL, KEY_NULL};
  readKeyboard(keys, KEYBOARD_START);
  sharp = false;
  flat = false;
  bool _local_octave_up_pressed = false;
  bool _local_octave_down_pressed = false;
  for (int i = 0; i < MAX_KEYS; i++) {
    if (keys[i] == KEY_SHARP) {
      sharp = true;
      keys[i] = KEY_NULL;
    } else if (keys[i] == KEY_FLAT) {
      flat = true;
      keys[i] = KEY_NULL;
    } else if (keys[i] == KEY_OCTAVE_UP) {
      _local_octave_up_pressed = true;

      if (!octave_up_pressed)
        octave++;
      keys[i] = KEY_NULL;
    } else if (keys[i] == KEY_OCTAVE_DOWN) {
      _local_octave_down_pressed = true;

      if (!octave_down_pressed)
        octave--;
      keys[i] = KEY_NULL;
    }
  }

  if (octave_up_pressed && !_local_octave_up_pressed) {
    octave_up_pressed = false;
  } else if (!octave_up_pressed && _local_octave_up_pressed) {
    octave_up_pressed = true;
  }

  if (octave_down_pressed && !_local_octave_down_pressed) {
    octave_down_pressed = false;
  } else if (!octave_down_pressed && _local_octave_down_pressed) {
    octave_down_pressed = true;
  }
  
  for (int i = 0; i < MAX_KEYS; i++) {
    if (keys[i] != KEY_NULL) {
      int freq = octaveMove(keys[i], octave);
      
      if (sharp) {
        freq = noteSharp(freq);
      }
      if (flat) {
        freq = noteFlat(freq);
      }

      playNote(BUZZER, MIN_INTERVAL, freq);
    }
  }
}