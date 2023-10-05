#include "Scene8.h"


RETURNVOID Empty_Rectangle::Initialize()
{
	this->Init();


	this->Point1  = { -DEFAULT_SCREEN_WIDTH / 4, DEFAULT_SCREEN_HEIGHT / 4  };
	this->Point2 = { DEFAULT_SCREEN_WIDTH / 4 , DEFAULT_SCREEN_HEIGHT / 4 };
	this->Point3 = { -DEFAULT_SCREEN_WIDTH / 4,-DEFAULT_SCREEN_HEIGHT / 4 };
	this->Point4 = { DEFAULT_SCREEN_WIDTH / 4,-DEFAULT_SCREEN_HEIGHT / 4 };



	this->Color1 = { this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) };
	this->Color2 = { this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) };
	this->Color3 = { this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) };
	this->Color4 = { this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) };



	return RETURNVOID();
}

RETURNVOID Empty_Rectangle::Drag(Point2F p)
{



	if (p.x > this->Point1.x - MouseCorrection && p.x < this->Point1.x + MouseCorrection) {
		if (p.y > this->Point1.y - MouseCorrection && p.y < this->Point1.y + MouseCorrection) {

				
			this->Point1.x = p.x;
			this->Point1.y = p.y;



			
		}
	} 

	if (p.x > this->Point2.x - MouseCorrection && p.x < this->Point2.x + MouseCorrection) {
		if (p.y > this->Point2.y - MouseCorrection && p.y < this->Point2.y + MouseCorrection) {



			this->Point2.x = p.x;
			this->Point2.y = p.y;




		}
	}

	if (p.x > this->Point3.x - MouseCorrection && p.x < this->Point3.x + MouseCorrection) {
		if (p.y > this->Point3.y - MouseCorrection && p.y < this->Point3.y + MouseCorrection) {


			this->Point3.x = p.x;
			this->Point3.y = p.y;



		}
	}

	if (p.x > this->Point4.x - MouseCorrection && p.x < this->Point4.x + MouseCorrection) {
		if (p.y > this->Point4.y - MouseCorrection && p.y < this->Point4.y + MouseCorrection) {

			this->Point4.x = p.x;
			this->Point4.y = p.y;




		}
	}


	return RETURNVOID();
}



RETURNVOID Empty_Rectangle::Render()
{
	this->ClearBuffer();



	this->Resister(VertexElement{ Translate(this->Point1),this->Color1});
	this->Resister(VertexElement{ Translate(this->Point2),this->Color2 });
	this->Resister(VertexElement{ Translate(this->Point4),this->Color4 });
	this->Resister(VertexElement{ Translate(this->Point3),this->Color3 });

	AdvanceObject::Object::Render();

	glLineWidth(5.f);
	glDrawArrays(GL_LINE_LOOP, 0, 4);



	return RETURNVOID();
}



RETURNVOID Scene8::Init(){
	this->Rect.Initialize();






	return RETURNVOID();
}


RETURNVOID Scene8::Render()
{

	this->Rect.Render();

	return RETURNVOID();

}

RETURNVOID Scene8::DragEvent(Point3F MousePoint)
{
	
	this->Rect.Drag(Point2F{ MousePoint.x,MousePoint.y });
	return UPDATE;
}







Scene8 SC8{};

RETURNVOID Scene8_CallBackFunctions::Draw()
{
	Color4f BackColor{ 0.f,0.f,0.f,1.f };
	glClearColor(BackColor.r, BackColor.g, BackColor.b, BackColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	SC8.Render();


	return glutSwapBuffers();
}

RETURNVOID Scene8_CallBackFunctions::Reshape(int w , int h)
{

	return glViewport(0, 0, w, h);
}




RETURNVOID Scene8_CallBackFunctions::MouseDrag(int x, int y)
{
	SC8.DragEvent(WindowCoord_to_GLCoord(x,y));
	
	return RETURNVOID();
}




CallbackFunc ResisterScene8()
{
	CallbackFunc result{};
	SC8.Init();

	result.DrawCall = Scene8_CallBackFunctions::Draw;
	result.ReShapeCall = Scene8_CallBackFunctions::Reshape;
	result.MouseDragCall = Scene8_CallBackFunctions::MouseDrag;

	return result;
}
