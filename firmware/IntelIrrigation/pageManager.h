#pragma once

/*
  -- pageManager.h --
  Include logic of pages & values.
*/

// -----------
// -- Pages --
// -----------

/*
  --- Pages Enumeration ---

  Number      Page
  -----       ----
    0        Main menu
    1        Review
    2        Manual mode
    3        Settings
    4        Choose Mode
    5        Enter Schedule
    6        Enter Power
    7        Enter Power Range
    8        Enter Ml Liquid
*/
uint8_t page = 0;

/*
  All "Accept" or "Back" (not include menus) buttons are activated with selector == 0
*/

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
#define MAX_SELECTOR_SETTINGS_AUTO_MODE 3
#define MAX_SELECTOR_SETTINGS_AUTO_SCHEDULE 4

// ---------------
// -- Selectors --
// ---------------

// Pages use: Main Menu, Settings
int8_t mainSelector = 0;
// Pages use: others
int8_t selector = 1;

// ------------
// -- Values --
// ------------

bool animation = false;

// -------------
// -- Headers --
// -------------

void setupConfigurationPages();
void runMainPages();
// Controls
void controlMainMenu();
void controlReview();
void controlManualMode();
void controlSettings();
void controlEnterPower();
void controlEnterPowerRange();
void controlEnterMlLiquid();
void controlChooseMode();
void controlEnterSchedule();