#include "global.h"

void setupConfigurationPages()
{
  page = PAGE_ENTER_POWER;
  viewEnterPower();
  while (!configuration.configured)
  {
    if (encoder.tick())
    {
      // -- Value controller --
      switch (page)
      {
      case PAGE_CHOOSE_MODE:
        controlChooseMode();
        break;
      case PAGE_ENTER_SCHEDULE:
        controlEnterSchedule();
        break;
      case PAGE_ENTER_POWER:
        controlEnterPower();
        break;
      case PAGE_ENTER_POWER_RANGE:
        controlEnterPowerRange();
        break;
      case PAGE_ENTER_ML_LIQUID:
        controlEnterMlLiquid();
      }

      // -- Display --
      if (millis() - displayTimer >= DISPLAY_TIMER)
      {
        switch (page)
        {
        case PAGE_CHOOSE_MODE:
          viewChooseMode();
          break;
        case PAGE_ENTER_SCHEDULE:
          viewEnterSchedule();
          break;
        case PAGE_ENTER_POWER:
          viewEnterPower();
          break;
        case PAGE_ENTER_POWER_RANGE:
          viewEnterPowerRange();
          break;
        case PAGE_ENTER_ML_LIQUID:
          viewEnterMlLiquid();
        }
      }
    }
  }
  viewCongratulationsInitialConfiguration();
  selector = 1;
  page = PAGE_MAIN_MENU;
}

void runMainPages()
{
  // -- Value controller --
  switch (page)
  {
  case PAGE_MAIN_MENU:
    controlMainMenu();
    break;
  case PAGE_REVIEW:
    controlReview();
    break;
  case PAGE_MANUAL_MODE:
    controlManualMode();
    break;
  case PAGE_SETTINGS:
    controlSettings();
    break;
  case PAGE_CHOOSE_MODE:
    controlChooseMode();
    break;
  case PAGE_ENTER_SCHEDULE:
    controlEnterSchedule();
    break;
  case PAGE_ENTER_POWER:
    controlEnterPower();
    break;
  case PAGE_ENTER_POWER_RANGE:
    controlEnterPowerRange();
    break;
  case PAGE_ENTER_ML_LIQUID:
    controlEnterMlLiquid();
  }

  // -- Display --
  if (millis() - displayTimer >= DISPLAY_TIMER)
  {
    switch (page)
    {
    case PAGE_MAIN_MENU:
      viewMainMenu();
      break;
    case PAGE_REVIEW:
      viewReview();
      break;
    case PAGE_MANUAL_MODE:
      viewManualMode();
      break;
    case PAGE_SETTINGS:
      viewSettings();
      break;
    case PAGE_CHOOSE_MODE:
      viewChooseMode();
      break;
    case PAGE_ENTER_SCHEDULE:
      viewEnterSchedule();
      break;
    case PAGE_ENTER_POWER:
      viewEnterPower();
      break;
    case PAGE_ENTER_POWER_RANGE:
      viewEnterPowerRange();
      break;
    case PAGE_ENTER_ML_LIQUID:
      viewEnterMlLiquid();
    }
  }
}

// --------------
// -- Controls --
// --------------

void controlMainMenu()
{
  if (encoder.turn())
  {
    mainSelector += 1 * encoder.dir();
    if (mainSelector > MAX_SELECTOR_MAIN_MENU)
    {
      mainSelector = 0;
    }
    else if (mainSelector < 0)
    {
      mainSelector = MAX_SELECTOR_MAIN_MENU;
    }
  }

  if (encoder.click())
  {
    switch (mainSelector)
    {
    case SELECT_REVIEW_MAIN_MENU:
      page = PAGE_REVIEW;
      selector = 0;
      break;
    case SELECT_MANUAL_MODE_MAIN_MENU:
      page = PAGE_MANUAL_MODE;
      selector = 1;
      break;
    case SELECT_SETTINGS_MAIN_MENU:
      page = PAGE_SETTINGS;
      mainSelector = 0;
    }
  }
}

void controlReview()
{
  if (!configuration.autoMode && encoder.turn())
  {
    selector = !selector;
  }

  if (encoder.hold())
  {
    page = PAGE_MAIN_MENU;
  }
}

void controlManualMode()
{
  if (encoder.turn())
  {
    selector = !selector;
    animationManualMode = false;
  }

  if (selector && encoder.holding())
  {
    pump.putOn();
    animationManualMode = true;
  }

  if (selector && encoder.hold())
  {
    pump.putOff();
    animationManualMode = false;
  }

  if (!selector && encoder.click())
  {
    page = PAGE_MAIN_MENU;
  }
}

void controlSettings()
{
  if (encoder.turn())
  {
    mainSelector += 1 * encoder.dir();
    if (mainSelector > (configuration.autoMode ? MAX_SELECTOR_SETTINGS_AUTO_MODE : MAX_SELECTOR_SETTINGS_SCHEDULE_MODE))
    {
      mainSelector = 0;
    }
    else if (mainSelector < 0)
    {
      mainSelector = configuration.autoMode ? MAX_SELECTOR_SETTINGS_AUTO_MODE : MAX_SELECTOR_SETTINGS_SCHEDULE_MODE;
    }
  }

  if (encoder.click())
  {
    if (configuration.autoMode)
    {
      switch (mainSelector)
      {
      case 0:
        page = PAGE_CHOOSE_MODE;
        break;
      case 1:
        page = PAGE_ENTER_POWER;
        break;
      case 2:
        page = PAGE_ENTER_ML_LIQUID;
        break;
      case 3:
        page = PAGE_MAIN_MENU;
        mainSelector = SELECT_SETTINGS_MAIN_MENU;
      }
    }
    else
    {
      switch (mainSelector)
      {
      case 0:
        page = PAGE_CHOOSE_MODE;
        break;
      case 1:
        page = PAGE_ENTER_SCHEDULE;
        break;
      case 2:
        page = PAGE_ENTER_POWER;
        break;
      case 3:
        page = PAGE_ENTER_ML_LIQUID;
        break;
      case 4:
        page = PAGE_MAIN_MENU;
        mainSelector = SELECT_SETTINGS_MAIN_MENU;
      }
    }
  }
}

void controlEnterPower()
{
  if (selector == SELECT_POWER && encoder.turn())
  {
    configuration.powerValue += (encoder.pressing() ? 10 : 1) * encoder.dir();
    if (configuration.powerValue > MAX_POWER)
    {
      configuration.powerValue = 0;
    }
  }

  if (encoder.click())
  {
    selector++;
    if (selector > MAX_SELECTOR_POWER)
    {
      selector = 0;
    }
  }

  if ((!selector || selector == SELECT_RANGE_POWER) && encoder.hold())
  {
    if (!selector && configuration.configured)
    {
      page = PAGE_SETTINGS;
      selector = 1;
      pump.calculateWorkPeriod(configuration.powerValue, configuration.mlLiquidValue);
      memory.update();
    }
    else if (!selector && !configuration.configured)
    {
      page = PAGE_ENTER_ML_LIQUID;
      pump.calculateWorkPeriod(configuration.powerValue, configuration.mlLiquidValue);
      selector = 1;
    }
    else
    {
      page = PAGE_ENTER_POWER_RANGE;
      selector = SELECT_MAX_POWER;
    }
  }
}

void controlEnterPowerRange()
{
  if (selector && encoder.turn())
  {
    selector == SELECT_MIN_POWER ? configuration.minPowerValue += (encoder.pressing() ? 10 : 1) * encoder.dir() : configuration.maxPowerValue += (encoder.pressing() ? 10 : 1) * encoder.dir();
    if (configuration.maxPowerValue > MAX_POWER)
    {
      configuration.maxPowerValue = 0;
    }
    if (configuration.minPowerValue > configuration.maxPowerValue)
    {
      configuration.minPowerValue = configuration.maxPowerValue;
    }
  }

  if (encoder.click())
  {
    selector++;
    if (selector > MAX_SELECTOR_POWER_RANGE)
    {
      selector = 0;
    }
  }

  if (!selector && encoder.hold())
  {
    if (configuration.configured)
    {
      page = PAGE_SETTINGS;
      memory.update();
    }
    else
    {
      page = PAGE_ENTER_ML_LIQUID;
    }
    configuration.powerValue = (configuration.minPowerValue + configuration.maxPowerValue) / 2;
    pump.calculateWorkPeriod(configuration.powerValue, configuration.mlLiquidValue);
    selector = 1;
  }
}

void controlEnterMlLiquid()
{
  if (selector && encoder.turn())
  {
    configuration.mlLiquidValue += (encoder.pressing() ? 100 : 5) * encoder.dir();
    if (configuration.mlLiquidValue > MAX_ML_LIQUID)
    {
      configuration.mlLiquidValue = 0;
    }
  }

  if (encoder.click())
  {
    selector++;
    if (selector > MAX_SELECTOR_ML_LIQUID)
    {
      selector = 0;
    }
  }

  if (!selector && encoder.hold())
  {
    if (configuration.configured)
    {
      page = PAGE_SETTINGS;
      selector = 1;
      memory.update();
    }
    else
    {
      page = PAGE_CHOOSE_MODE;
    }
    pump.calculateWorkPeriod(configuration.powerValue, configuration.mlLiquidValue);
  }
}

void controlChooseMode()
{
  if (encoder.turn())
  {
    selector = !selector;
  }

  if (encoder.hold())
  {
    if (!selector && configuration.configured)
    {
      configuration.autoMode = true;
      scheduleTimer.stop();
      page = PAGE_SETTINGS;
      memory.update();
    }
    else if (!selector && !configuration.configured)
    {
      configuration.autoMode = true;
      configuration.configured = true;
    }
    else if (selector && configuration.configured)
    {
      configuration.autoMode = false;
      if (!scheduleTimer.active())
      {
        scheduleTimer.start();
      }
      page = PAGE_SETTINGS;
      memory.update();
    }
    else
    {
      configuration.autoMode = false;
      page = PAGE_ENTER_SCHEDULE;
      selector = 1;
    }
  }
}

void controlEnterSchedule()
{
  if (selector && encoder.turn())
  {
    switch (selector)
    {
    case SELECT_DAYS_SCHEDULE:
      configuration.schedule.days += (encoder.pressing() ? 5 : 1) * encoder.dir();
      break;
    case SELECT_HOURS_SCHEDULE:
      configuration.schedule.hours += (encoder.pressing() ? 5 : 1) * encoder.dir();
      break;
    case SELECT_MINS_SCHEDULE:
      configuration.schedule.mins += (encoder.pressing() ? 5 : 1) * encoder.dir();
    }
    if (configuration.schedule.days > MAX_DAYS_SCHEDULE)
    {
      configuration.schedule.days = 0;
    }
    if (configuration.schedule.hours > MAX_HOURS_SCHEDULE)
    {
      configuration.schedule.hours = 0;
      configuration.schedule.days++;
    }
    if (configuration.schedule.mins > MAX_MINS_SCHEDULE)
    {
      configuration.schedule.mins = 0;
      configuration.schedule.hours++;
    }
  }

  if (encoder.click())
  {
    selector++;
    if (selector > MAX_SELECTOR_SCHEDULE)
    {
      selector = 0;
    }
  }

  if (!selector && encoder.hold())
  {
    if (configuration.configured)
    {
      page = PAGE_SETTINGS;
      memory.update();
    }
    else
    {
      configuration.configured = true;
    }
    selector = 1;
    scheduleTimer.setTime(convertScheduleToMs());
    scheduleTimer.start();
  }
}

uint32_t convertScheduleToMs()
{
  return (uint32_t) (configuration.schedule.days * 24 * 60 * 60 * 1000) +
         (configuration.schedule.hours * 60 * 60 * 1000) +
         (configuration.schedule.mins * 60 * 1000);
}