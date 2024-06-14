#include "global.h"

void isrButton()
{
  if (power.inSleep())
  {
    power.wakeUp();
    if (configuration.autoMode)
    {
      sleepAutoMode = false;
    }
    viewPage();
  }
}

void startMain()
{
  viewLogoPage();
  memory.begin(0, INIT_KEY);
  if (!configuration.configured)
  {
    setupConfiguration();
  }
  else
  {
    pump.calculateWorkPeriod(configuration.powerValue, configuration.mlLiquidValue);
    if (!configuration.autoMode)
    {
      scheduleTimer.setTime(convertScheduleToMs());
      scheduleTimer.start();
    }
  }
  viewMainMenu();
}

void setupConfiguration()
{
  setupConfigurationPages();
  memory.update();
}

void runMain()
{
  bool encoderTick = encoder.tick();
  memory.tick();
  pump.updateLastUseTime();

  if (configuration.autoMode)
  {
    if (pump.isWorkingDuringWorkPeriod() || isDryGround())
    {
      pump.doWorkDuringWorkPeriod();
    }
  }
  else
  {
    if (pump.isWorkingDuringWorkPeriod() || scheduleTimer.tick())
    {
      pump.doWorkDuringWorkPeriod();
    }
  }

  if (encoderTick)
  {
    runMainPages();
  }

  if (encoder.timeout(TIMER_1_MIN))
  {
    display.clearDisplay();
    if (configuration.autoMode)
    {
      sleepAutoMode = true;
    }
    else
    {
      power.sleepDelay(scheduleTimer.timeLeft());
    }
  }

  if (sleepAutoMode)
  {
    power.sleep(SLEEP_4096MS);
  }
}

bool isDryGround()
{
  return analogRead(SOIL_MOISTURE_SENSOR) > DRY_SIGNAL;
}