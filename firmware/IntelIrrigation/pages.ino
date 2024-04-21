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

  drawButton(26, 55, "Accept", !selector);

  drawButton(76, 55, "Range", selector == SELECT_RANGE_POWER);

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

  drawButton(48, 56, "Accept", !selector);

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

  drawButton(48, 56, "Accept", !selector);

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

  drawButton(48, 57, "Accept", !selector);

  display.drawStr(23, 9, "Irrigation every");

  display.sendBuffer();
}

void viewCongratulationsInitialConfiguration()
{
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
  display.clearBuffer();
  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(50, 9, "Menu");

  display.setDrawColor(1);
  switch (mainSelector)
  {
  case SELECT_REVIEW_MAIN_MENU:
    display.drawRFrame(65, 38, 53, 20, 8);
    display.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    display.drawRFrame(10, 38, 52, 20, 8);
    display.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);

    display.drawRBox(10, 14, 108, 20, 8);
    display.setDrawColor(2);
    display.drawStr(37, 28, "Review");
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);
    break;

  case SELECT_MANUAL_MODE_MAIN_MENU:
    display.drawRFrame(10, 14, 108, 20, 8);
    display.drawStr(37, 28, "Review");
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);

    display.drawRFrame(65, 38, 53, 20, 8);
    display.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    display.drawRBox(10, 38, 52, 20, 8);
    display.setDrawColor(2);
    display.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);
    break;

  case SELECT_SETTINGS_MAIN_MENU:
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

  if (configuration.autoMode || !selector)
  {
    if (configuration.autoMode)
    {
      display.drawFilledEllipse(62, 58, 2, 2);
    }
    else
    {
      display.drawFilledEllipse(56, 58, 2, 2);
      display.drawEllipse(66, 58, 2, 2);
    }
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
    display.drawStr(77, 50, "50");
    display.drawStr(69, 50, "h");
    display.drawStr(57, 50, "23");
    display.drawStr(49, 50, "d");
    display.drawStr(36, 50, "31");
    display.drawStr(22, 50, "in");
    display.drawLine(25, 38, 100, 38);
    display.drawStr(26, 36, "Next irrigation");
  }

  display.setFont(u8g2_font_helvB08_tr);
  display.drawStr(45, 10, "Review");
  display.sendBuffer();
}

void viewManualMode()
{
  static uint8_t animationFrame = 0;

  display.clearBuffer();

  display.setFont(u8g2_font_5x7_tr);

  drawButton(54, 59, "Back", !selector);

  if (selector && animationManualMode)
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
  display.clearBuffer();

  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.drawStr(39, 9, "Settings");

  display.setDrawColor(1);

  display.drawLine(123, 3, 123, 60);

  if (configuration.autoMode)
  {
    drawSettingsAutoMode();
  }
  else
  {
    drawSettingsScheduleMode();
  }

  display.sendBuffer();
}

void drawSettingsAutoMode()
{
  switch (mainSelector)
  {
  case SELECT_CHANGE_MODE_SETTINGS:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 40, 106, 19, 5);
    display.drawStr(32, 52, "Change power");
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 14, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 28, "Change mode");
    display.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);
    break;
  case SELECT_CHANGE_POWER_SETTINGS_AUTO_MODE:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change mode");
    display.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Change power");
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
    break;
  case SELECT_CHANGE_ML_SETTINGS_AUTO_MODE:
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
  case SELECT_BACK_SETTINGS_AUTO_MODE:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change ml");
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Back");
    display.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }
}

void drawSettingsScheduleMode()
{
  switch (mainSelector)
  {
  case SELECT_CHANGE_MODE_SETTINGS:
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
  case SELECT_CHANGE_SCHEDULE_SETTINGS_SCHEDULE_MODE:
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
  case SELECT_CHANGE_POWER_SETTINGS_SCHEDULE_MODE:
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
  case SELECT_CHANGE_ML_SETTINGS_SCHEDULE_MODE:
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
  case SELECT_BACK_SETTINGS_SCHEDULE_MODE:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.drawStr(32, 28, "Change ml");
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.drawStr(32, 52, "Back");
    display.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }
}