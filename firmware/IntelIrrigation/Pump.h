#pragma once

/*
  -- Pump.h --
  Include declaration of Pump class to manage water pump.
*/

class Pump
{
private:
  uint16_t power;      // L/h
  uint32_t workPeriod; // ms
  bool working;

public:
  Pump();

  /*
    @param power uint16_t
  */
  Pump(uint16_t);

  /*
    @param power uint16_t
  */
  void setPower(uint16_t);

  /*
    @param mlLiquid uint16_t
  */
  void calculateWorkPeriod(uint16_t);

  uint16_t getPower() const;

  uint32_t getWorkPeriod() const;

  bool isWorking() const;

  void begin();

  void doWorkDuringWorkPeriod();

  void putOn();

  void putOff();
};
