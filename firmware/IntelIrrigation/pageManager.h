#pragma once

/*
  -- pagesManager.h --
  Include login of pages.
*/

// -----------
// -- Pages --
// -----------

// -- Power pages --
// Values
#define MAX_POWER 500
// Selector
#define MAX_SELECTOR_POWER 2
#define MAX_SELECTOR_POWER_RANGE 2
#define SELECT_POWER 1
#define SELECT_RANGE_POWER 2
#define SELECT_MIN_POWER 1
#define SELECT_MAX_POWER 2

// -- Ml Liquid page --
// Values
#define MAX_ML_LIQUID 5000
// Selector
#define MAX_SELECTOR_ML_LIQUID 1
#define SELECT_ML_LIQUID 1

// -- Schedule page --
// Values
#define MAX_DAYS_SCHEDULE 31
#define MAX_HOURS_SCHEDULE 23
#define MAX_MINS_SCHEDULE 59
// Selector
#define MAX_SELECTOR_SCHEDULE 3
#define SELECT_MINS_SCHEDULE 3
#define SELECT_HOURS_SCHEDULE 2
#define SELECT_DAYS_SCHEDULE 1

// -- Main menu page --
#define MAX_SELECTOR_MAIN_MENU 2

// -- Settings page --
#define MAX_SELECTOR_SETTINGS 4


// ---------------
// -- Selectors --
// ---------------

int8_t selector = 1;

// ------------
// -- Values --
// ------------

uint16_t minPowerValue = 30, maxPowerValue = 60;

// -------------
// -- Headers --
// -------------

void setupConfigurationPages();
// Controls
void controlEnterPower();
void controlEnterPowerRange();
void controlEnterMlLiquid();
void controlChooseMode();
void controlEnterSchedule();