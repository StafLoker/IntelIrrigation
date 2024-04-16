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

//////////////////////////
// Library optimisation //
//////////////////////////

// EncButton.h

#define EB_NO_FOR       // отключить поддержку pressFor/holdFor/stepFor и счётчик степов (экономит 2 байта оперативки)
#define EB_NO_CALLBACK  // отключить обработчик событий attach (экономит 2 байта оперативки)

///////////////
// Libraries //
///////////////

// Native
#include <stdint.h>
#include <Wire.h>
#include <EEPROM.h>
// Outside
#include <U8g2lib.h>     // Version: 2.34.22
#include <EncButton.h>   // Version: 3.5.4
#include <GyverPower.h>  // Version: 2.2
// Personal
#include "global.h"
#include "controller.h"
#include "pageManager.h"
#include "pages.h"
#include "Pump.h"
#include "EepromManager.h"

/////////////
// Objects //
/////////////

U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
EncButton encoder(ENCODER_S1, ENCODER_S2, ENCODER_BUTTON);
Pump pump;

CONFIGURATION configuration;

//////////
// MAIN //
//////////

void setup() {
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
  if (!configuration.configutated) {
    setupConfiguration();
  }
  viewMainMenu();
}

void loop() {
  runMain();
}