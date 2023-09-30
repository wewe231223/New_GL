#include "RandomGenerater.h"


namespace RandomEngine {
	std::default_random_engine dre;
}



int RandomGenerater::RandInt(int min, int max){


	std::uniform_int_distribution<int>rdi(min,max);

	return rdi(RandomEngine::dre);
}

float RandomGenerater::RandFloat(float min, float max){
	std::uniform_real_distribution<float>rdf (min, max);



	
	return rdf(RandomEngine::dre);
}

double RandomGenerater::RandDouble(double min, double max)
{
	std::uniform_real_distribution<double> rdd(min,max);
	return rdd(RandomEngine::dre);
}
