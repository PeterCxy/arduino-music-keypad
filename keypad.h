#include "notes.h"

#ifndef _KEYPAD_H
#define _KEYPAD_H
#define MAX_KEYS 2
#define KEY_NULL -100
#define KEY_SHARP -99
#define KEY_FLAT -98
#define KEY_OCTAVE_UP -97
#define KEY_OCTAVE_DOWN -96

int keyboard[4][4] = {
  {C, D, E, KEY_SHARP},
  {F, G, A, KEY_FLAT},
  {B, C * 2, D * 2, KEY_OCTAVE_UP},
  {E * 2, F * 2, G * 2, KEY_OCTAVE_DOWN},
};

#endif