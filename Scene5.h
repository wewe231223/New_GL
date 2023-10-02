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


	RETURNVOID Reshape(GLint NewScreenWidth,GLint NewScreenHeight);

	



};


namespace Scene5_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);










}

CallbackFunc ResisterScene5();