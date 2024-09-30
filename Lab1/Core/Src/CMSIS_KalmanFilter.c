#include "CMSIS_KalmanFilter.h"
#include "arm_math.h"

int CMSISKalmanfilter(float* InputArray, float* OutputArray, kalman_state* kf, int Length) {
	//Null input exception
	if (InputArray == NULL || OutputArray == NULL || kf == NULL) {
	        return -1;
	    }
    for (int i = 0; i < Length; i++) {
        kf->p = arm_add_f32(&kf->p, &kf->q,&kf->p,1);
        arm_add_f32(&kf->p, &kf->r,&kf->k,1);

        //check division by 0
        if (kf->k==0){
                	return -2;
                }
        kf->k = kf->p/kf->k;


        float32_t temp;
        arm_sub_f32(&InputArray[i], &kf->x, &temp, 1);
        arm_mult_f32(&kf->k, &temp, &temp, 1);
        arm_add_f32(&kf->x, &temp, &kf->x, 1);
        float one = 1.0;
        arm_sub_f32(&one, &kf->k, &temp, 1);
        arm_mult_f32(&kf->p, &temp, &kf->p, 1);
        //check output
        if (isnan(kf->x)){
             return -3;
        }
        OutputArray[i] = kf->x;
    }
    return 0;
}
void Processing(float* InputArray, float* OutputArray, float* diff, float* stdv, float* avg, float* corrl, float* conv, int length){
	arm_sub_f32(InputArray, OutputArray, diff, length);
	arm_abs_f32(diff, diff, length);
	arm_mean_f32(diff, length, &avg);
	arm_std_f32(diff, length, &stdv);
	arm_correlate_f32(InputArray,length,OutputArray, length, corrl);
	arm_conv_f32(InputArray,length,OutputArray, length, conv);

//	For Pearson correlation:
//	float XY[length];
//	float X2[length];
//	float Y2[length];
//	float Ex;
//	float Ey;
//	float Exy;
//	float Ex2;
//	float Ey2;
//	arm_mult_f32(InputArray, OutputArray, XY, length);
//	arm_mult_f32(InputArray,InputArray,X2,length);
//	arm_mult_f32(OutputArray,OutputArray,Y2,length);
//	arm_mean_f32(XY,length,&Exy);
//	arm_mean_f32(InputArray,length,&Ex);
//	arm_mean_f32(OutputArray,length,&Ey);
//	arm_mean_f32(X2,length,&Ex2);
//	arm_mean_f32(Y2,length,&Ey2);
//	float EX2 = Ex * Ex;
//	float EY2 = Ey * Ey;
//	&corrl = (Exy-Ex*Ey)/(sqrt(Ex2-EX2)*sqrt(Ey2-EY2));

}
