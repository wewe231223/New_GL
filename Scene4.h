#pragma once
#include "StandardShape.h"


enum ResetFlag {
	RF_T1,
	RF_T2,
	RF_T3,
	RF_T4
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


	RETURNVOID Reset();


};

namespace Scene4_CallBackFunctions{

	

	RETURNVOID Draw();

	RETURNVOID KeyboardInput(unsigned char, int, int);

	CallbackFunc Resister_Scene4(PARAMETERVOID);
}