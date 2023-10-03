#pragma once
#include "StandardShape.h"
#include <cmath>





class Scene5
{
private:
	AdvanceShape::IsoscelesTriangle T1{};

	GLfloat OldScreenWidth{};
	GLfloat OldScreenHeight{};

	RandomGenerater RG;

public:
	Scene5() {}
	RETURNVOID Init();
	



	RETURNVOID Render();



	RETURNVOID Move(PARAMETERVOID) { T1.Vector_Movement(); }
	RETURNVOID SpecialMovement(PARAMETERVOID) { T1.Vector_ZigZag_Movement(); }


};


namespace Scene5_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);


	RETURNVOID IdleCall(PARAMETERVOID);


	RETURNVOID TimerCall(int);




}

CallbackFunc ResisterScene5();