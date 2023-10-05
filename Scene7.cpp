#include "Scene7.h"

constexpr auto pi = 3.141592f;

RETURNVOID Polygon_Pentagon::Initialize(Point2F Center){

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

RETURNVOID Polygon_Pentagon::Render()
{
	this->ClearBuffer();


	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}

	AdvanceObject::Object::Render();


	return glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->VertexArray.size());
}



RETURNVOID Polygon_Rectangle::Initialize(Point2F Center)
{
	this->Init();

	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

	Point2F Point1{ Center.x + this->size, Center.y + this->size };
	Point2F Point2{ Center.x - this->size, Center.y + this->size };
	Point2F Point3{ Center.x - this->size, Center.y - this->size };
	Point2F Point4{ Center.x + this->size, Center.y - this->size };

	this->VertexArray.push_back(VertexElement{ Translate(Point1),Color});
	this->VertexArray.push_back(VertexElement{ Translate(Point2),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point4),Color });


	this->VertexArray.push_back(VertexElement{ Translate(Point2),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point3),Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point4),Color });






	return RETURNVOID();
}



RETURNVOID Polygon_Rectangle::Render()
{
	this->ClearBuffer();


	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}

	AdvanceObject::Object::Render();


	return glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->VertexArray.size());

	return RETURNVOID();
}





RETURNVOID Polygon_Triangle::Initalize(Point2F)
{
	return RETURNVOID();
}






RETURNVOID Scene7::Init()
{
	this->P.Initialize(Point2F{0.f,0.f});
	this->R.Initialize(Point2F{ 100.f, 100.f });
	return RETURNVOID();
}


Scene7 SC7{};

RETURNVOID Scene7::Render()
{

	this->P.Render();
	this->R.Render();

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