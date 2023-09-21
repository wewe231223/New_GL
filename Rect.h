#pragma once
#include "Geometry.h"
#include "RandomGenerater.h"

#define DEFAULT_WIDTH	0.3f
#define DEFAULT_HEIGHT	0.3f

class Rect{
public:
	RandomGenerater RandomEngine{};
	Point2F Center{};
	SizeF Size{};
	Color3f Color{};

public:
	Rect(PARAMETERVOID);
	RETURNVOID ScaleByScreen(int, int);
	virtual RETURNVOID Draw(PARAMETERVOID) = 0;


	


};


