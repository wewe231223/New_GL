#include "Scene5.h"



RETURNVOID Scene5::Init()
{
	this->T1.Init();

	T1.NewIsoscelesTriangle(Point3F{ 0.f, 0.f, 0.f },0.4f,0.6f,DOWN);

	return RETURNVOID();
}



RETURNVOID Scene5::Render()
{



	this->T1.Render();

	return RETURNVOID();
}










//===================================================================================================================
Scene5 SC5{};


RETURNVOID Scene5_CallBackFunctions::Draw()
{
	Color4f BackGroundColor{ 0.f,0.f,0.f,1.f };

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	SC5.Render();


	glutSwapBuffers();
	return RETURNVOID();
}

RETURNVOID Scene5_CallBackFunctions::Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	return RETURNVOID();
}



CallbackFunc ResisterScene5()
{
	CallbackFunc result{};
	SC5.Init();


	result.DrawCall = Scene5_CallBackFunctions::Draw;
	result.ReShapeCall = Scene5_CallBackFunctions::Reshape;





	return result;
}