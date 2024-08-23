#include "../../include/sensors/LineSensor.hpp"

class LineSensor {

public: 
  LineSensor::LineSensor(uint8_t pin) {
    this->pin = pin;
  }

  uint32_t LineSensor::get_raw_value() {
    return analogRead(pin);
  }

  uint32_t LineSensor::get_filtered_value() {

  }

private:
  uint8_t pin;

};

