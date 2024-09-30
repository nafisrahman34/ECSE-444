#include "CMSIS_KalmanFilter.h"
#include "arm_math.h"

int CMSISKalmanfilter(float* InputArray, float* OutputArray, kalman_state* kf, int Length) {
	//Null input exception
	if (InputArray == NULL || OutputArray == NULL || kstate == NULL) {
	        return -1;
	    }
    for (int i = 0; i < Length; i++) {
        kf->p = arm_add_f32(kf->p, kf->q,&(kf->p),1);
        arm_add_f32(kf->p, kf->r,&(kf->k),1);
        kf->k = kf->p/kf->k;
        //check division by 0
        if (isnan(kf->k)){
        	return -2;
        }
        float32_t temp;
        arm_sub_f32(&InputArray[i], &kf->x, &temp, 1);
        arm_mult_f32(&kf->k, &temp, &temp, 1);
        arm_add_f32(&kf->x, &temp, &kf->x, 1);
        arm_sub_f32(1.0f, kf->k, &temp, 1);
        arm_mult_f32(&kf->p, &temp, &kf->p, 1);
        //check output
        if (isnan(kf->x)){
             return -3;
        }
        OutputArray[i] = kf->x;
    }
    return 0;
}
