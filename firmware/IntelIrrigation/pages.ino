#include "global.h"

void viewLogoPage()
{
  display.clearBuffer();

  display.setFont(u8g2_font_6x12_tr);
  display.setCursor(49, 30);
  display.print(F("Intel"));
  display.setCursor(35, 40);
  display.print(F("Irrigation"));

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
  display.clearBuffer();

  display.setFont(u8g2_font_haxrcorp4089_tr);
  display.setCursor(49, 10);
  display.print(F("Power"));

  display.setFont(u8g2_font_5x8_tr);
  display.setCursor(41, 32);
  display.print(configuration.powerValue);
  if (selector == SELECT_POWER)
  {
    display.drawLine(40, 34, 56, 34);
  }
  display.setCursor(66, 32);
  display.print(F("L/H"));

  drawButton(26, 55, "Accept", !selector);

  drawButton(76, 55, "Range", selector == SELECT_RANGE_POWER);

  display.sendBuffer();
}

void viewEnterPowerRange()
{
  display.clearBuffer();

  display.setFont(u8g2_font_haxrcorp4089_tr);
  display.setCursor(48, 10);
  display.print(F("Power"));

  display.setFont(u8g2_font_5x8_tr);
  display.setCursor(37, 33);
  display.print(configuration.minPowerValue);
  if (selector == SELECT_MIN_POWER)
  {
    display.drawLine(37, 35, 51, 35);
  }

  display.drawLine(56, 30, 61, 30);

  display.setCursor(67, 33);
  display.print(configuration.maxPowerValue);
  if (selector == SELECT_MAX_POWER)
  {
    display.drawLine(66, 35, 81, 35);
  }

  display.setCursor(87, 33);
  display.print(F("L/H"));

  drawButton(48, 56, "Accept", !selector);

  display.sendBuffer();
}

void viewEnterMlLiquid()
{
  display.clearBuffer();

  display.setFont(u8g2_font_6x10_tr);
  display.setCursor(71, 33);
  display.print(F("mL"));

  display.setFont(u8g2_font_5x8_tr);
  display.setCursor(6, 10);
  display.print(F("ml of irrigation liquid"));

  display.setCursor(46, 33);
  display.print(configuration.mlLiquidValue);
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
  display.setCursor(52, 10);
  display.print(F("Mode"));

  if (!selector)
  {
    display.drawRFrame(19, 39, 92, 19, 5);
    display.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    display.setCursor(45, 52);
    display.print(F("Schedule"));

    display.drawRBox(19, 15, 92, 19, 5);
    display.setDrawColor(2);
    display.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    display.setCursor(45, 28);
    display.print(F("Auto"));
  }
  else
  {
    display.drawRFrame(19, 15, 92, 19, 5);
    display.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    display.setCursor(45, 28);
    display.print(F("Auto"));

    display.drawRBox(19, 39, 92, 19, 5);
    display.setDrawColor(2);
    display.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    display.setCursor(45, 52);
    display.print(F("Schedule"));
  }
  display.sendBuffer();
}

void viewEnterSchedule()
{
  display.clearBuffer();

  display.setFont(u8g2_font_5x8_tr);
  display.setCursor(87, 32);
  display.print(F("min"));
  if (selector == SELECT_MINS_SCHEDULE)
  {
    display.drawLine(73, 34, 83, 34);
  }

  display.setCursor(74, 32);
  display.print(configuration.schedule.mins);

  display.setCursor(63, 32);
  display.print(F("h"));
  if (selector == SELECT_HOURS_SCHEDULE)
  {
    display.drawLine(49, 34, 59, 34);
  }
  display.setCursor(50, 32);
  display.print(configuration.schedule.hours);

  display.setCursor(39, 32);
  display.print(F("d"));
  if (selector == SELECT_DAYS_SCHEDULE)
  {
    display.drawLine(25, 34, 35, 34);
  }
  display.setCursor(26, 32);
  display.print(configuration.schedule.days);

  drawButton(48, 57, "Accept", !selector);

  display.setCursor(23, 9);
  display.print(F("Irrigation every"));

  display.sendBuffer();
}

void viewCongratulationsInitialConfiguration()
{
  display.clearBuffer();

  display.drawXBMP(96, 20, 16, 16, image_hand_thumbs_up_bits);

  display.setFont(u8g2_font_helvB08_tr);
  display.setCursor(20, 33);
  display.print(F("configured"));
  display.setCursor(13, 22);
  display.print(F("Device"));
  display.setCursor(36, 45);
  display.print(F("Enjoy !!!"));

  display.sendBuffer();

  delay(CONGRATULATION_INITIAL_CONFIGURATION_PAGE_DELAY);
}

void viewMainMenu()
{
  display.clearBuffer();
  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.setCursor(50, 9);
  display.print(F("Menu"));

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
    display.setCursor(37, 28);
    display.print(F("Review"));
    display.drawXBMP(14, 16, 16, 16, image_plant_bits);
    break;

  case SELECT_MANUAL_MODE_MAIN_MENU:
    display.drawRFrame(10, 14, 108, 20, 8);
    display.setCursor(37, 28);
    display.print(F("Review"));
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
    display.setCursor(37, 28);
    display.print(F("Review"));
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

  display.setCursor(36, 22);
  display.print(configuration.autoMode ? F("Auto") : F("Schedule"));

  display.drawLine(6, 23, 29, 23);
  display.setCursor(7, 22);
  display.print(F("Mode:"));

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
    display.setCursor(92, 50);
    display.print(F("ago"));

    display.setCursor(74, 50);
    display.print(F("min"));
    display.setCursor(62, 50);
    display.print("59");

    display.setCursor(54, 50);
    display.print(F("h"));
    display.setCursor(42, 50);
    display.print("23");

    display.setCursor(34, 50);
    display.print(F("d"));
    display.setCursor(21, 50);
    display.print("31");

    display.drawLine(25, 38, 100, 38);
    display.setCursor(26, 36);
    display.print(F("Last irrigation"));
  }
  else
  {
    display.drawEllipse(56, 58, 2, 2);
    display.drawFilledEllipse(66, 58, 2, 2);

    uint32_t timeLeft = scheduleTimer.timeLeft();

    display.setCursor(89, 50);
    display.print(F("min"));
    display.setCursor(77, 50);
    display.print((timeLeft % 3600000) / 60000);

    display.setCursor(69, 50);
    display.print(F("h"));
    display.setCursor(57, 50);
    display.print((timeLeft % 86400000) / 3600000);

    display.setCursor(49, 50);
    display.print(F("d"));
    display.setCursor(36, 50);
    display.print(timeLeft / 86400000);

    display.setCursor(22, 50);
    display.print(F("in"));

    display.drawLine(25, 38, 100, 38);
    display.setCursor(26, 36);
    display.print(F("Next irrigation"));
  }

  display.setFont(u8g2_font_helvB08_tr);
  display.setCursor(45, 10);
  display.print(F("Review"));
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

  display.setCursor(7, 45);
  display.print(F("irrigation"));

  display.setCursor(26, 35);
  display.print(F("to"));

  if (selector)
  {
    display.drawLine(44, 22, 52, 22);
    display.drawLine(8, 22, 16, 22);
  }
  display.setCursor(21, 25);
  display.print(F("Hold"));

  display.setFont(u8g2_font_6x10_tr);
  display.setCursor(30, 9);
  display.print(F("Manual mode"));

  display.sendBuffer();
}

void viewSettings()
{
  display.clearBuffer();

  display.setFontMode(1);
  display.setBitmapMode(1);

  display.setFont(u8g2_font_6x10_tr);
  display.setCursor(39, 9);
  display.print(F("Settings"));

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
    display.setCursor(39, 52);
    display.print(F("Change power"));
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
    display.setCursor(39, 52);
    display.print(F("Change power"));
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
    break;
  case SELECT_CHANGE_ML_SETTINGS_AUTO_MODE:
    display.drawBox(121, 27, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setCursor(39, 26);
    display.print(F("Change power"));
    display.setDrawColor(2);
    display.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 40, 106, 19, 4);
    display.setDrawColor(2);
    display.setCursor(39, 52);
    display.print(F("Change ml"));
    display.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
    break;
  case SELECT_BACK_SETTINGS_AUTO_MODE:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setCursor(39, 28);
    display.print(F("Change ml"));
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setCursor(39, 52);
    display.print(F("Back"));
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
    display.setCursor(32, 52);
    display.print(F("Change schedule"));
    display.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);

    display.drawRBox(9, 14, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_6x10_tr);
    display.setCursor(32, 27);
    display.print(F("Change mode"));
    display.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);
    break;
  case SELECT_CHANGE_SCHEDULE_SETTINGS_SCHEDULE_MODE:
    display.drawBox(121, 6, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setCursor(32, 27);
    display.print(F("Change mode"));
    display.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_5x8_tr);
    display.setCursor(32, 52);
    display.print(F("Change schedule"));
    display.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);
    break;
  case SELECT_CHANGE_POWER_SETTINGS_SCHEDULE_MODE:
    display.drawBox(121, 16, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setFont(u8g2_font_5x8_tr);
    display.setCursor(32, 26);
    display.print(F("Change schedule"));
    display.drawXBMP(12, 16, 15, 16, image_clock_quarters_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setFont(u8g2_font_6x10_tr);
    display.setCursor(32, 52);
    display.print(F("Change power"));
    display.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
    break;
  case SELECT_CHANGE_ML_SETTINGS_SCHEDULE_MODE:
    display.drawBox(121, 35, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setCursor(32, 26);
    display.print(F("Change power"));
    display.setDrawColor(2);
    display.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    display.drawRBox(9, 40, 106, 19, 4);
    display.setDrawColor(2);
    display.setCursor(32, 52);
    display.print(F("Change ml"));
    display.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
    break;
  case SELECT_BACK_SETTINGS_SCHEDULE_MODE:
    display.drawBox(121, 49, 5, 9);

    display.drawRFrame(9, 14, 106, 19, 5);
    display.setCursor(32, 28);
    display.print(F("Change ml"));
    display.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    display.drawRBox(9, 40, 106, 19, 5);
    display.setDrawColor(2);
    display.setCursor(32, 52);
    display.print(F("Back"));
    display.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }
}