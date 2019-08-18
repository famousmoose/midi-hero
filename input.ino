
void inputInit(){
    nunchuck1.begin();
  if (nunchuck1.type == Unknown) {
    /** If the device isn't auto-detected, set the type explicatly
     *  NUNCHUCK,
     WIICLASSIC,
     GuitarHeroController,
     GuitarHeroWorldTourDrums,
     DrumController,
     DrawsomeTablet,
     Turntable
     */
    nunchuck1.type = NUNCHUCK;
  }
}

unsigned  char getButtonBitmask(bool g, bool r, bool y, bool b, bool o) {
  unsigned char buttonMask;
  buttonMask =  g
    | r << 1
    | y << 2
    | b << 3
    | o << 4
  ;
  return buttonMask;
}
