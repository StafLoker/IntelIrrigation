#include "global.h"

void viewLogoPage()
{
  display.clearBuffer();

  display.setFont(u8g2_font_6x12_tr);
  display.drawStr(49, 30, "Intel");
  display.drawStr(35, 40, "Irrigation");

  display.drawFrame(13, 55, 32, 1);
  display.drawFrame(13, 8, 32, 1);
  display.drawFrame(12, 8, 1, 15);
  display.drawFrame(12, 41, 1, 15);
  display.drawFrame(83, 55, 32, 1);
  display.drawFrame(83, 8, 32, 1);
  display.drawFrame(115, 8, 1, 15);
  display.drawFrame(115, 41, 1, 15);

  display.sendBuffer();

  delay(LOGO_PAGE_DELAY);
}

void viewEnterPower()
{
  char valueString[4];

  display.clearBuffer();

  display.setFont(u8g2_font_haxrcorp4089_tr);
  display.drawStr(49, 10, "Power");

  display.setFont(u8g2_font_5x8_tr);
  sprintf(valueString, "%u", configuration.powerValue);

  display.drawStr(41, 32, valueString);
  if (selector == SELECT_POWER)
  {
    display.drawLine(40, 34, 56, 34);
  }
  display.drawStr(66, 32, "L/H");

  if (!selector)
  {
    display.drawButtonUTF8(26, 55, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  }
  else
  {
    display.drawButtonUTF8(26, 55, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  if (selector == SELECT_RANGE_POWER)
  {
    display.drawButtonUTF8(76, 55, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Range");
  }
  else
  {
    display.drawButtonUTF8(76, 55, U8G2_BTN_BW1, 0, 2, 2, "Range");
  }

  display.sendBuffer();
}

void viewEnterPowerRange()
{
  char minValueString[4], maxValueString[4];

  display.clearBuffer();

  display.setFont(u8g2_font_haxrcorp4089_tr);
  display.drawStr(48, 10, "Power");

  display.setFont(u8g2_font_5x8_tr);
  sprintf(minValueString, "%u", configuration.minPowerValue);
  display.drawStr(37, 33, minValueString);
  if (selector == SELECT_MIN_POWER)
  {
    display.drawLine(37, 35, 51, 35);
  }

  display.drawLine(56, 30, 61, 30);

  sprintf(maxValueString, "%u", configuration.maxPowerValue);
  display.drawStr(67, 33, maxValueString);
  if (selector == SELECT_MAX_POWER)
  {
    display.drawLine(66, 35, 81, 35);
  }

  display.drawStr(87, 33, "L/H");

  if (!selector)
  {
    display.drawButtonUTF8(48, 56, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  }
  else
  {
    display.drawButtonUTF8(48, 56, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  display.sendBuffer();
}

void viewEnterMlLiquid()
{
  char valueString[5];

  display.clearBuffer();

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(71, 33, "mL");

  display.setFont(u8g2_font_5x8_tr);
  display.drawStr(6, 10, "ml of irrigation liquid");

  sprintf(valueString, "%u", configuration.mlLiquidValue);
  display.drawStr(46, 33, valueString);
  if (selector == SELECT_ML_LIQUID)
  {
    display.drawLine(45, 35, 66, 35);
  }

  if (!selector)
  {
    display.drawButtonUTF8(48, 56, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  }
  else
  {
    display.drawButtonUTF8(48, 56, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }
  display.sendBuffer();
}

void viewChooseMode()
{
  display.clearBuffer();
  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x12_tr);
  display.setDrawColor(1);
  display.drawStr(52, 10, "Mode");

  if (!selector)
  {
    display.drawRFrame(19, 39, 92, 19, 5);
    display.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    display.drawStr(45, 52, "Schedule");

    display.drawRBox(19, 15, 92, 19, 5);
    display.setDrawColor(2);
    display.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    display.drawStr(45, 28, "Auto");
  }
  else
  {
    display.drawRFrame(19, 15, 92, 19, 5);
    display.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    display.drawStr(45, 28, "Auto");

    display.drawRBox(19, 39, 92, 19, 5);
    display.setDrawColor(2);
    display.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    display.drawStr(45, 52, "Schedule");
  }
  display.sendBuffer();
}

void viewEnterSchedule()
{
  char daysString[3], hoursString[3], minsString[3];

  display.clearBuffer();

  display.setFont(u8g2_font_5x8_tr);
  display.drawStr(87, 32, "min");
  if (selector == SELECT_MINS_SCHEDULE)
  {
    display.drawLine(73, 34, 83, 34);
  }
  sprintf(minsString, "%u", configuration.schedule[2]);
  display.drawStr(74, 32, minsString);

  display.drawStr(63, 32, "h");
  if (selector == SELECT_HOURS_SCHEDULE)
  {
    display.drawLine(49, 34, 59, 34);
  }
  sprintf(hoursString, "%u", configuration.schedule[1]);
  display.drawStr(50, 32, hoursString);

  display.drawStr(39, 32, "d");
  if (selector == SELECT_DAYS_SCHEDULE)
  {
    display.drawLine(25, 34, 35, 34);
  }
  sprintf(daysString, "%u", configuration.schedule[0]);
  display.drawStr(26, 32, daysString);

  if (!selector)
  {
    display.drawButtonUTF8(48, 57, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  }
  else
  {
    display.drawButtonUTF8(48, 57, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  display.drawStr(23, 9, "Irrigation every");

  display.sendBuffer();
}

void viewCongratulationsInitialConfiguration()
{
  static const unsigned char image_hand_thumbs_up_bits[] U8X8_PROGMEM = {0x00, 0x08, 0x00, 0x14, 0x00, 0x14, 0x00, 0x12, 0x00, 0x0a, 0x00, 0x09, 0x80, 0x7c, 0x5f, 0xc0, 0x31, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x15, 0x40, 0x71, 0x60, 0x9f, 0x3f};

  display.clearBuffer();

  display.drawXBMP(96, 20, 16, 16, image_hand_thumbs_up_bits);

  display.setFont(u8g2_font_helvB08_tr);
  display.drawStr(20, 33, "configured");
  display.drawStr(13, 22, "Device");
  display.drawStr(36, 45, "Enjoy !!!");

  display.sendBuffer();

  delay(CONGRATULATION_INITIAL_CONFIGURATION_PAGE_DELAY);
}

void viewMainMenu()
{
  static const unsigned char image_plant_bits[] U8X8_PROGMEM = {0x00, 0xc0, 0x00, 0xf0, 0x04, 0xf8, 0x0e, 0xfc, 0x1f, 0xfc, 0x3f, 0x7e, 0x3f, 0x7e, 0x3f, 0x3e, 0x1e, 0x0f, 0x0c, 0x03, 0x08, 0x01, 0x10, 0x01, 0xa0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00};
  static const unsigned char image_menu_settings_gear_bits[] U8X8_PROGMEM = {0xc0, 0x03, 0x48, 0x12, 0x34, 0x2c, 0x02, 0x40, 0xc4, 0x23, 0x24, 0x24, 0x13, 0xc8, 0x11, 0x88, 0x11, 0x88, 0x13, 0xc8, 0x24, 0x24, 0xc4, 0x23, 0x02, 0x40, 0x34, 0x2c, 0x48, 0x12, 0xc0, 0x03};

  display.clearBuffer();
  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(50, 9, "Menu");

  display.setDrawColor(1);
  switch (mainSelector)
  {
  case 0:
    display.drawRFrame(65, 38, 53, 20, 8);
    display.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    display.drawRFrame(10, 38, 52, 20, 8);
    display.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);

    display.drawRBox(10, 14, 108, 20, 8);
    display.setDrawColor(2);
    display.drawStr(37, 28, "Review");
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);
    break;

  case 1:
    display.drawRFrame(10, 14, 108, 20, 8);
    display.drawStr(37, 28, "Review");
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);

    display.drawRFrame(65, 38, 53, 20, 8);
    display.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    display.drawRBox(10, 38, 52, 20, 8);
    display.setDrawColor(2);
    display.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);
    break;

  case 2:
    display.drawRFrame(10, 38, 52, 20, 8);
    display.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);

    display.drawRFrame(10, 14, 108, 20, 8);
    display.drawStr(37, 28, "Review");
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);

    display.drawRBox(65, 38, 53, 20, 8);
    display.setDrawColor(2);
    display.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);
  }

  display.sendBuffer();
}

void viewReview()
{
  display.clearBuffer();

  display.setFont(u8g2_font_5x8_tr);

  display.drawStr(36, 22, configuration.autoMode ? "Auto" : "Schedule");
  display.drawLine(6, 23, 29, 23);
  display.drawStr(7, 22, "Mode:");

  if (configuration.autoMode)
  {
    display.drawFilledEllipse(62, 58, 2, 2);
    display.drawStr(92, 50, "ago");
    display.drawStr(74, 50, "min");
    display.drawStr(62, 50, "34");
    display.drawStr(54, 50, "h");
    display.drawStr(42, 50, "15");
    display.drawStr(34, 50, "d");
    display.drawStr(21, 50, "12");
    display.drawLine(25, 38, 100, 38);
    display.drawStr(26, 36, "Last irrigation");
  }
  else
  {
    if (!selector)
    {
      display.drawFilledEllipse(56, 58, 2, 2);
      display.drawEllipse(66, 58, 2, 2);

      display.drawStr(92, 50, "ago");
      display.drawStr(74, 50, "min");
      display.drawStr(62, 50, "34");
      display.drawStr(54, 50, "h");
      display.drawStr(42, 50, "15");
      display.drawStr(34, 50, "d");
      display.drawStr(21, 50, "12");
      display.drawLine(25, 38, 100, 38);
      display.drawStr(26, 36, "Last irrigation");
    }
    else
    {
      display.drawEllipse(56, 58, 2, 2);
      display.drawFilledEllipse(66, 58, 2, 2);

      display.drawStr(89, 50, "min");
      display.drawStr(77, 50, "34");
      display.drawStr(69, 50, "h");
      display.drawStr(57, 50, "15");
      display.drawStr(49, 50, "d");
      display.drawStr(36, 50, "12");
      display.drawStr(22, 50, "in");
      display.drawLine(25, 38, 100, 38);
      display.drawStr(26, 36, "Next irrigation");
    }
  }
  display.setFont(u8g2_font_helvB08_tr);
  display.drawStr(45, 10, "Review");
  display.sendBuffer();
}

void viewManualMode(bool animation)
{
  static const unsigned char image_weather_humidity_bits[] U8X8_PROGMEM = {0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x70, 0x00, 0x78, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfc, 0x01, 0x7e, 0x03, 0xfe, 0x02, 0xff, 0x06, 0xff, 0x07, 0xfe, 0x03, 0xfe, 0x03, 0xfc, 0x01, 0xf0, 0x00};
  static const unsigned char image_weather_humidity_white_bits[] U8X8_PROGMEM = {0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x50, 0x00, 0x48, 0x00, 0x88, 0x00, 0x04, 0x01, 0x04, 0x01, 0x82, 0x02, 0x02, 0x03, 0x01, 0x05, 0x01, 0x04, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x01, 0xf0, 0x00};
  static uint8_t animationFrame = 0;

  display.clearBuffer();

  display.setFont(u8g2_font_5x7_tr);
  if (!selector)
  {
    display.drawButtonUTF8(54, 59, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Back");
  }
  else
  {
    display.drawButtonUTF8(54, 59, U8G2_BTN_BW1, 0, 2, 2, "Back");
  }

  if (selector && animation)
  {
    animationFrame++;
    if (animationFrame > 2)
    {
      animationFrame = 0;
    }
  }

  switch (animationFrame)
  {
  case 0:
    display.drawXBMP(98, 12, 11, 16, image_weather_humidity_bits);
    display.drawXBMP(85, 23, 11, 16, image_weather_humidity_white_bits);
    display.drawXBMP(97, 35, 11, 16, image_weather_humidity_white_bits);
    break;
  case 1:
    display.drawXBMP(98, 12, 11, 16, image_weather_humidity_white_bits);
    display.drawXBMP(85, 23, 11, 16, image_weather_humidity_bits);
    display.drawXBMP(97, 35, 11, 16, image_weather_humidity_white_bits);
    break;
  case 2:
    display.drawXBMP(98, 12, 11, 16, image_weather_humidity_white_bits);
    display.drawXBMP(85, 23, 11, 16, image_weather_humidity_white_bits);
    display.drawXBMP(97, 35, 11, 16, image_weather_humidity_bits);
  }

  display.drawStr(7, 45, "irrigation");
  display.drawStr(26, 35, "to");
  if (selector)
  {
    display.drawLine(44, 22, 52, 22);
    display.drawLine(8, 22, 16, 22);
  }
  display.drawStr(21, 25, "Hold");

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(30, 9, "Manual mode");

  display.sendBuffer();
}

void viewSettings()
{
  if (configuration.autoMode)
  {
    viewSettingsAutoMode();
  }
  else
  {
    viewSettingsScheduleMode();
  }
}

void viewSettingsAutoMode()
{
  display.clearBuffer();

  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(39, 9, "Settings");

  display.setDrawColor(1);
  display.drawLine(123, 3, 123, 60);

  switch (mainSelector)
  {
  case 0:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 40, 106, 19, 5);
    display.drawStr(32, 52, "Change power");
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 14, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 28, "Change mode");
    display.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);
    break;
  case 1:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change mode");
    display.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Change power");
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
    break;
  case 2:
    display.drawBox(121, 27, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 26, "Change power");
    display.setDrawColor(2);
    display.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 40, 106, 19, 4);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Change ml");
    display.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
    break;
  case 3:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change ml");
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Back");
    display.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }

  display.sendBuffer();
}

void viewSettingsScheduleMode()
{
  display.clearBuffer();

  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(39, 9, "Settings");

  display.setDrawColor(1);

  display.drawLine(123, 3, 123, 60);

  switch (mainSelector)
  {
  case 0:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 40, 106, 19, 5);
    display.setFont(u8g2_font_5x8_tr);
    display.drawStr(32, 52, "Change schedule");
    display.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);

    display.drawRBox(9, 14, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_6x10_tr);
    display.drawStr(32, 27, "Change mode");
    display.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);
    break;
  case 1:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 27, "Change mode");
    display.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_5x8_tr);
    display.drawStr(32, 52, "Change schedule");
    display.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);
    break;
  case 2:
    display.drawBox(121, 16, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setFont(u8g2_font_5x8_tr);
    display.drawStr(32, 26, "Change schedule");
    display.drawXBMP(12, 16, 15, 16, image_clock_quarters_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_6x10_tr);
    display.drawStr(32, 52, "Change power");
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
    break;
  case 3:
    display.drawBox(121, 35, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 26, "Change power");
    display.setDrawColor(2);
    display.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 40, 106, 19, 4);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Change ml");
    display.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
    break;
  case 4:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change ml");
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Back");
    display.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }

  display.sendBuffer();
}