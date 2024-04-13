void viewLogoPage() {
  oled.clearBuffer();

  oled.setFont(u8g2_font_6x12_tr);
  oled.drawStr(49, 30, "Intel");
  oled.drawStr(35, 40, "Irrigation");

  oled.drawFrame(13, 55, 32, 1);
  oled.drawFrame(13, 8, 32, 1);
  oled.drawFrame(12, 8, 1, 15);
  oled.drawFrame(12, 41, 1, 15);
  oled.drawFrame(83, 55, 32, 1);
  oled.drawFrame(83, 8, 32, 1);
  oled.drawFrame(115, 8, 1, 15);
  oled.drawFrame(115, 41, 1, 15);

  oled.sendBuffer();

  delay(2000);
}

void viewEnterPower(uint16_t value, uint8_t selecter) {
  char valueString[4];

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_haxrcorp4089_tr);
  u8g2.drawStr(49, 10, "Power");

  u8g2.setFont(u8g2_font_5x8_tr);
  sprintf(valueString, "%u", value);

  u8g2.drawStr(41, 32, valueString);
  if (!selecter) {
    u8g2.drawLine(40, 34, 56, 34);
  }
  u8g2.drawStr(66, 32, "L/H");

  if (selecter == 1) {
    u8g2.drawButtonUTF8(26, 55, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  } else {
    u8g2.drawButtonUTF8(26, 55, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  if (selecter == 2) {
    u8g2.drawButtonUTF8(76, 55, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Range");
  } else {
    u8g2.drawButtonUTF8(76, 55, U8G2_BTN_BW1, 0, 2, 2, "Range");
  }

  u8g2.sendBuffer();
}

void viewEnterPowerRange(uint16_t minValue, uint16_t maxValue, uint8_t selecter) {
  char minValueString[4], maxValueString[4];

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_haxrcorp4089_tr);
  u8g2.drawStr(48, 10, "Power");

  u8g2.setFont(u8g2_font_5x8_tr);
  sprintf(minValueString, "%u", minValue);
  u8g2.drawStr(37, 33, minValueString);
  if (!selecter) {
    u8g2.drawLine(37, 35, 51, 35);
  }

  u8g2.drawLine(56, 30, 61, 30);

  sprintf(maxValueString, "%u", maxValue);
  u8g2.drawStr(67, 33, maxValueString);
  if (selecter == 1) {
    u8g2.drawLine(66, 35, 81, 35);
  }

  u8g2.drawStr(87, 33, "L/H");

  if (selecter == 2) {
    u8g2.drawButtonUTF8(48, 56, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  } else {
    u8g2.drawButtonUTF8(48, 56, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  u8g2.sendBuffer();
}

void viewEnterMlLiquid(uint16_t value, uint8_t selecter) {
  char valueString[5];

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(71, 33, "mL");

  u8g2.setFont(u8g2_font_5x8_tr);
  u8g2.drawStr(6, 10, "ml of irrigation liquid");

  sprintf(valueString, "%u", value);
  u8g2.drawStr(46, 33, valueString);
  if (!selecter) {
    u8g2.drawLine(45, 35, 66, 35);
  }

  if (selecter == 1) {
    u8g2.drawButtonUTF8(48, 56, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  } else {
    u8g2.drawButtonUTF8(48, 56, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }
  u8g2.sendBuffer();
}

void viewChooseMode(uint8_t selecter) {
  static const unsigned char image_clock_quarters_bits[] U8X8_PROGMEM = { 0xe0, 0x03, 0x98, 0x0c, 0x84, 0x10, 0x02, 0x20, 0x82, 0x20, 0x81, 0x40, 0x81, 0x40, 0x87, 0x70, 0x01, 0x41, 0x01, 0x42, 0x02, 0x20, 0x02, 0x20, 0x84, 0x10, 0x98, 0x0c, 0xe0, 0x03, 0x00, 0x00 };
  static const unsigned char image_menu_settings_sliders_square_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xff, 0x33, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00 };

  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);

  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.setDrawColor(1);
  u8g2.drawStr(52, 10, "Mode");

  if (!selecter) {
    u8g2.drawRFrame(19, 39, 92, 19, 5);
    u8g2.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    u8g2.drawStr(45, 52, "Schedule");

    u8g2.drawRBox(19, 15, 92, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    u8g2.drawStr(45, 28, "Auto");
  } else {
    u8g2.drawRFrame(19, 15, 92, 19, 5);
    u8g2.drawXBMP(23, 17, 14, 16, image_menu_settings_sliders_square_bits);
    u8g2.drawStr(45, 28, "Auto");

    u8g2.drawRBox(19, 39, 92, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(22, 41, 15, 16, image_clock_quarters_bits);
    u8g2.drawStr(45, 52, "Schedule");
  }
  u8g2.sendBuffer();
}

void viewEnterSchedule(uint8_t days, uint8_t hours, uint8_t mins, uint8_t selecter) {
  char daysString[3], hoursString[3], minsString[3];

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_5x8_tr);
  u8g2.drawStr(87, 32, "min");
  if (selecter == 2) {
    u8g2.drawLine(73, 34, 83, 34);
  }
  sprintf(minsString, "%u", mins);
  u8g2.drawStr(74, 32, minsString);

  u8g2.drawStr(63, 32, "h");
  if (selecter == 1) {
    u8g2.drawLine(49, 34, 59, 34);
  }
  sprintf(hoursString, "%u", hours);
  u8g2.drawStr(50, 32, hoursString);

  u8g2.drawStr(39, 32, "d");
  if (!selecter) {
    u8g2.drawLine(25, 34, 35, 34);
  }
  sprintf(daysString, "%u", days);
  u8g2.drawStr(26, 32, daysString);

  if (selecter == 3) {
    u8g2.drawButtonUTF8(48, 57, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Accept");
  } else {
    u8g2.drawButtonUTF8(48, 57, U8G2_BTN_BW1, 0, 2, 2, "Accept");
  }

  u8g2.drawStr(23, 9, "Irrigation every");

  u8g2.sendBuffer();
}

void viewCongrulacionInitialConfig() {
  static const unsigned char image_hand_thumbs_up_bits[] U8X8_PROGMEM = { 0x00, 0x08, 0x00, 0x14, 0x00, 0x14, 0x00, 0x12, 0x00, 0x0a, 0x00, 0x09, 0x80, 0x7c, 0x5f, 0xc0, 0x31, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x11, 0xc0, 0x11, 0xa0, 0x15, 0x40, 0x71, 0x60, 0x9f, 0x3f };

  u8g2.clearBuffer();

  u8g2.drawXBMP(96, 20, 16, 16, image_hand_thumbs_up_bits);

  u8g2.setFont(u8g2_font_helvB08_tr);
  u8g2.drawStr(20, 33, "configured");
  u8g2.drawStr(13, 22, "Device");
  u8g2.drawStr(36, 45, "Enjoy !!!");

  u8g2.sendBuffer();

  delay(1300);
}

void viewMainMenu(uint8_t selecter) {
  static const unsigned char image_menu_settings_gear_bits[] U8X8_PROGMEM = { 0xc0, 0x03, 0x48, 0x12, 0x34, 0x2c, 0x02, 0x40, 0xc4, 0x23, 0x24, 0x24, 0x13, 0xc8, 0x11, 0x88, 0x11, 0x88, 0x13, 0xc8, 0x24, 0x24, 0xc4, 0x23, 0x02, 0x40, 0x34, 0x2c, 0x48, 0x12, 0xc0, 0x03 };
  static const unsigned char image_weather_wind_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x11, 0x20, 0x22, 0x20, 0x22, 0x00, 0x22, 0x00, 0x11, 0xff, 0x4c, 0x00, 0x00, 0xb5, 0x41, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x80, 0x04, 0x00, 0x03 };
  static const unsigned char image_plant_bits[] U8X8_PROGMEM = { 0x00, 0xc0, 0x00, 0xf0, 0x04, 0xf8, 0x0e, 0xfc, 0x1f, 0xfc, 0x3f, 0x7e, 0x3f, 0x7e, 0x3f, 0x3e, 0x1e, 0x0f, 0x0c, 0x03, 0x08, 0x01, 0x10, 0x01, 0xa0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00 };

  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(50, 9, "Menu");

  u8g2.setDrawColor(1);
  if (!selecter) {
    u8g2.drawRFrame(65, 38, 53, 20, 8);
    u8g2.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    u8g2.drawRFrame(10, 38, 52, 20, 8);
    u8g2.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);

    u8g2.drawRBox(10, 14, 108, 20, 8);
    u8g2.setDrawColor(2);
    u8g2.drawStr(37, 28, "Review");
    u8g2.drawXBMP(14, 16, 16, 16, image_plant_bits);
  } else if (selecter == 1) {
    u8g2.drawRFrame(10, 14, 108, 20, 8);
    u8g2.drawStr(37, 28, "Review");
    u8g2.drawXBMP(14, 16, 16, 16, image_plant_bits);

    u8g2.drawRFrame(65, 38, 53, 20, 8);
    u8g2.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);

    u8g2.drawRBox(10, 38, 52, 20, 8);
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);
  } else if (selecter == 2) {
    u8g2.drawRFrame(10, 38, 52, 20, 8);
    u8g2.drawXBMP(28, 39, 15, 16, image_weather_wind_bits);

    u8g2.drawRFrame(10, 14, 108, 20, 8);
    u8g2.drawStr(37, 28, "Review");
    u8g2.drawXBMP(14, 16, 16, 16, image_plant_bits);

    u8g2.drawRBox(65, 38, 53, 20, 8);
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(83, 40, 16, 16, image_menu_settings_gear_bits);
  }

  u8g2.sendBuffer();
}

void viewReview(uint8_t page) {
  u8g2.clearBuffer();
  if (autoMode) {
    u8g2.drawFilledEllipse(62, 58, 2, 2);

    u8g2.setFont(u8g2_font_5x8_tr);
    u8g2.drawStr(74, 50, "min");
    u8g2.drawStr(62, 50, "34");
    u8g2.drawStr(54, 50, "h");
    u8g2.drawStr(42, 50, "15");
    u8g2.drawStr(34, 50, "d");
    u8g2.drawStr(21, 50, "12");
    u8g2.drawLine(25, 38, 100, 38);
    u8g2.drawStr(26, 36, "Last irrigation");
    u8g2.drawStr(36, 22, "Auto");
    u8g2.drawLine(6, 23, 29, 23);
    u8g2.drawStr(7, 22, "Mode:");
    u8g2.drawStr(92, 50, "ago");
  } else {
    if (!page) {
      u8g2.drawFilledEllipse(56, 58, 2, 2);
      u8g2.drawEllipse(66, 58, 2, 2);

      u8g2.setFont(u8g2_font_5x8_tr);
      u8g2.drawStr(92, 50, "ago");
      u8g2.drawStr(74, 50, "min");
      u8g2.drawStr(62, 50, "34");
      u8g2.drawStr(54, 50, "h");
      u8g2.drawStr(42, 50, "15");
      u8g2.drawStr(34, 50, "d");
      u8g2.drawStr(21, 50, "12");
      u8g2.drawLine(25, 38, 100, 38);
      u8g2.drawStr(26, 36, "Last irrigation");
      u8g2.drawStr(36, 22, "Schedule");
      u8g2.drawLine(6, 23, 29, 23);
      u8g2.drawStr(7, 22, "Mode:");
    } else if (page == 1) {
      u8g2.drawEllipse(56, 58, 2, 2);
      u8g2.drawFilledEllipse(66, 58, 2, 2);

      u8g2.setFont(u8g2_font_5x8_tr);
      u8g2.drawStr(89, 50, "min");
      u8g2.drawStr(77, 50, "34");
      u8g2.drawStr(69, 50, "h");
      u8g2.drawStr(57, 50, "15");
      u8g2.drawStr(49, 50, "d");
      u8g2.drawStr(36, 50, "12");
      u8g2.drawStr(22, 50, "in");
      u8g2.drawLine(25, 38, 100, 38);
      u8g2.drawStr(26, 36, "Next irrigation");
      u8g2.drawStr(36, 22, "Schedule");
      u8g2.drawLine(6, 23, 29, 23);
      u8g2.drawStr(7, 22, "Mode:");
    }
  }
  u8g2.setFont(u8g2_font_helvB08_tr);
  u8g2.drawStr(45, 10, "Review");
  u8g2.sendBuffer();
}

void viewManualMode(uint8_t selecter, bool animation) {
  static const unsigned char image_weather_humidity_bits[] U8X8_PROGMEM = { 0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x70, 0x00, 0x78, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfc, 0x01, 0x7e, 0x03, 0xfe, 0x02, 0xff, 0x06, 0xff, 0x07, 0xfe, 0x03, 0xfe, 0x03, 0xfc, 0x01, 0xf0, 0x00 };
  static const unsigned char image_weather_humidity_white_bits[] U8X8_PROGMEM = { 0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x50, 0x00, 0x48, 0x00, 0x88, 0x00, 0x04, 0x01, 0x04, 0x01, 0x82, 0x02, 0x02, 0x03, 0x01, 0x05, 0x01, 0x04, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x01, 0xf0, 0x00 };
  static uint8_t animationFrame = 0;

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_5x7_tr);
  if (selecter == 1) {
    u8g2.drawButtonUTF8(54, 59, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, "Back");
  } else {
    u8g2.drawButtonUTF8(54, 59, U8G2_BTN_BW1, 0, 2, 2, "Back");
  }

  if (!selecter && animation) {
    animationFrame++;
    if (animationFrame > 2) {
      animationFrame = 0;
    }
  }

  switch (animationFrame) {
    case 0:
      u8g2.drawXBMP(98, 12, 11, 16, image_weather_humidity_bits);
      u8g2.drawXBMP(85, 23, 11, 16, image_weather_humidity_white_bits);
      u8g2.drawXBMP(97, 35, 11, 16, image_weather_humidity_white_bits);
      break;
    case 1:
      u8g2.drawXBMP(98, 12, 11, 16, image_weather_humidity_white_bits);
      u8g2.drawXBMP(85, 23, 11, 16, image_weather_humidity_bits);
      u8g2.drawXBMP(97, 35, 11, 16, image_weather_humidity_white_bits);
      break;
    case 2:
      u8g2.drawXBMP(98, 12, 11, 16, image_weather_humidity_white_bits);
      u8g2.drawXBMP(85, 23, 11, 16, image_weather_humidity_white_bits);
      u8g2.drawXBMP(97, 35, 11, 16, image_weather_humidity_bits);
  }

  u8g2.drawStr(7, 45, "irrigation");
  u8g2.drawStr(26, 35, "to");
  if (!selecter) {
    u8g2.drawLine(44, 22, 52, 22);
    u8g2.drawLine(8, 22, 16, 22);
  }
  u8g2.drawStr(21, 25, "Hold");

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(30, 9, "Manual mode");

  u8g2.sendBuffer();
}

void viewSettings(uint8_t selecter) {
  if (autoMode) {
    viewSettingsAutoMode(selecter);
  } else {
    viewSettingsScheduleMode(selecter);
  }
}

void viewSettingsAutoMode(uint8_t selecter) {
  static const unsigned char image_weather_wind_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x11, 0x20, 0x22, 0x20, 0x22, 0x00, 0x22, 0x00, 0x11, 0xff, 0x4c, 0x00, 0x00, 0xb5, 0x41, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x80, 0x04, 0x00, 0x03 };
  static const unsigned char image_menu_settings_sliders_square_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xff, 0x33, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00 };
  static const unsigned char image_weather_humidity_bits[] U8X8_PROGMEM = { 0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x70, 0x00, 0x78, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfc, 0x01, 0x7e, 0x03, 0xfe, 0x02, 0xff, 0x06, 0xff, 0x07, 0xfe, 0x03, 0xfe, 0x03, 0xfc, 0x01, 0xf0, 0x00 };
  static const unsigned char image_arrow_curved_left_down_bits[] U8X8_PROGMEM = { 0x18, 0x08, 0x1f, 0x1e, 0x18, 0x03, 0x1c };

  u8g2.clearBuffer();

  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(39, 9, "Settings");

  u8g2.setDrawColor(1);
  u8g2.drawLine(123, 3, 123, 60);

  if (!selecter) {
    u8g2.drawBox(121, 6, 5, 9);

    u8g2.drawRFrame(9, 40, 106, 19, 5);
    u8g2.drawStr(32, 52, "Change power");
    u8g2.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);

    u8g2.drawRBox(9, 14, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 28, "Change mode");
    u8g2.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);
  } else if (selecter == 1) {
    u8g2.drawBox(121, 6, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 28, "Change mode");
    u8g2.drawXBMP(13, 17, 14, 16, image_menu_settings_sliders_square_bits);

    u8g2.drawRBox(9, 40, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 52, "Change power");
    u8g2.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
  } else if (selecter == 2) {
    u8g2.drawBox(121, 27, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 26, "Change power");
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    u8g2.drawRBox(9, 40, 106, 19, 4);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 52, "Change ml");
    u8g2.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
  } else if (selecter == 3) {
    u8g2.drawBox(121, 49, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 28, "Change ml");
    u8g2.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    u8g2.drawRBox(9, 40, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 52, "Back");
    u8g2.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }

  u8g2.sendBuffer();
}

void viewSettingsScheduleMode(uint8_t selecter) {
  static const unsigned char image_clock_quarters_bits[] U8X8_PROGMEM = { 0xe0, 0x03, 0x98, 0x0c, 0x84, 0x10, 0x02, 0x20, 0x82, 0x20, 0x81, 0x40, 0x81, 0x40, 0x87, 0x70, 0x01, 0x41, 0x01, 0x42, 0x02, 0x20, 0x02, 0x20, 0x84, 0x10, 0x98, 0x0c, 0xe0, 0x03, 0x00, 0x00 };
  static const unsigned char image_menu_settings_sliders_square_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xff, 0x33, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0xf3, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00 };
  static const unsigned char image_weather_wind_bits[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x11, 0x20, 0x22, 0x20, 0x22, 0x00, 0x22, 0x00, 0x11, 0xff, 0x4c, 0x00, 0x00, 0xb5, 0x41, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x80, 0x04, 0x00, 0x03 };
  static const unsigned char image_weather_humidity_bits[] U8X8_PROGMEM = { 0x20, 0x00, 0x20, 0x00, 0x30, 0x00, 0x70, 0x00, 0x78, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfc, 0x01, 0x7e, 0x03, 0xfe, 0x02, 0xff, 0x06, 0xff, 0x07, 0xfe, 0x03, 0xfe, 0x03, 0xfc, 0x01, 0xf0, 0x00 };
  static const unsigned char image_arrow_curved_left_down_bits[] U8X8_PROGMEM = { 0x18, 0x08, 0x1f, 0x1e, 0x18, 0x03, 0x1c };

  u8g2.clearBuffer();

  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(39, 9, "Settings");

  u8g2.setDrawColor(1);

  u8g2.drawLine(123, 3, 123, 60);

  if (!selecter) {
    u8g2.drawBox(121, 6, 5, 9);

    u8g2.drawRFrame(9, 40, 106, 19, 5);
    u8g2.setFont(u8g2_font_5x8_tr);
    u8g2.drawStr(32, 52, "Change schedule");
    u8g2.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);

    u8g2.drawRBox(9, 14, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.setFont(u8g2_font_6x10_tr);
    u8g2.drawStr(32, 27, "Change mode");
    u8g2.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);
  } else if (selecter == 1) {
    u8g2.drawBox(121, 6, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 27, "Change mode");
    u8g2.drawXBMP(13, 16, 14, 16, image_menu_settings_sliders_square_bits);

    u8g2.drawRBox(9, 40, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.setFont(u8g2_font_5x8_tr);
    u8g2.drawStr(32, 52, "Change schedule");
    u8g2.drawXBMP(12, 42, 15, 16, image_clock_quarters_bits);
  } else if (selecter == 2) {
    u8g2.drawBox(121, 16, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.setFont(u8g2_font_5x8_tr);
    u8g2.drawStr(32, 26, "Change schedule");
    u8g2.drawXBMP(12, 16, 15, 16, image_clock_quarters_bits);

    u8g2.drawRBox(9, 40, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.setFont(u8g2_font_6x10_tr);
    u8g2.drawStr(32, 52, "Change power");
    u8g2.drawXBMP(12, 40, 15, 16, image_weather_wind_bits);
  } else if (selecter == 3) {
    u8g2.drawBox(121, 35, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 26, "Change power");
    u8g2.setDrawColor(2);
    u8g2.drawXBMP(12, 14, 15, 16, image_weather_wind_bits);

    u8g2.drawRBox(9, 40, 106, 19, 4);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 52, "Change ml");
    u8g2.drawXBMP(14, 41, 11, 16, image_weather_humidity_bits);
  } else if (selecter == 4) {
    u8g2.drawBox(121, 49, 5, 9);

    u8g2.drawRFrame(9, 14, 106, 19, 5);
    u8g2.drawStr(32, 28, "Change ml");
    u8g2.drawXBMP(14, 16, 11, 16, image_weather_humidity_bits);

    u8g2.drawRBox(9, 40, 106, 19, 5);
    u8g2.setDrawColor(2);
    u8g2.drawStr(32, 52, "Back");
    u8g2.drawXBMP(16, 47, 5, 7, image_arrow_curved_left_down_bits);
  }
  u8g2.sendBuffer();
}
