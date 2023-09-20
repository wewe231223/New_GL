#include "RandomGenerater.h"





int RandomGenerater::RandInt(int min, int max){


	std::uniform_int_distribution<>rdi(min,max);

	return rdi(this->gen);
}

float RandomGenerater::RandFloat(float min, float max){
	std::uniform_real_distribution<float>rdf (min, max);

	return rdf(this->gen);
}

double RandomGenerater::RandDouble(double min, double max)
{
	std::uniform_real_distribution<double> rdd(min,max);
	return rdd(this->gen);
}
