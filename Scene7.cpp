#include "Scene7.h"

constexpr auto pi = 3.141592f;

RETURNVOID Pentagon::Initialize(Point2F Center){

	this->Init();

	
	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

	float theta = 90.f;

	


	Point2F Point1{ Center.x + this->Radius * cosf(theta * pi / 180.f),Center.y + this->Radius * sinf(theta * pi / 180.f) };

	theta += 72.f;
	Point2F Point2{ Center.x + this->Radius * cosf(theta * pi / 180.f),Center.y + this->Radius * sinf(theta * pi / 180.f) };

	theta += 72.f;
	Point2F Point3{ Center.x + this->Radius * cosf(theta * pi / 180.f),Center.y + this->Radius * sinf(theta * pi / 180.f) };

	theta += 72.f;
	Point2F Point4{ Center.x + this->Radius * cosf(theta * pi / 180.f),Center.y + this->Radius * sinf(theta * pi / 180.f) };

	theta += 72.f;
	Point2F Point5{ Center.x + this->Radius * cosf(theta * pi / 180.f),Center.y + this->Radius * sinf(theta * pi / 180.f) };

	this->VertexArray.push_back(VertexElement{ Translate(Center),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point1),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point2),Color });

	this->VertexArray.push_back(VertexElement{ Translate(Center),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point2),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point3),Color });

	this->VertexArray.push_back(VertexElement{ Translate(Center),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point3),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point4),Color });

	this->VertexArray.push_back(VertexElement{ Translate(Center),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point4),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point5),Color });

	this->VertexArray.push_back(VertexElement{ Translate(Center),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point5),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point1),Color });



}

RETURNVOID Pentagon::Render()
{
	this->ClearBuffer();


	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}

	AdvanceObject::Object::Render();


	return glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->VertexArray.size());
}



RETURNVOID Scene7::Init()
{
	this->P.Initialize(Point2F{0.f,0.f});

	return RETURNVOID();
}


Scene7 SC7{};

RETURNVOID Scene7::Render()
{

	this->P.Render();

	return RETURNVOID();
}




RETURNVOID Scene7_CallBackFunctions::Draw()
{
	Color4f BackColor{ 0.f,0.f,0.f,1.f };
	glClearColor(BackColor.r, BackColor.g, BackColor.b, BackColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	SC7.Render();

	
   return glutSwapBuffers();
}

RETURNVOID Scene7_CallBackFunctions::Reshape(int w,int h)
{
	glViewport(0, 0, w, h);

	return RETURNVOID();
}

CallbackFunc ResisterScene7()
{
	SC7.Init();

	CallbackFunc result;

	result.DrawCall = Scene7_CallBackFunctions::Draw;
	result.ReShapeCall = Scene7_CallBackFunctions::Reshape;


	return result;
}