#pragma once

#include "global.h"

/*
  -- controller.h --
  Include logic of global application.
*/

/////////////
// DEFINEs //
/////////////

/*
Sensor environment    Readings (Arduino 5V)
------------------    ---------------------
      Air                     430
  Pressed finger              300
    Dry earth                 350
    Wet ground                230
*/
#define DRY_SIGNAL 350

// ------------
// -- Timers --
// ------------

#define TIMER_1_MIN 60000 // (ms)

// Objects
TimerMs scheduleTimer(TIMER_1_MIN, false, true);

// ------------
// -- Values --
// ------------

volatile bool sleepAutoMode = false;

// -------------
// -- Headers --
// -------------

void isrButton();

void startMain();
void setupConfiguration();
void runMain();

bool isDryGround();