#include "pageManager.h"

void mainMenu() {
  static uint32_t tmr;

  if (encoder.turn()) {
    selector += 1 * encoder.dir();
    if (selector > MAX_SELECTOR_MAIN_MENU) {
      selector = 0;
    } else if (selector < 0) {
      selector = MAX_SELECTOR_MAIN_MENU;
    }
  }
}

void settings() {
  static uint32_t tmr;

  if (encoder.turn()) {
    selector += 1 * encoder.dir();
    if (selector > MAX_SELECTOR_SETTINGS) {
      selector = 0;
    } else if (selector < 0) {
      selector = MAX_SELECTOR_SETTINGS;
    }
  }
}

void manualMode() {
  static uint32_t tmr;
  static bool holding = false;

  if (encoder.turn()) {
    selector = !selector;
    holding = false;
  }

  if (encoder.holding()) {
    holding = true;
  }

  if (encoder.hold()) {
    holding = false;
  }
}

void setupConfigurationPages() {
  viewEnterPower();
  for (uint8_t step = 1; step;) {
    if (encoder.tick()) {
      // -- Value controller --
      switch (step) {
        case 1:
          controlEnterPower();
          break;
        case 2:
          controlEnterPowerRange();
          break;
        case 3:
          controlEnterMlLiquid();
          break;
        case 4:
          controlChooseMode();
          break;
        case 5:
          controlEnterSchedule();
      }

      // -- Router --
      if (encoder.hold()) {
        if (step == 4) {
          // Mode selection
          if (!selector) {
            step = 0;
            configuration.autoMode = true;
          } else {
            step++;
            configuration.autoMode = false;
            selector = 1;
          }
        } else if (step == 1 && selector == SELECT_RANGE_POWER) {
          // Button "Range"
          step++;
          selector = SELECT_MAX_POWER;
        } else if (!selector) {
          // Button "Accept"
          switch (step) {
            case 1:
              step = 3;
              break;
            case 2:
              step++;
              configuration.powerValue = (minPowerValue + maxPowerValue) / 2;
              break;
            case 3:
              step++;
              break;
            case 5: step = 0;
          }
          step == 4 ? selector = 0 : selector = 1;
        }
      }

      // -- Display --
      if (millis() - displayTimer >= DISPLAY_TIMER) {
        switch (step) {
          case 1:
            viewEnterPower();
            break;
          case 2:
            viewEnterPowerRange(minPowerValue, maxPowerValue);
            break;
          case 3:
            viewEnterMlLiquid();
            break;
          case 4:
            viewChooseMode();
            break;
          case 5: viewEnterSchedule();
        }
      }
    }
  }
  viewCongratulationsInitialConfiguration();
  selector = 0;
  viewMainMenu();
}

// --------------
// -- Controls --
// --------------

void controlEnterPower() {
  if (selector == SELECT_POWER && encoder.turn()) {
    configuration.powerValue += (encoder.pressing() ? 10 : 1) * encoder.dir();
    if (configuration.powerValue > MAX_POWER) {
      configuration.powerValue = 0;
    }
  }

  if (encoder.click()) {
    selector++;
    if (selector > MAX_SELECTOR_POWER) {
      selector = 0;
    }
  }
}

void controlEnterPowerRange() {
  if (selector && encoder.turn()) {
    selector == SELECT_MIN_POWER ? minPowerValue += (encoder.pressing() ? 10 : 1) * encoder.dir() : maxPowerValue += (encoder.pressing() ? 10 : 1) * encoder.dir();
    if (maxPowerValue > MAX_POWER) {
      maxPowerValue = 0;
    }
    if (minPowerValue > maxPowerValue) {
      minPowerValue = maxPowerValue;
    }
  }

  if (encoder.click()) {
    selector++;
    if (selector > MAX_SELECTOR_POWER_RANGE) {
      selector = 0;
    }
  }
}

void controlEnterMlLiquid() {
  if (selector && encoder.turn()) {
    configuration.mlLiquidValue += (encoder.pressing() ? 100 : 5) * encoder.dir();
    if (configuration.mlLiquidValue > MAX_ML_LIQUID) {
      configuration.mlLiquidValue = 0;
    }
  }

  if (encoder.click()) {
    selector++;
    if (selector > MAX_SELECTOR_ML_LIQUID) {
      selector = 0;
    }
  }
}

void controlChooseMode() {
  if (encoder.turn()) {
    selector = !selector;
  }
}

void controlEnterSchedule() {
  if (selector && encoder.turn()) {
    switch (selector) {
      case SELECT_DAYS_SCHEDULE:
        configuration.schedule[0] += (encoder.pressing() ? 5 : 1) * encoder.dir();
        break;
      case SELECT_HOURS_SCHEDULE:
        configuration.schedule[1] += (encoder.pressing() ? 5 : 1) * encoder.dir();
        break;
      case SELECT_MINS_SCHEDULE:
        configuration.schedule[2] += (encoder.pressing() ? 5 : 1) * encoder.dir();
    }
    if (configuration.schedule[0] > MAX_DAYS_SCHEDULE) {
      configuration.schedule[0] = 0;
    }
    if (configuration.schedule[1] > MAX_HOURS_SCHEDULE) {
      configuration.schedule[1] = 0;
      configuration.schedule[0]++;
    }
    if (configuration.schedule[2] > MAX_MINS_SCHEDULE) {
      configuration.schedule[2] = 0;
      configuration.schedule[1]++;
    }
  }

  if (encoder.click()) {
    selector++;
    if (selector > MAX_SELECTOR_SCHEDULE) {
      selector = 0;
    }
  }
}