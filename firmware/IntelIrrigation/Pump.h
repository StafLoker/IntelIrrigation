#pragma once

#include "global.h"

/*
  -- Pump.h --
  Include declaration of Pump class to manage water pump.
*/

class Pump
{
private:
  TimerMs workingTimer;

public:
  Pump();

  void begin();

  bool isWorkingDuringWorkPeriod();

  /*
    @param power uint16_t
    @param mlLiquid uint16_t
  */
  void calculateWorkPeriod(uint16_t, uint16_t);

  void doWorkDuringWorkPeriod();

  void putOn();

  void putOff();
};
