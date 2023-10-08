#pragma once

#include <random>
#include "Definition.h"




class RandomGenerater{	
private:

	float FR_MIN{};
	float FR_MAX{};


public:

	RandomGenerater(PARAMETERVOID) {}
	
	RandomGenerater(float a, float b) : FR_MIN(a), FR_MAX(b) {}

	int RandInt(int min,int max);
	float RandFloat(float min,float max);
	double RandDouble(double min,double max);

	float RandF();



	float ApplyResisterF(float a, float b) {this->FR_MIN = a;this->FR_MAX = b;}


};

