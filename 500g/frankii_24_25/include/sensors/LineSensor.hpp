#ifndef LINESENSOR_HPP
#define LINESENSOR_HPP

#include <Arduino.h>


class LineSensor {

public:
  LineSensor(uint8_t pin);

  uint32_t get_raw_value();
  uint32_t get_filtered_value();

};

#endif
