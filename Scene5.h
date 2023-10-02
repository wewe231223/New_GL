#pragma once
#include "StandardShape.h"



class Scene5
{
private:
	AdvanceShape::IsoscelesTriangle T1{};


public:
	Scene5() {}
	RETURNVOID Init();



	RETURNVOID Render();




	



};


namespace Scene5_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);










}

CallbackFunc ResisterScene5();