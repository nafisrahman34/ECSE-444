#ifndef KALMANFILTER_H
#define KALMANFILTER_H


typedef struct {
    float p;
    float q;
    float r;
    float x;
    float k;
} kalman_state;

void KalmanFilter_init(kalman_state *kf, float q, float r, float p, float initial_value);

float KalmanFilter_update(kalman_state *kf, float measurement);

extern void kalman(kalman_state *kf, float measurement);

#endif
