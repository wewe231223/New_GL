#pragma once

#include <random>
#include "Definition.h"




class RandomGenerater{	
public:

	RandomGenerater(PARAMETERVOID) {}
	
	int RandInt(int min,int max);
	float RandFloat(float min,float max);
	double RandDouble(double min,double max);

};

