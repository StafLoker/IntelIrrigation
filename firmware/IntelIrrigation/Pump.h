#pragma once

class Pump {
private:
  uint16_t power;       // L/h
  uint32_t workPeriod;  // ms

public:
  Pump();

  Pump(uint16_t);

  Pump(uint16_t, uint16_t);

  void setPower(uint16_t);

  void calculateWorkPeriod(uint16_t);

  uint16_t getPower() const;

  uint32_t getWorkPeriod() const;

  void doWorkDuringWorkPeriod();

  void putOn();

  void putOff();
};
