#include "global.h"

Pump::Pump() = default;

Pump::Pump(uint16_t power)
{
  this->power = power;
}

void Pump::setPower(uint16_t power)
{
  this->power = power;
}

void Pump::calculateWorkPeriod(uint16_t mlLiquid)
{
  this->workPeriod = (mlLiquid / this->power) * 3600 * 1000;
}

uint16_t Pump::getPower() const
{
  return this->power;
}

uint32_t Pump::getWorkPeriod() const
{
  return this->workPeriod;
}

bool Pump::isWorking() const
{
  return this->working;
}

void Pump::begin()
{
  pinMode(PUMP, OUTPUT);
}

void Pump::doWorkDuringWorkPeriod()
{
  static uint32_t timer;
  static bool flag = true;
  this->putOn();
  if (flag && millis() - timer >= this->workPeriod)
  {
    flag = false;
    this->putOff();
  }
  if (!flag)
  {
    flag = true;
  }
}

void Pump::putOn()
{
  digitalWrite(PUMP, HIGH);
  this->working = true;
}

void Pump::putOff()
{
  digitalWrite(PUMP, LOW);
  this->working = false;
}