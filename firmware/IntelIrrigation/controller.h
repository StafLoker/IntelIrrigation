#pragma once

/*
  -- controller.h --
  Include logic of global application.
*/

#define DRY_SIGNAL 230

// -------------
// -- Headers --
// -------------

void startMain();
void setupConfiguration();
void runMain();

bool isDryGround();