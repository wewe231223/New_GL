#include "RandomGenerater.h"

int RandomGenerater::RandInt(){
	std::uniform_int_distribution<>rdi;
	return rdi(this->dre);
}

float RandomGenerater::RandFloat(){
	std::uniform_real_distribution<float> rdf;
	return rdf(this->dre);
}

double RandomGenerater::RandDouble()
{
	std::uniform_real_distribution<double> rdd;
	return rdd(dre);
}
