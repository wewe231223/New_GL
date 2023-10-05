#include "Scene7.h"

constexpr auto pi = 3.141592f;

RETURNVOID Polygon_Pentagon::Initialize(Point2F Center){

	this->Init();
	this->Center = Center;
	
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
	this->Center = Center;

	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };



	GLfloat RectShape = 45.f;
	
	Point2F Point1{ Center.x + this->size * cosf(RectShape * pi / 180.f),Center.y + this->size * sinf(RectShape * pi / 180.f) };
	Point2F Point2{ Center.x + this->size * cosf((180.f - RectShape) * pi / 180.f),Center.y + this->size * sinf((180.f - RectShape) * pi / 180.f)};
	Point2F Point3{ Center.x + this->size * cosf((180.f + RectShape) * pi / 180.f),Center.y + this->size * sinf((180.f + RectShape) * pi / 180.f) };
	Point2F Point4{ Center.x + this->size * cosf((360.f - RectShape) * pi / 180.f),Center.y + this->size * sinf((360.f - RectShape) * pi / 180.f) };



	this->VertexArray.push_back( VertexElement{Translate(Point1),Color});
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





RETURNVOID Polygon_Triangle::Initialize(Point2F Center)
{

	this->Init();
	this->Center = Center;



	// ���ﰢ�� 
	GLfloat TriShape = 60.f;

	Point2F Point1{ Center.x + this->size * cosf(90.f * pi / 180.f),Center.y + this->size * sinf(90.f * pi / 180.f) };
	Point2F Point2{ Center.x + this->size * cosf((270.f - TriShape) * pi / 180.f),Center.y + this->size * sinf((270.f - TriShape) * pi / 180.f) };
	Point2F Point3{ Center.x + this->size * cosf((270.f + TriShape) * pi / 180.f),Center.y + this->size * sinf((270.f + TriShape) * pi / 180.f) };



	this->VertexArray.push_back(VertexElement{ Translate(Point1),this->Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point2),this->Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point3),this->Color });






	return RETURNVOID();
}

RETURNVOID Polygon_Triangle::Render()
{
	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}
	AdvanceObject::Object::Render();



	return glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->VertexArray.size());
}

RETURNVOID Polygon_Triangle::Update()
{
	if (this->Polymorph) {


		if (this->t >= 0.99f) {

			return RETURNVOID();
		}
		else {
			std::vector<VertexElement>().swap(this->VertexArray);
			this->ClearBuffer();
			this->t += 0.01f;

			GLfloat TriShape = 60.f;


			Point2F Point1{ (1.f - t) * (Center.x + this->size * cosf(90.f * pi / 180.f)) + t * ( Center.x + this->size * cosf((270.f - TriShape) * pi / 180.f)) ,Center.y + this->size * sinf(90.f * pi / 180.f)};
			Point2F Point2{ Center.x + this->size * cosf((270.f - TriShape) * pi / 180.f),Center.y + this->size * sinf((270.f - TriShape) * pi / 180.f) };
			Point2F Point3{ Center.x + this->size * cosf((270.f + TriShape) * pi / 180.f),Center.y + this->size * sinf((270.f + TriShape) * pi / 180.f) };

			Point2F PolymorphPoint{

				(1.f - t)*((Point1.x + Point3.x) / 2) + t * Point3.x,
				(1.f - t)* ((Point1.y + Point3.y) / 2) + t * Point1.y,

			
			
			};


			this->VertexArray.push_back(VertexElement{ Translate(Point1),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(Point2),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(Point3),this->Color });

			this->VertexArray.push_back(VertexElement{ Translate(Point1),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(PolymorphPoint),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(Point3),this->Color });



		}
	}
	else {
		return RETURNVOID();
	}



	return RETURNVOID();
}




RETURNVOID Polygon_Line::Initialize(Point2F Center)
{
	this->Init();
	this->Center = Center;




	Point2F Point1{ Center.x + this->Length * cosf(0.f * pi / 180.f), Center.y + this->Length * sinf(0.f * pi / 180.f) };
	Point2F Point2{ Center.x + this->Length * cosf(180.f * pi / 180.f), Center.y + this->Length * sinf(180.f * pi / 180.f) };
	Point2F PolymophPoint{ Center.x , Center.y };



	this->VertexArray.push_back(VertexElement{ Translate(Point1),this->Color });
	this->VertexArray.push_back(VertexElement{ Translate(Point2),this->Color });
	this->VertexArray.push_back(VertexElement{ Translate(PolymophPoint),this->Color });

	return RETURNVOID();
}



RETURNVOID Polygon_Line::Render()
{

	for (auto& i : this->VertexArray) {
		this->Resister(i);
	}
	AdvanceObject::Object::Render();


	if (this->Polymorph)return glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->VertexArray.size());
	glLineWidth(this->Thickness);
	return glDrawArrays(GL_LINES, 0, (GLsizei)this->VertexArray.size());
}





RETURNVOID Polygon_Line::Update()
{

	if (this->Polymorph) {


		if (this->Polymorph_theta == 90.f) {
			
			return RETURNVOID();
		}
		else {
			std::vector<VertexElement>().swap(this->VertexArray);
			this->ClearBuffer();
			this->Polymorph_theta += 1.f;



			Point2F Point1{ this->Center.x + this->Length * cosf(0.f * pi / 180.f), this->Center.y + this->Length * sinf(0.f * pi / 180.f) };
			Point2F Point2{ this->Center.x + this->Length * cosf(180.f * pi / 180.f), this->Center.y + this->Length * sinf(180.f * pi / 180.f) };
			Point2F PolymophPoint{ Center.x , Center.y + this->Length * 1.5f * sinf(this->Polymorph_theta * pi / 180.f) };



			this->VertexArray.push_back(VertexElement{ Translate(Point1),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(PolymophPoint),this->Color });
			this->VertexArray.push_back(VertexElement{ Translate(Point2),this->Color });

		}
	}
	else {
		return RETURNVOID();
	}




	return RETURNVOID();
}







RETURNVOID Scene7::Init()
{
	this->L.Initialize(Point2F{  - DEFAULT_SCREEN_WIDTH / 4, DEFAULT_SCREEN_HEIGHT / 4});
	this->T.Initialize(Point2F{ DEFAULT_SCREEN_WIDTH / 4 , DEFAULT_SCREEN_HEIGHT / 4  });
	this->R.Initialize(Point2F{ -DEFAULT_SCREEN_WIDTH / 4,-DEFAULT_SCREEN_HEIGHT / 4 });
	this->P.Initialize(Point2F{ DEFAULT_SCREEN_WIDTH/ 4,-DEFAULT_SCREEN_HEIGHT / 4  });
	return RETURNVOID();
}


Scene7 SC7{};

RETURNVOID Scene7::Render()
{

	this->P.Render();
	this->R.Render();
	this->T.Render();
	this->L.Render();

	return RETURNVOID();
}

RETURNVOID Scene7::Update(){

	this->L.Update();
	this->T.Update();

	return RETURNVOID();
}

RETURNVOID Scene7::PolymorthSwitch(int Value){

	if (Value == 1) {
		this->L.Polymorph_ON();
	}
	else if(Value == 2) {
		this->T.Polymorph_ON();
	}


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


RETURNVOID Scene7_CallBackFunctions::Idle()
{


	SC7.Update();
	return UPDATE;
}

RETURNVOID Scene7_CallBackFunctions::KeyboardInput(unsigned char key, int, int){

	if (key == '1') {
		SC7.PolymorthSwitch(1);
	}

	if (key == '2') {
		SC7.PolymorthSwitch(2);
	}


	return RETURNVOID();
}



RETURNVOID Scene7_CallBackFunctions::Timer(int Value)
{


	return glutTimerFunc(10, Scene7_CallBackFunctions::Timer, Value);
}





CallbackFunc ResisterScene7()
{
	SC7.Init();

	CallbackFunc result;

	result.DrawCall = Scene7_CallBackFunctions::Draw;
	result.ReShapeCall = Scene7_CallBackFunctions::Reshape;
	result.TimerCall = Scene7_CallBackFunctions::Timer;
	result.IdleCall = Scene7_CallBackFunctions::Idle;
	result.KeyboardInputCall = Scene7_CallBackFunctions::KeyboardInput;


	return result;
}