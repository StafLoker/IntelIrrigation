#include "global.h"

void startMain()
{
  viewLogoPage();
  configured = !memory.begin(0, INIT_KEY);
  if (!configured)
  {
    setupConfiguration();
  }
  else
  {
    viewMainMenu();
  }
}

void setupConfiguration()
{
  page = 6;
  setupConfigurationPages();
  pump.setPower(configuration.powerValue);
  pump.calculateWorkPeriod(configuration.mlLiquidValue);
  memory.update();
}

void runMain()
{
  memory.tick();
  bool encoderTick = encoder.tick();
  if (configuration.autoMode)
  {
    if (isDryGround())
    {
      pump.doWorkDuringWorkPeriod();
    }
  }
  if (encoderTick)
  {
    runMainPages();
  }
}

bool isDryGround()
{
  return analogRead(SOIL_MOISTURE_SENSOR) > DRY_SIGNAL;
}