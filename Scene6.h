#pragma once
#include "StandardShape.h"
#include <cmath>

constexpr auto pi = 3.141592;


class Spiral : public AdvanceShape::Dot {
private:
	GLfloat Theta = 0.f;
	GLfloat Radius = 0.f;




	RandomGenerater RG;
	Point2F Center{ 0,0 };
	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

public:

	RETURNVOID NextDot();
	

};




class Scene6 {
private:
	std::vector<Spiral> Shapes{};

	AdvanceShape::Dot d{};

public:
	Scene6() {}




	RETURNVOID NewSpiral();

	RETURNVOID Continue();



	RETURNVOID Init();

	RETURNVOID Render();

};



namespace Scene6_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int, int);


	RETURNVOID IdleCall(PARAMETERVOID);


	RETURNVOID TimerCall(int);


	RETURNVOID KeyBoardInputCall(unsigned char, int, int);

}

CallbackFunc ResisterScene6();