/*
* func.s
*/

.syntax unified
.align 16
.section .text, "x"

// .global exports the label asmStd, which is expected by lab1math.h
.global kalman

/**
* float KalmanFilter_update(KalmanFilter *kf, double measurement);
*
* R0 = pointer to state variables struct
* S0 = current measurement value
*/

kalman:
	PUSH {R1}
	//self->p = self->p + self->q:
	VLDR.f32 S1, [R0] //store self->p in floating point register S1
	VLDR.f32 S2, [R0, #4] //store self->q in floating point register S2
	VADD.f32 S1, S1, S2 //self->p = self->p + self->q

	//self->k = self->p / (self->p + self->r):
	VLDR.f32 S3, [R0, #8] //store self->r in floating point register S3
	VADD.f32 S10, S1, S3 //do (self->p + self->r) and store result in S10
	VDIV.f32 S4, S1, S10 //self->k = self->p / (self->p + self->r) with S4 storing self->k value
	VSTR.f32 S4, [R0, #16] //store self->k value in state variable

	//self->x = self->x + self->k*(measurement - self->x)
	VLDR.f32 S5, [R0, #12] //store self->x in floating point register S5
	VSUB.f32 S10, S0, S5 //do (measurement - self->x) and store result in S10
	VMUL.f32 S10, S4, S10 //do self->k*(measurement - self->x) and store result in S10
	VADD.f32 S5, S5, S10 //self->x = self->x + self->k*(measurement - self->x)
	VSTR.f32 S5, [R0, #12] //store self->x value in state variable

	//self->p = (1 - self->k)*self->p
	MOV R1, #0x3F800000 //hexadecimal representation of 1.0
	VMOV S9, R1 //store value of 1.0 in floating point register
	VSUB.f32 S10, S9, S4 //do (1-self->k) and store result in S10
	VMUL.f32 S1, S10, S1 //S1 stores self->p value; do self->p=(1-self->k)*self->p
	VSTR.f32 S1, [R0] //store self->p back in state variable

	//return self->x
	VMOV S0, S5 //move self->x to S0
	POP {R1}
	BX LR //return



