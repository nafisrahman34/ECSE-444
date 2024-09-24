#ifndef KALMANFILTER_H
#define KALMANFILTER_H


typedef struct {
    float q;
    float r;
    float x;
    float p;
    float k;
} KalmanFilter;

void KalmanFilter_init(KalmanFilter *kf, double q, double r, double p, double initial_value);

double KalmanFilter_update(KalmanFilter *kf, double measurement);


#endif
