#ifndef CMSIS_KALMANFILTER_H
#define CMSIS_KALMANFILTER_H
#include "KalmanFilter.h"

//
//typedef struct {
//    float p;
//    float q;
//    float r;
//    float x;
//    float k;
//} kalman_state;
int CMSISKalmanfilter(float* InputArray, float* OutputArray, kalman_state* kf, int Length);

void Processing(float* InputArray, float* OutputArray, float* diff, float* stdv, float* avg, float* corrl, float* conv, int length);
#endif
