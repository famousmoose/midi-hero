#include <MIDIUSB.h>


void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
void playNote(byte pitch){
  Serial.println("Note on "+String(pitch)+" "+String(VELOCITY));
  if (pitch > 0) {
    noteOn(CHANNEL, pitch, VELOCITY);
    MidiUSB.flush();
  }
}

void stopNote(byte pitch){
  Serial.println("Note off "+String(pitch)+" "+String(VELOCITY));
  if (pitch > 0){
    noteOff(CHANNEL, pitch, VELOCITY);
    MidiUSB.flush();
  }
}

byte buttonsToNote(unsigned char button){
  Serial.println(button);
  return MAPPING_CHROMATIC[button];
}
