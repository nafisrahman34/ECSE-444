#include <KalmanFilter_C.h>

void KalmanFilter_init(kalman_state *kf, float q, float r, float p, float initial_value) {
    kf->q = q;
    kf->r = r;
    kf->p = p;
    kf->x = initial_value;
    kf->k = 0.0;
}

//float KalmanFilter_update(kalman_state *kf, float measurement) {
//    kf->p = kf->p + kf->q;
//    kf->k = kf->p / (kf->p + kf->r);
//    kf->x = kf->x + kf->k * (measurement - kf->x);
//    kf->p = (1 - kf->k) * kf->p;
//
//    return kf->x;
//}
int kalmanFilter_C_update(float* InputArray, float* OutputArray, int Length, kalman_state* kf){
	for (int i = 0; i < Length; i++) {
		if (InputArray == 0 || OutputArray == 0 || kf == 0) {
			        return -1;
			    }
	        kf->p += kf->q;
	        kf->k = kf->p / (kf->p + kf->r);
	        //check division by 0
			if (isnan(kf->k)){
				return -2;
			}
	        kf->x += kf->k * (InputArray[i] - kf->x);
	        kf->p *= (1.0f - kf->k);
	        //check output
			if (isnan(kf->x)){
				 return -3;
			}
	        OutputArray[i] = kf->x;
	    }
	    return 0;
}
