#ifndef CMSIS_KALMANFILTER_H
#define CMSIS_KALMANFILTER_H


typedef struct {
    float p;
    float q;
    float r;
    float x;
    float k;
} kalman_state;
int Kalmanfilter(float* InputArray, float* OutputArray, kalman_state* kf, int Length);
