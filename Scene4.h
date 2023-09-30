#pragma once
#include "StandardShape.h"



enum Qudrant {
	Q1, // 1	��и�
	Q2, // 2	��и�
	Q3, // 3	��и�
	Q4  // 4	��и�
};

class Scene4 {
private:
	IsoscelesTriangle T1{};
	IsoscelesTriangle T2{};
	IsoscelesTriangle T3{};
	IsoscelesTriangle T4{};

	Line Horizen{};
	Line Vertial{};
	Line GuideLine1{};
	Line GuideLine2{};
	Line GuideLine3{};
	Line GuideLine4{};



	RandomGenerater RG{};

public:
	Scene4();

	RETURNVOID Init();
	RETURNVOID Render();

	RETURNVOID Clicked(Qudrant, Point2F);

	RETURNVOID Reset();


};

namespace Scene4_CallBackFunctions{

	

	RETURNVOID Draw();

	RETURNVOID KeyboardInput(unsigned char, int, int);
	RETURNVOID MouseInput(int, int, int, int);


	CallbackFunc Resister_Scene4(PARAMETERVOID);
}