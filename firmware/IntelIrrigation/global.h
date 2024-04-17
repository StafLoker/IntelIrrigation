#pragma once

/*
  -- global.h --
  Include declaration of pins and structs.
*/

//////////
// Pins //
//////////

// Encoder
#define ENCODER_S1 11
#define ENCODER_S2 12
#define ENCODER_BUTTON 13

// Water pump
#define PUMP 7

// Soil moisture sensor
#define SOIL_MOISTURE_SENSOR A0

/////////////
// Structs //
/////////////

struct CONFIGURATION {
  bool autoMode = true, configured = false;
  uint8_t schedule[3] = { 0, 0, 0 };  // schedule = {days, hours, mins}
  uint16_t powerValue = 80, minPowerValue = 30, maxPowerValue = 60, mlLiquidValue = 500;
};