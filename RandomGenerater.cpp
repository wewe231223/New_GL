#include "RandomGenerater.h"


namespace RandomEngine {
	std::random_device rd;
	std::mt19937 gen(rd());
}



int RandomGenerater::RandInt(int min, int max){
	std::uniform_int_distribution<int>rdi(min,max);
	return rdi(RandomEngine::gen);
}

float RandomGenerater::RandFloat(float min, float max){
	std::uniform_real_distribution<float>rdf (min, max);
	return rdf(RandomEngine::gen);
}

double RandomGenerater::RandDouble(double min, double max)
{
	std::uniform_real_distribution<double> rdd(min,max);
	return rdd(RandomEngine::gen);
}
