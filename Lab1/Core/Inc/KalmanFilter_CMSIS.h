#ifndef CMSIS_KALMANFILTER_H
#define CMSIS_KALMANFILTER_H
#include <KalmanFilter_C.h>

//
//typedef struct {
//    float p;
//    float q;
//    float r;
//    float x;
//    float k;
//} kalman_state;
int kalmanFilter_CMSIS_update(float* InputArray, float* OutputArray, int Length, kalman_state* kf);

void Processing(float* InputArray, float* OutputArray, float* diff, float* stdv, float* avg, float* corrl, float* conv, int length);
#endif
