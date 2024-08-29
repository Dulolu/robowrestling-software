#include "../../include/sensors/LineSensor.hpp"
#include "../../include/filters/KalmanFilter.hpp"

class LineSensor {

public: 
  LineSensor::LineSensor(uint8_t pin) {
    this->pin = pin;
  }

  LineSensor::LineSensor(uint8_t pin, KalmanFilter kalmanfilter) {
    this->pin = pin;
    this->kalmanfilter = new KalmanFilter(400.0, 1.0, 0.1, 5.0);
  }

  uint32_t LineSensor::get_raw_value() {
    return analogRead(pin);
  }

  uint32_t LineSensor::get_filtered_value() {
    uint32_t raw_value = analogRead(pin);
    float filtered_value = kalmanfilter.update(static_cast<float>(raw_value));

    return static_cast<uint32_t>(filtered_value);
  }

private:
  uint8_t pin;
  KalmanFilter* kalmanfilter;  
};
