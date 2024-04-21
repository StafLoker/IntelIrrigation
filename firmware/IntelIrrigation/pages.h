#pragma once

#include "global.h"

/*
  -- pages.h --
  Include graphic of pages, not logic.
*/

// ----------
// -- Time --
// ----------

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
void viewEnterPowerRange();
void viewEnterMlLiquid();
void viewChooseMode();
void viewEnterSchedule();
void viewCongratulationsInitialConfiguration();
void viewMainMenu();
void viewReview();
void viewManualMode();
void viewSettings();
void drawSettingsAutoMode();
void drawSettingsScheduleMode();

// -------------
// -- Bitmaps --
// -------------

static const unsigned char image_menu_settings_sliders_square_bits[] U8X8_PROGMEM = {0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xff, 0x33, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00};
static const unsigned char image_clock_quarters_bits[] U8X8_PROGMEM = {0xe0, 0x03, 0x98, 0x0c, 0x84, 0x10, 0x02, 0x20, 0x82, 0x20, 0x81, 0x40, 0x81, 0x40, 0x87, 0x70, 0x01, 0x41, 0x01, 0x42, 0x02, 0x20, 0x02, 0x20, 0x84, 0x10, 0x98, 0x0c, 0xe0, 0x03, 0x00, 0x00};
static const unsigned char image_weather_wind_bits[] U8X8_PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x11, 0x20, 0x22, 0x20, 0x22, 0x00, 0x22, 0x00, 0x11, 0xff, 0x4c, 0x00, 0x00, 0xb5, 0x41, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x80, 0x04, 0x00, 0x03};
static const unsigned char image_weather_humidity_bits[] U8X8_PROGMEM = {0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x70, 0x00, 0x78, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfc, 0x01, 0x7e, 0x03, 0xfe, 0x02, 0xff, 0x06, 0xff, 0x07, 0xfe, 0x03, 0xfe, 0x03, 0xfc, 0x01, 0xf0, 0x00};
static const unsigned char image_arrow_curved_left_down_bits[] U8X8_PROGMEM = {0x18, 0x08, 0x1f, 0x1e, 0x18, 0x03, 0x1c};
static const unsigned char image_weather_humidity_white_bits[] U8X8_PROGMEM = {0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x50, 0x00, 0x48, 0x00, 0x88, 0x00, 0x04, 0x01, 0x04, 0x01, 0x82, 0x02, 0x02, 0x03, 0x01, 0x05, 0x01, 0x04, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x01, 0xf0, 0x00};
static const unsigned char image_plant_bits[] U8X8_PROGMEM = {0x00, 0xc0, 0x00, 0xf0, 0x04, 0xf8, 0x0e, 0xfc, 0x1f, 0xfc, 0x3f, 0x7e, 0x3f, 0x7e, 0x3f, 0x3e, 0x1e, 0x0f, 0x0c, 0x03, 0x08, 0x01, 0x10, 0x01, 0xa0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00};
static const unsigned char image_menu_settings_gear_bits[] U8X8_PROGMEM = {0xc0, 0x03, 0x48, 0x12, 0x34, 0x2c, 0x02, 0x40, 0xc4, 0x23, 0x24, 0x24, 0x13, 0xc8, 0x11, 0x88, 0x11, 0x88, 0x13, 0xc8, 0x24, 0x24, 0xc4, 0x23, 0x02, 0x40, 0x34, 0x2c, 0x48, 0x12, 0xc0, 0x03};
static const unsigned char image_hand_thumbs_up_bits[] U8X8_PROGMEM = {0x00, 0x08, 0x00, 0x14, 0x00, 0x14, 0x00, 0x12, 0x00, 0x0a, 0x00, 0x09, 0x80, 0x7c, 0x5f, 0xc0, 0x31, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x15, 0x40, 0x71, 0x60, 0x9f, 0x3f};