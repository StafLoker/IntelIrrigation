#pragma once

/*
  -- pages.h --
  Include grafic of pages, not logic.
*/

// Timers
#define DISPLAY_TIMER 30
uint32_t displayTimer;

// Page delays
#define LOGO_PAGE_DELAY 2000
#define CONGRATULATION_INITIAL_CONFIGURATION_PAGE_DELAY 1300

// -------------
// -- Headers --
// -------------

void viewLogoPage();
void viewEnterPower();
void viewEnterPowerRange(uint16_t, uint16_t);
void viewEnterMlLiquid();
void viewChooseMode();
void viewEnterSchedule();
void viewCongratulationsInitialConfiguration();
void viewMainMenu();
void viewReview();
void viewManualMode(bool);
void viewSettings();
void viewSettingsAutoMode();
void viewSettingsScheduleMode();