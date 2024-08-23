#include "../../include/sensors/LineSensor.hpp"

class LineSensor {

private:
  uint8_t pin;

public: 
  LineSensor(uint8_t pin) {
    this->pin = pin;
  }

};

