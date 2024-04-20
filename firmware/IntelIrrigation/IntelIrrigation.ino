/*
  --> IntelIrrigation <--
  @author: StafLoker
  @version: 1.0.0-SNAPSHOT
*/

/* --!!! IMPORTANT !!!--
  If you do not use the project wiring diagram, you should change ONLY the pins in the "global.h" file.
*/

/*
  ==== Version history ====

  = Version 1.1.0 =
    -
    -

  = Version 1.0.0 =
  Futures:
    -
    -
*/

/*
  ==== Futures on new versions ====

  - You can indicate the glass/bottle/etc in ml and according to the schedule (Schedule mode ONLY) it calculates approximately how many times or years/months/days/hours the flower can be watered.
  - In Setting add new screen that allows to set the screen contrast.
  - Before installing the firmware on the board you can specify in which language you prefer the interface. Possible languages: English, Spanish. Default: English.
  - At program start (setup) & activate "hot key" -> factory settings & start configuration
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

  // Encoder
  attachInterrupt(ENCODER_BUTTON_INT, isrButton, RISING);

  // Disable unused hardware
  power.hardwareDisable(PWR_SPI);

  // -----------
  // -- POWER --
  // -----------

  power.autoCalibrate();
  power.setSleepMode(STANDBY_SLEEP);

  // ----------------
  // -- Start main --
  // ----------------

  startMain();
}

void loop()
{
  runMain();
}