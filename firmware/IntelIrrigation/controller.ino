#include "global.h"

void startMain() {
  configuration.configured = EepromManager::loadConfiguration();
  viewLogoPage();
}

void setupConfiguration() {
  page = 6;
  setupConfigurationPages();
  pump.setPower(configuration.powerValue);
  pump.calculateWorkPeriod(configuration.mlLiquidValue);
  EepromManager::writeInitialConfiguration();
}

void runMain() {
  if (configuration.autoMode) {
    if (isDryGround()) {
      pump.doWorkDuringWorkPeriod();
    }
  }
  runMainPages();
}

bool isDryGround() {
  return analogRead(SOIL_MOISTURE_SENSOR) > DRY_SIGNAL;
}