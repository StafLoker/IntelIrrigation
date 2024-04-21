#include "global.h"

Pump::Pump() = default;

void Pump::begin()
{
  pinMode(PUMP, OUTPUT);
  this->workingTimer.setTimerMode();
}

bool Pump::isWorking()
{
  return this->workingTimer.active();
}

void Pump::calculateWorkPeriod(uint16_t power, uint16_t mlLiquid)
{
  this->workingTimer.setTime((mlLiquid / power) * 3600 * 1000);
}

void Pump::doWorkDuringWorkPeriod()
{
  if (!this->workingTimer.active())
  {
    this->putOn();
    this->workingTimer.start();
  }
  
  if (this->workingTimer.tick())
  {
    this->putOff();
  }
}

void Pump::putOn()
{
  digitalWrite(PUMP, HIGH);
}

void Pump::putOff()
{
  digitalWrite(PUMP, LOW);
}