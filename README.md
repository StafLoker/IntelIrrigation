# IntelIrrigation `v1.0.0`

"IntelIrrigation" is an Arduino based project. Its goal is to create automatic flower irrigation.

## Main Features

- Two modes of operation, "Automatic" and "Schedule".
  - "Automatic" - according to the sensor readings the watering is switched on.
  - "Schedule" - set a schedule (example: every 2 days, 5 hours and 30 minutes) according to which the watering is switched on.
- Initial configuration of the device during the first start of the device.
- The configuration is stored in the EEPROM memory.
- Automatic sleep mode (both modes).
- Programme menus:
  - Settings. All parameters set during initial configuration of the device can be changed.
  - Review. Shows the current operating mode and the elapsed time since the last watering. Also how long it will take for the next watering to take place.
  - Manual mode. Useful if you need to pump up the liquid to the flower (recommended).
- The programme interface is clear and intuitive.

## Components

- Arduino Nano
- SSD1306 128x64 I2C OLED display
- Rotary encoder ([Encoder](https://a.aliexpress.com/_ExFSOl7)).
- Water pump, power 70-120 L/H and DC 3-5V ([Pump](https://a.aliexpress.com/_EJphP6b))
- MOSFET Trigger Switch Drive Module
- Soil moisture sensor

## Libraries

- [U8g2](https://github.com/olikraus/u8g2)
- [EncButton](https://github.com/GyverLibs/EncButton)
- [GyverPower](https://github.com/GyverLibs/GyverPower)
- [EEManager](https://github.com/GyverLibs/EEManager)
- [TimerMs](https://github.com/GyverLibs/TimerMs)
