#include "arm_math.h"



void difference(float32_t* InputArray, float32_t* OutputArray, float32_t* result,  int length){
	arm_sub_f32(InputArray, OutputArray, result, length);
	arm_abs_f32(result,result, length);
}
