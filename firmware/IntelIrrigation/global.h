#pragma once

/*
  -- global.h --
  Include global declarations.
*/

//////////////////////////
// Library optimisation //
//////////////////////////

// U8g2lib.h

/*
  To optimize use library of "/libraries/U8g2"
*/

// EncButton.h

#define EB_NO_FOR      // disable support for pressFor/holdFor/stepFor and step counter (saves 2 bytes of RAM)
#define EB_NO_CALLBACK // disable attach event handler (saves 2 bytes of RAM)

///////////////
// Libraries //
///////////////

// Native
#include <stdint.h>
#include <Wire.h>
// Outside
#include <U8g2lib.h>    // Version: 2.34.22
#include <EncButton.h>  // Version: 3.5.4
#include <GyverPower.h> // Version: 2.2
#include <EEManager.h>  // Version: 2.0
#include <TimerMs.h> // Version: 1.2

// Personal
#include "controller.h"
#include "pageManager.h"
#include "pages.h"
#include "Pump.h"

//////////
// Pins //
//////////

// Encoder
#define ENCODER_S1 11
#define ENCODER_S2 12
#define ENCODER_BUTTON 2 // pin to attach || Arduino Nano/Uno -> D2 = 0 | D3 = 1

#if (ENCODER_BUTTON == 2)
#define ENCODER_BUTTON_INT 0

#elif (ENCODER_BUTTON == 3)
#define ENCODER_BUTTON_INT 1

#endif

// Water pump
#define PUMP 7

// Soil moisture sensor
#define SOIL_MOISTURE_SENSOR A0

/////////////
// DEFINEs //
/////////////

#define INIT_KEY 2

/////////////
// Structs //
/////////////

struct CONFIGURATION
{
  bool autoMode = true, configured = false;
  uint8_t schedule[3] = {0, 0, 0}; // schedule = {days, hours, mins}
  uint16_t powerValue = 110, minPowerValue = 100, maxPowerValue = 120, mlLiquidValue = 500;
};

/////////////
// Objects //
/////////////

U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
EncButton encoder(ENCODER_S1, ENCODER_S2, ENCODER_BUTTON);
Pump pump;

CONFIGURATION configuration;

EEManager memory(configuration);