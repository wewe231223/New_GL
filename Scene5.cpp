#include "Scene5.h"



RETURNVOID Scene5::Init()
{
	this->T1.Init();



	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{
	this->RG.RandFloat( -DEFAULT_SCREEN_WIDTH / 3,0),
	this->RG.RandFloat(0,DEFAULT_SCREEN_HEIGHT / 3),
	0},
	50,
	100,
	UP,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
	
		}
	);



	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
		{
	this->RG.RandFloat(0,DEFAULT_SCREEN_WIDTH / 3),
	this->RG.RandFloat(0,DEFAULT_SCREEN_HEIGHT / 3),
	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
		}
	);


	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{
	this->RG.RandFloat( -DEFAULT_SCREEN_WIDTH / 3 , 0),
	this->RG.RandFloat(- DEFAULT_SCREEN_HEIGHT / 3 , 0),
	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
		}
	);





	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{

	
	this->RG.RandFloat(0,DEFAULT_SCREEN_WIDTH / 3),
	this->RG.RandFloat(-DEFAULT_SCREEN_HEIGHT / 3 , 0),

	0 },
	50,
	100,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)},
		}
	);












	this->OldScreenWidth = GET_WINDOW_WIDTHF;
	this->OldScreenHeight = GET_WINDOW_HEIGHTF;
	


	return RETURNVOID();
}















RETURNVOID Scene5::Render()
{
	this->T1.Render();

	return RETURNVOID();
}

RETURNVOID Scene5::NewMovement(AdvanceShape::VectorType T)
{
	this->T1.ResetAnimationFactors(T);
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

	return glutTimerFunc(10, Scene5_CallBackFunctions::TimerCall, value);
}


RETURNVOID Scene5_CallBackFunctions::KeyBoardInputCall(unsigned char Key, int, int)
{
	if (Key == '1') {
		SC5.NewMovement(AdvanceShape::Rand);
	} 

	if (Key == '2') {
		SC5.NewMovement(AdvanceShape::ZigZag);
	}


	if (Key == '3') {
		SC5.NewMovement(AdvanceShape::RectSpiral);
	}
	
	if (Key == '4') {
		SC5.NewMovement(AdvanceShape::Spiral);
	}


	return RETURNVOID();
}

CallbackFunc ResisterScene5()
{
	CallbackFunc result{};
	SC5.Init();


	result.DrawCall = Scene5_CallBackFunctions::Draw;
	result.ReShapeCall = Scene5_CallBackFunctions::Reshape;
	result.IdleCall = Scene5_CallBackFunctions::IdleCall;
	result.TimerCall = Scene5_CallBackFunctions::TimerCall;
	result.KeyboardInputCall = Scene5_CallBackFunctions::KeyBoardInputCall;



	return result;
}


