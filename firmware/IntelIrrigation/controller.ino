#include "global.h"

volatile bool sleepAutoMode = false;

void isrButton()
{
  if (power.inSleep())
  {
    power.wakeUp();
    if (configuration.autoMode)
    {
      sleepAutoMode = false;
    }
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
    viewMainMenu();
    if(!configuration.autoMode){
      scheduleTimer.setTime(configuration.schedule[0] * 24 * 60 * 60 * 1000UL +
                          configuration.schedule[1] * 60 * 60 * 1000UL +
                          configuration.schedule[2] * 60 * 1000UL);
      scheduleTimer.start();
    }
  }
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
  
  if (pump.isWorking() || configuration.autoMode)
  {
    if (isDryGround())
    {
      pump.doWorkDuringWorkPeriod();
    }
  }
  else
  {
    if (pump.isWorking() || scheduleTimer.tick())
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