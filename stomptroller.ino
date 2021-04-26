#include <OneButton.h>
#include <MIDI.h>

/**  Button Config
      ---------
      | 1    2 |
      |        |
      |        |
      | 3    4 |
      ---------
*/

// configure buttons
OneButton button1(2, true, true);
OneButton button2(3, true, true);
OneButton button3(4, true, true);
OneButton button4(5, true, true);

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // button 1
  button1.attachClick(button1Press);
  button1.attachLongPressStart(button1LongPressStart);

  // button 2
  button2.attachClick(button2Press);
  button2.attachLongPressStart(button2LongPressStart);

  // button 3
  button3.attachClick(button3Press);
  button3.attachLongPressStart(button3LongPressStart);

  // button 4
  button4.attachClick(button4Press);
  button4.attachLongPressStart(button4LongPressStart);

  // MIDI setup
  MIDI.begin();
}

void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
  button4.tick();

  // TODO: do we need the delay here as in the example?
}


// button 1 Events
void button1Press() {
  // Snapshot 1
  MIDI.sendControlChange(69, 0, 1);
}

void button1LongPressStart() {
  // FS4
  MIDI.sendControlChange(72, 0, 1);
}

// button 2 Events
void button2Press() {
  // Snapshot 2
  MIDI.sendControlChange(69, 1, 1);
}

void button2LongPressStart() {
  // FS5
  MIDI.sendControlChange(72, 127, 1);
}

// button 3 Events
void button3Press() {
  // Snapshot 3
  MIDI.sendControlChange(69, 2, 1);
}

void button3LongPressStart() {
  // Next Footswitch Mode
  MIDI.sendControlChange(71, 4, 1);
}


// button 4 Events
void button4Press() {
  // Tap tempo
  MIDI.sendControlChange(64, 127, 1);
}

void button4LongPressStart() {
  // show tuner
  MIDI.sendControlChange(68, 0, 1);
}
