/*
 * KalmanFilter.h
 *
 *  Created on: Sep 23, 2024
 *      Author: rongweizhang
 */

#ifndef SRC_KALMANFILTER_H_
#define SRC_KALMANFILTER_H_
#include "KalmanFIlter.h"

class KalmanFilter {
public:
	KalmanFilter();
	virtual ~KalmanFilter();
	int q = 0.f;
	int r = 0.f;
	int x = 0.f;
	int p = 0.f;
	int k = 0.f;
	void update()

};

#endif /* SRC_KALMANFILTER_H_ */
