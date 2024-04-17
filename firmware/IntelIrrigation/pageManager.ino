#include "global.h"

void setupConfigurationPages()
{
  viewEnterPower();
  while (!configured)
  {
    if (encoder.tick())
    {
      // -- Value controller --
      switch (page)
      {
      case 4:
        controlChooseMode();
        break;
      case 5:
        controlEnterSchedule();
        break;
      case 6:
        controlEnterPower();
        break;
      case 7:
        controlEnterPowerRange();
        break;
      case 8:
        controlEnterMlLiquid();
      }

      // -- Display --
      if (millis() - displayTimer >= DISPLAY_TIMER)
      {
        switch (page)
        {
        case 4:
          viewChooseMode();
          break;
        case 5:
          viewEnterSchedule();
          break;
        case 6:
          viewEnterPower();
          break;
        case 7:
          viewEnterPowerRange();
          break;
        case 8:
          viewEnterMlLiquid();
        }
      }
    }
  }
  viewCongratulationsInitialConfiguration();
  selector = 1;
  page = 0;
}

void runMainPages()
{
  // -- Value controller --
  switch (page)
  {
  case 0:
    controlMainMenu();
    break;
  case 1:
    controlReview();
    break;
  case 2:
    controlManualMode();
    break;
  case 3:
    controlSettings();
  case 4:
    controlChooseMode();
    break;
  case 5:
    controlEnterSchedule();
    break;
  case 6:
    controlEnterPower();
    break;
  case 7:
    controlEnterPowerRange();
    break;
  case 8:
    controlEnterMlLiquid();
  }

  // -- Display --
  if (millis() - displayTimer >= DISPLAY_TIMER)
  {
    switch (page)
    {
    case 0:
      viewMainMenu();
      break;
    case 1:
      viewReview();
      break;
    case 2:
      viewManualMode(animation);
      break;
    case 3:
      viewSettings();
      break;
    case 4:
      viewChooseMode();
      break;
    case 5:
      viewEnterSchedule();
      break;
    case 6:
      viewEnterPower();
      break;
    case 7:
      viewEnterPowerRange();
      break;
    case 8:
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
    case 0:
      page = 1;
      selector = 0;
      break;
    case 1:
      page = 2;
      selector = 1;
      break;
    case 2:
      page = 3;
      mainSelector = 0;
    }
  }
}

void controlReview()
{
  static bool autoChangePageReview = false;
  static uint32_t timer;
  if (!configuration.autoMode && encoder.turn())
  {
    selector = !selector;
    autoChangePageReview = false;
  }
  if (!configuration.autoMode && encoder.timeout(180000))
  {
    autoChangePageReview = true;
  }
  if (autoChangePageReview && millis() - timer >= 3000)
  {
    selector = !selector;
  }

  if (encoder.hold())
  {
    page = 0;
  }
}

void controlManualMode()
{
  if (encoder.turn())
  {
    selector = !selector;
    animation = false;
  }

  if (selector && encoder.holding())
  {
    pump.putOn();
    animation = true;
  }

  if (selector && encoder.hold())
  {
    pump.putOff();
    animation = false;
  }

  if (!selector && encoder.click())
  {
    page = 0;
  }
}

void controlSettings()
{
  if (encoder.turn())
  {
    mainSelector += 1 * encoder.dir();
    if (mainSelector > (configuration.autoMode ? MAX_SELECTOR_SETTINGS_AUTO_MODE : MAX_SELECTOR_SETTINGS_AUTO_SCHEDULE))
    {
      mainSelector = 0;
    }
    else if (mainSelector < 0)
    {
      mainSelector = configuration.autoMode ? MAX_SELECTOR_SETTINGS_AUTO_MODE : MAX_SELECTOR_SETTINGS_AUTO_SCHEDULE;
    }
  }

  if (encoder.click())
  {
    if (configuration.autoMode)
    {
      switch (mainSelector)
      {
      case 0:
        page = 4;
        break;
      case 1:
        page = 6;
        break;
      case 2:
        page = 8;
        break;
      case 3:
        page = 0;
        mainSelector = 2;
      }
    }
    else
    {
      switch (mainSelector)
      {
      case 0:
        page = 4;
        break;
      case 1:
        page = 5;
        break;
      case 2:
        page = 6;
        break;
      case 3:
        page = 8;
        break;
      case 4:
        page = 0;
        mainSelector = 2;
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
    if (!selector && configured)
    {
      page = 3;
      selector = 1;
      memory.update();
    }
    else if (!selector && !configured)
    {
      page = 8;
      selector = 1;
    }
    else
    {
      page = 7;
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
    if (configured)
    {
      page = 3;
      memory.update();
    }
    else
    {
      page = 8;
    }
    configuration.powerValue = (configuration.minPowerValue + configuration.maxPowerValue) / 2;
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
    if (configured)
    {
      page = 3;
      selector = 1;
      memory.update();
    }
    else
    {
      page = 4;
    }
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
    if (!selector && configured)
    {
      configuration.autoMode = true;
      page = 3;
      memory.update();
    }
    else if (!selector && !configured)
    {
      configuration.autoMode = true;
      configured = true;
    }
    else if (selector && configured)
    {
      configuration.autoMode = false;
      page = 3;
      memory.update();
    }
    else
    {
      configuration.autoMode = false;
      page = 5;
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
      configuration.schedule[0] += (encoder.pressing() ? 5 : 1) * encoder.dir();
      break;
    case SELECT_HOURS_SCHEDULE:
      configuration.schedule[1] += (encoder.pressing() ? 5 : 1) * encoder.dir();
      break;
    case SELECT_MINS_SCHEDULE:
      configuration.schedule[2] += (encoder.pressing() ? 5 : 1) * encoder.dir();
    }
    if (configuration.schedule[0] > MAX_DAYS_SCHEDULE)
    {
      configuration.schedule[0] = 0;
    }
    if (configuration.schedule[1] > MAX_HOURS_SCHEDULE)
    {
      configuration.schedule[1] = 0;
      configuration.schedule[0]++;
    }
    if (configuration.schedule[2] > MAX_MINS_SCHEDULE)
    {
      configuration.schedule[2] = 0;
      configuration.schedule[1]++;
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
    if (configured)
    {
      page = 3;
      memory.update();
    }
    else
    {
      configured = true;
    }
    selector = 1;
  }
}