#pragma once

#include "global.h"

/*
  -- controller.h --
  Include logic of global application.
*/

/////////////
// DEFINEs //
/////////////

#define DRY_SIGNAL 230

// ------------
// -- Timers --
// ------------

#define TIMER_1_MIN 60000

// Objects
TimerMs scheduleTimer(1000, false, true);

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