#pragma once
#include "Geometry.h"
#include "Definition.h"


class Collider {
public:
	PIVOT BottomLeft{};
	PIVOT TopRight{};

public:



	Collider() {};
	RETURNVOID Update(SizeF,Point2F);
	bool Check(const Collider other);

};

