#include "Scene5.h"



RETURNVOID Scene5::Init()
{
	this->T1.Init();



	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{
	this->RG.RandInt( -DEFAULT_SCREEN_WIDTH / 2,0),
	this->RG.RandInt(0,DEFAULT_SCREEN_HEIGHT / 2),
	0},
	50,
	100,
	UP,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
	{this->RG.RandInt(5,10),10},
	AdvanceShape::ZigZag
		}
	);



	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
		{
	this->RG.RandInt(0,DEFAULT_SCREEN_WIDTH / 2),
	this->RG.RandInt(0,DEFAULT_SCREEN_HEIGHT / 2),
	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
	{this->RG.RandInt(5,10),0},
	AdvanceShape::Rand
		}
	);


	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{
	this->RG.RandInt( -DEFAULT_SCREEN_WIDTH / 2 , 0),
	this->RG.RandInt(- DEFAULT_SCREEN_HEIGHT / 2 , 0),
	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
	{this->RG.RandInt(5,10),0},
	AdvanceShape::ZigZag
		}
	);





	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{
	this->RG.RandInt(0,DEFAULT_SCREEN_WIDTH / 2),
	this->RG.RandInt(-DEFAULT_SCREEN_HEIGHT / 2 , 0),

	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
	{3,0},
	AdvanceShape::RectSpiral
		}
	);












	this->OldScreenWidth = GET_WINDOW_WIDTHF;
	this->OldScreenHeight = GET_WINDOW_HEIGHTF;
	
	T1.Vector_Apply();


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
	// ºäÆ÷Æ® ¼³Á¤
	glViewport(0, 0, w, h);
	return RETURNVOID();
}

RETURNVOID Scene5_CallBackFunctions::IdleCall(PARAMETERVOID) {
	SC5.Move();
	glutPostRedisplay();
}


RETURNVOID Scene5_CallBackFunctions::TimerCall(int value)
{
	SC5.SpecialMovement();
	glutPostRedisplay();

	return glutTimerFunc(100, Scene5_CallBackFunctions::TimerCall, value);
}



CallbackFunc ResisterScene5()
{
	CallbackFunc result{};
	SC5.Init();


	result.DrawCall = Scene5_CallBackFunctions::Draw;
	result.ReShapeCall = Scene5_CallBackFunctions::Reshape;
	result.IdleCall = Scene5_CallBackFunctions::IdleCall;
	result.TimerCall = Scene5_CallBackFunctions::TimerCall;



	return result;
}


