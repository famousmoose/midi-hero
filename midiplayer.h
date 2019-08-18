#include <MIDIUSB.h>
#include <PitchToNote.h>

const byte CHANNEL = 0;
const byte VELOCITY = 100;

void playNote(byte pitch);
void stopNote(byte pitch);
byte buttonsToNote(unsigned char button);

//Mappings from controller to notes. Use PitchToNotes definitions or numbers
//position starts open and counts with LSB at green
//Chromatic scale starting at C3 mapped sequentially
//For GH Controller you have 32 values
const byte MAPPING_CHROMATIC[32] = {
    48,49,50,51,52,53,54,55,
    56,57,58,59,60,61,62,63,
    64,65,66,67,68,69,70,71,
    72,73,74,75,76,77,78,79
};

//C Major scale, sequential on controller
const byte MAPPING_MAJOR_SEQ[32] = {
  pitchC3, pitchD3, pitchE3, pitchF3, pitchG3, pitchA3, pitchB3,
  pitchC4, pitchD4, pitchE4, pitchF4, pitchG4, pitchA4, pitchB4,
  pitchC5, pitchD5, pitchE5, pitchF5, pitchG5, pitchA5, pitchB5,
  pitchC6, pitchD6, pitchE6, pitchF6, pitchG6, pitchA6, pitchB6
};

//C Minor Pentatonic open layout
