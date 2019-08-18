//Midi Guitar Hero guitar adapter for Wii guitars

#include "input.h"
#include "midiplayer.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Init time");
  inputInit();
}

void loop() {
  
  static unsigned char holdButtons = 0;
  unsigned char buttons;
  static bool playingNote = false;
  unsigned char strumState;
  
  if (nunchuck1.type == GuitarHeroController){
    nunchuck1.readData();    // Read inputs and update maps
    buttons = getButtonBitmask(
      nunchuck1.values[10] == 255 ? 1 : 0, //green
      nunchuck1.values[11] == 255 ? 1 : 0, //red
      nunchuck1.values[12] == 255 ? 1 : 0, //yellow
      nunchuck1.values[13] == 255 ? 1 : 0, //blue
      nunchuck1.values[14] == 255 ? 1 : 0  // orange
    );
    //nunchuck1.printInputs(); // Print all inputs
    strumState = nunchuck1.values[7];
   
    if (playingNote) {
      if (strumState == 128) { //released!
        Serial.println("release" + String(buttons));
        playingNote = false;
        stopNote(buttonsToNote(holdButtons));
      }
      if (buttons != holdButtons) {
        Serial.println("HoPo Buttons were: " + String(holdButtons) + " now: " +String(buttons));
        //stopNote(buttonsToNote(holdButtons));
        //playNote(buttonsToNote(buttons));
        //oldbuttons = buttons;
      }
    }
    else {
      if (strumState != 128) { //pressed

       Serial.println("press" + String(buttons));
       playingNote = true;
       playNote(buttonsToNote(buttons));
       holdButtons=buttons;
      }
    }
    
  }
  delay(1);
}
