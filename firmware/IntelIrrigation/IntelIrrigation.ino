/*
  --> IntelIrrigation <--
  Author: StafLoker
  Version: 1.0.0-SNAPSHOT
*/

/*
  ==== Version history ====

  Version 1.1.0:
    -
    -

  Version 1.0.0:
    -
    -
*/

/*
  ==== Futures on new versions ====

  - You can indicate the glass/bottle/etc in ml and according to the schedule (Schedule mode ONLY) it calculates approximately how many times or years/months/days/hours the flower can be watered.
  - In Setting add new screen that allows to set the screen contrast.
  - Before installing the firmware on the board you can specify in which language you prefer the interface. Possible languages: English, Spanish. Default: English.
*/

#include "global.h"

//////////
// MAIN //
//////////

void setup()
{
  // --------------------
  // -- Setup hardware --
  // --------------------

  // Oled
  Wire.begin();
  display.begin();

  // Pump
  pump.begin();

  // ----------------
  // -- Start main --
  // ----------------
  startMain();
}

void loop()
{
  runMain();
}