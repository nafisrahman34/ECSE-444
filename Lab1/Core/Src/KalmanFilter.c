#include "KalmanFilter.h"

typedef struct {
    float q;
    float r;
    float x;
    float p;
    float k;
} KalmanFilter;

void KalmanFilter_init(KalmanFilter *kf, float q, float r, float p, float initial_value) {
    kf->q = q;
    kf->r = r;
    kf->p = p;
    kf->x = initial_value;
    kf->k = 0.0;
}

float KalmanFilter_update(KalmanFilter *kf, float measurement) {
    kf->p = kf->p + kf->q;
    kf->k = kf->p / (kf->p + kf->r);
    kf->x = kf->x + kf->k * (measurement - kf->x);
    kf->p = (1 - kf->k) * kf->p;

    return kf->x;
}
