#include "Scene5.h"



RETURNVOID Scene5::Init()
{
	this->T1.Init();





	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
		{0.f,0.f,0.f},
		0.5f,
		0.5f,
		UP,
		{this->RG.RandFloat(0.f,1.f),
		this->RG.RandFloat(0.f,1.f),
		this->RG.RandFloat(0.f,1.f)}
		}
	);
	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{0.f,0.f,0.f},
	0.5f,
	0.5f,
	LEFT,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)}
		}
	);

	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{0.f,0.f,0.f},
	0.5f,
	0.5f,
	RIGHT,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)}
		}
	);


	T1.NewIsoscelesTriangle(AdvanceShape::IsoTriElement{
	{0.f,0.f,0.f},
	0.5f,
	0.5f,
	DOWN,
	{this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f),
	this->RG.RandFloat(0.f,1.f)}
		}
	);




	this->OldScreenWidth = GETWIN_WIDTH;
	this->OldScreenHeight = GETWIN_HEIGHT;



	return RETURNVOID();
}




#include <Windows.h>

RETURNVOID Scene5::Reshape(GLint NewScreenWidth, GLint NewScreenHeight)
{
	GLfloat RatioX = this->OldScreenWidth / static_cast<float>(NewScreenWidth);
	GLfloat RatioY = this->OldScreenHeight / static_cast<float>(NewScreenHeight);







	this->T1.Reshape(RatioX, RatioY);


	this->OldScreenWidth = GETWIN_WIDTH;
	this->OldScreenHeight = GETWIN_HEIGHT;



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
	SC5.Reshape(w, h);
	// ºäÆ÷Æ® ¼³Á¤
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