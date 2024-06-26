#include "global.h"

Pump::Pump() = default;

void Pump::begin()
{
  pinMode(PUMP, OUTPUT);
  this->workingTimer.setTimerMode();
  this->isActive = false;
}

bool Pump::isWorkingDuringWorkPeriod()
{
  return this->workingTimer.active();
}

uint32_t Pump::getLastUseTime() const
{
  return this->lastUseTime;
}

void Pump::updateLastUseTime()
{
  if (!this->isWorkingDuringWorkPeriod())
  {
    this->lastUseTime = millis() - this->lastUseTime;
  }
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
  if (!isActive)
  {
    digitalWrite(PUMP, HIGH);
    isActive = true;
    this->lastUseTime = millis();
  }
}

void Pump::putOff()
{
  if (isActive)
  {
    digitalWrite(PUMP, LOW);
    isActive = false;
  }
}