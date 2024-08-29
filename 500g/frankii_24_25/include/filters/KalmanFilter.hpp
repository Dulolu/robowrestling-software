#ifndef KALMANFILTER_HPP 
#define KALMANFILTER_HPP

#include <Arduino.h> 


class KalmanFilter {

  public:
    KalmanFilter(float initial_estimate, float initial_error_covariance, float process_noise, float measurement_noise);

    float update(float measurement);  

  private:

};

#endif 
