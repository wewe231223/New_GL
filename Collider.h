#pragma once
#include "Geometry.h"
#include "GLH.h"

class BoxCollider{
private:
	PIVOT BottomLeft{};
	PIVOT TopRight{};

public:

	BoxCollider() {};


	bool operator[](const BoxCollider&) const;

};

