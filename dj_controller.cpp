#include <Control_Surface.h>

USBMIDI_Interface midi;

PBPotentiometer pitch {A0};

NoteButton controls[] {
  // {pin, midi address/note}
  {1, 1}, // Mod1
  {2, 2}, // Flux
  {3, 3}, // Cue
  {4, 4}, // Play/Pause
  {5, 5}, // Down
  {6, 6}, // Up
  {7, 7}, // Toggle
};

Bank<4> pads(4);

ManyButtonsSelectorLEDs<4> selectorsBank = {
  pads,               // bank to manage
  {{8,  9,  10, 11}}, // pins, buttons
  {{12, 13, 14, 15}}, // pins, LEDs
};

Bankable::NoteButton padsBank[] {
  // {bank, pin, midi address/note}
  {pads, 16, 50}, // Pad #1
  {pads, 17, 51}, // Pad #2
  {pads, 18, 52}, // Pad #3
  {pads, 19, 53}, // Pad #4
};

void setup() {
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}
