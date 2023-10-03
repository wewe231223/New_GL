#pragma once
#include "StandardShape.h"



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



};


namespace Scene5_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);


	RETURNVOID IdleCall(PARAMETERVOID);







}

CallbackFunc ResisterScene5();