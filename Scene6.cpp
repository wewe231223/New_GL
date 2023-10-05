#include "Scene6.h"

Spiral::Spiral(Point2F Center){
	
	this->Init();



	this->dt = this->RG.RandFloat(5.0f, 10.f);
	this->dr = this->RG.RandFloat(0.1f, 1.0f);


	float Xinterval = (MaxTheta / this->dt) * this->dr;
	Point2F LeftPart{Center.x - Xinterval,Center.y};
	Point2F RightPart{ Center.x + Xinterval,Center.y };

	std::vector<VertexElement> LeftSpiral{};
	std::vector<VertexElement> RightSpiral{};


	Point2F PointBuffer{};

	GLfloat ThetaBuffer{};
	GLfloat RadiusBuffer{};


	while (ThetaBuffer < MaxTheta) {
		PointBuffer.x = LeftPart.x + RadiusBuffer * cosf(ThetaBuffer * pi / 180.f);
		PointBuffer.y = LeftPart.y + RadiusBuffer * sinf(ThetaBuffer * pi / 180.f);

		LeftSpiral.push_back(VertexElement{
			
			Translate(PointBuffer),
			{this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f)}
			}
		);

		ThetaBuffer += this->dt;
		RadiusBuffer += this->dr;
	}

	PointBuffer = Point2F{0,};
	ThetaBuffer = 0.f;
	RadiusBuffer = 0.f;


	while (ThetaBuffer < MaxTheta) {
		PointBuffer.x = RightPart.x + RadiusBuffer * cosf(ThetaBuffer * pi / 180.f);
		PointBuffer.y = RightPart.y + RadiusBuffer * sinf(ThetaBuffer * pi / 180.f);

		RightSpiral.push_back(VertexElement{

			Translate(PointBuffer),
			{this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f)}
			}
		);

		ThetaBuffer += this->dt;
		RadiusBuffer -= this->dr;
	}


	
	std::reverse(RightSpiral.begin(), RightSpiral.end());

	std::vector<VertexElement>::iterator iter = this->VertexArray.end();

	this->VertexArray.insert(iter, LeftSpiral.begin(), LeftSpiral.end());

	iter = this->VertexArray.end();

	this->VertexArray.insert(iter, RightSpiral.begin(), RightSpiral.end());

}




RETURNVOID Spiral::Render()
{
	this->ClearBuffer();

	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}

	

	AdvanceObject::Object::Render();

	
	if(this->RenderMode == GL_POINTS) glPointSize(this->PointSize);
	if (this->RenderMode == GL_LINE_STRIP) glLineWidth(this->PointSize / 2);


	glDrawArrays(this->RenderMode, 0, (GLsizei)this->RenderSize);
	return RETURNVOID();
}


RETURNVOID Spiral::NextFrame()
{
	if (this->RenderSize == this->VertexArray.size() - 1) {
		this->RenderDirection = -1;
	}
	else if (this->RenderSize == 1 && this->RenderDirection == -1) {
		this->RenderDirection = 1;
	}

	this->RenderSize += this->RenderDirection;


	return RETURNVOID();
}







RETURNVOID Scene6::NewSpiral()
{
	this->Shapes.push_back(Spiral{ Point2F{this->RG.RandFloat(-GET_WINDOW_WIDTHF / 3,GET_WINDOW_WIDTHF / 3),this->RG.RandFloat(-GET_WINDOW_HEIGHTF / 3,GET_WINDOW_HEIGHTF / 3)} });

	return RETURNVOID();
}

RETURNVOID Scene6::Reset()
{
	this->ResetBackGroundColor();
	std::vector<Spiral>().swap(this->Shapes);
	return RETURNVOID();
}







RETURNVOID Scene6::Init()
{


	return RETURNVOID();
}



RETURNVOID Scene6::Render()
{
	
	for (auto& i : this->Shapes) {
		i.Render();

	}


	return RETURNVOID();
}







RETURNVOID Scene6::Timer()
{
	for (auto& i : this->Shapes) i.NextFrame();
	return RETURNVOID();
}
RETURNVOID Scene6::ShapesRenderMode(GLenum M)
{
	for (auto& i : this->Shapes) {
		i.ChangeRenderMode(M);
	}

	return RETURNVOID();
}


Scene6 SC6;


RETURNVOID Scene6_CallBackFunctions::Draw()
{
	COLOR4F BackGroundColor = SC6.GetBackColor();

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
		
	SC6.Timer();
	UPDATE;
	return glutTimerFunc(10, TimerCall, Value);
}


RETURNVOID Scene6_CallBackFunctions::KeyBoardInputCall(unsigned char key, int, int)
{
	if (key == '1') {

		SC6.Reset();
		SC6.NewSpiral();

	}

	if (key == '2') {
		SC6.Reset();
		SC6.NewSpiral();
		SC6.NewSpiral();

	}

	if (key == '3') {
		SC6.Reset();
		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();

	}
	if (key == '4') {
		SC6.Reset();

		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();
	}

	if (key == '5') {
		SC6.Reset();

		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();
		SC6.NewSpiral();

	}


	if (key == 'p') {
		SC6.ShapesRenderMode(GL_POINTS);
	}
	

	if (key == 'l') {
		SC6.ShapesRenderMode(GL_LINE_STRIP);
	}



	return RETURNVOID();
}

CallbackFunc ResisterScene6()
{
	CallbackFunc result{};
	SC6.Init();
	result.DrawCall = Scene6_CallBackFunctions::Draw;
	result.ReShapeCall = Scene6_CallBackFunctions::Reshape;
	result.IdleCall = Scene6_CallBackFunctions::IdleCall;
	result.TimerCall = Scene6_CallBackFunctions::TimerCall;
	result.KeyboardInputCall = Scene6_CallBackFunctions::KeyBoardInputCall;
	return result;
}



