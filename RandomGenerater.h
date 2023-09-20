#pragma once

#include <random>
#include "Definition.h"


class RandomGenerater{
private:
	std::mt19937 gen;
	
	
public:

	RandomGenerater(PARAMETERVOID) : gen(std::random_device{}()) {}
	
	int RandInt(int min,int max);
	float RandFloat(float min,float max);
	double RandDouble(double min,double max);

};

