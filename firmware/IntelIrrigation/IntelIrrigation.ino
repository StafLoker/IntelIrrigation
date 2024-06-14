/*
  --> IntelIrrigation <--
  Author: StafLoker
  Version: 1.0.0
*/

/* --!!! IMPORTANT !!!--
  If you do not use the project wiring diagram, you should change ONLY the pins in the "global.h" file.
*/

/*
  ==== Version history ====

  = Version 1.0.0 =
  Futures:
    - Two modes of operation, "Automatic" and "Schedule".
      - "Automatic" - according to the sensor readings the watering is switched on.
      - "Schedule" - set a schedule (example: every 2 days, 5 hours and 30 minutes) according to which the watering is switched on.
    - Initial configuration of the device during the first start of the device.
    - The configuration is stored in the EEPROM memory.
    - Automatic sleep mode (both modes).
    - Programme menus:
      - Settings. All parameters set during initial configuration of the device can be changed.
      - Review. Shows the current operating mode and the elapsed time since the last watering. Also how long it will take for the next watering to take place.
      - Manual mode. Useful if you need to pump up the liquid to the flower (recommended).
*/

/*
  ==== Futures on new versions ====

  - You can indicate the glass/bottle/etc in ml and according to the schedule (Schedule mode ONLY) it calculates approximately how many times or years/months/days/hours the flower can be watered.
  - In Setting add new screen that allows to set the screen contrast.
  - Before installing the firmware on the board you can specify in which language you prefer the interface. Possible languages: English, Spanish. Default: English.
  - At program start (setup) & activate "hot key" -> factory settings & start configuration.
  - Config review.
  - Calibrate the soil moisture sensor.
*/

/*
  ==== Optimize ====

  - FLASH memory of settings "strings"
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