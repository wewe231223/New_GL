#pragma once

#include <random>



class RandomGenerater{
private:
	std::default_random_engine dre;
	

public:

	RandomGenerater() {}


	
	int RandInt();
	float RandFloat();
	double RandDouble();



};

