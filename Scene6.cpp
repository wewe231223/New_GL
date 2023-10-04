#include "Scene6.h"

int dots = 0;

RETURNVOID Spiral::NextDot()
{
	this->NewVertex(
		VertexElement{

			{this->Center.x + this->Radius * (float)cos(this->Theta * pi / 180.0),
			this->Center.y + this->Radius * (float)sin(this->Theta * pi / 180.0),
			0.0f},
			this->Color
		}
		,
		5.f
	);

	dots += 1;



	this->Radius += 0.005f;
	this->Theta +=  10.f;

	return RETURNVOID();
}











RETURNVOID Scene6::NewSpiral()
{
	Spiral Newspiral {};
	Newspiral.Init();

	this->Shapes.push_back(Newspiral);
	return RETURNVOID();
}

RETURNVOID Scene6::Init()
{

	this->NewSpiral();
	d.Init();
	return RETURNVOID();
}



RETURNVOID Scene6::Render()
{
	for (auto& i : this->Shapes) { 
		i.Render();
	}

	return RETURNVOID();
}







RETURNVOID Scene6::Continue()
{
	for (auto& i : this->Shapes) {
		i.NextDot();
	}
	return RETURNVOID();
}



Scene6 SC6;


RETURNVOID Scene6_CallBackFunctions::Draw()
{
	Color4f BackGroundColor{ 1.f,1.f,1.f,1.f };

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




	SC6.Render();
	return glutSwapBuffers();
}



RETURNVOID Scene6_CallBackFunctions::Reshape(int w,  int h)
{
	glViewport(0, 0, w, h);
	return RETURNVOID();
}


RETURNVOID Scene6_CallBackFunctions::IdleCall() {
	

}



RETURNVOID Scene6_CallBackFunctions::TimerCall(int Value)
{

	SC6.Continue();
	UPDATE;
	return glutTimerFunc(10, TimerCall, Value);
}


CallbackFunc ResisterScene6()
{
	CallbackFunc result{};
	SC6.Init();
	result.DrawCall = Scene6_CallBackFunctions::Draw;
	result.ReShapeCall = Scene6_CallBackFunctions::Reshape;
	result.IdleCall = Scene6_CallBackFunctions::IdleCall;
	result.TimerCall = Scene6_CallBackFunctions::TimerCall;

	return result;
}



