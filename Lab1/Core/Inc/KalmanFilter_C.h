#ifndef KALMANFILTER_C_H
#define KALMANFILTER_C_H


typedef struct {
    float p;
    float q;
    float r;
    float x;
    float k;
} kalman_state;

void KalmanFilter_init(kalman_state *kf, float q, float r, float p, float initial_value);

//float KalmanFilter_update(kalman_state *kf, float measurement);
int kalmanFilter_C_update(float* InputArray, float* OutputArray, int Length, kalman_state* kf);
extern float kalman(kalman_state *kf, float measurement);
//int kalmanFilter_C_update(float* inputArray, float* outputArray, int length, struct kalman_state* kstate);
#endif
