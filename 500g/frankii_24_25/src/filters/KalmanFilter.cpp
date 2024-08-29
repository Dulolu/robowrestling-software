#include "../include/filters/KalmanFilter.hpp"

class KalmanFilter {

  public:

    KalmanFilter(float initial_estimate, float initial_error_covariance, float process_noise, float measurement_noise) {
      this->x_est = initial_estimate;
      this->P = initial_error_covariance;
      this->Q = process_noise;
      this->R = measurement_noise;
    }

    float update(float measurement) {
      // prediction step
      // add how much x_est will change to uncertainty of x_est 
      // increasing uncertainty by Q
      P += Q;

      // update step
      // K is the Kalman Gain, calculates how much to trust the new measurement vs the previous estimate
      // K = 1, trust the new sensor measurement 
      // K = 0, trust the old estimate more
      // if P is big and R is small, K will be closer to 1 
      // to further elaborate, if uncertainty of estimate is higher and trust factor of new sensor measurement is low, trust the new sensor measurement 
      float K = P / (P + R); 
      x_est = x_est + K * (measurement - x_est); 
      P = (1 - K) * P;

      return x_est;
    } 

  private:
    float x_est; // best estimate of true sensor value based on previous measurements 
    float P; // how much to trust estimate 
    float Q; // estimate of how much x_est will change between measurements
    float R; // how much to trust the new sensor measurement

};
