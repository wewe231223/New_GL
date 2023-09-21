#include "Rect.h"

Rect::Rect(PARAMETERVOID){
	this->Center.x = this->RandomEngine.RandFloat(-1.f, 1.f);
	this->Center.y = this->RandomEngine.RandFloat(-1.f, 1.f);


	this->Color.r = this->RandomEngine.RandFloat(0.f,1.f);
	this->Color.g = this->RandomEngine.RandFloat(0.f, 1.f);
	this->Color.b = this->RandomEngine.RandFloat(0.f, 1.f);


	this->Size.Width = DEFAULT_WIDTH;
	this->Size.Height = DEFAULT_HEIGHT;


	this->ScaleByScreen(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);


}

Rect::Rect(const Rect& other){
	this->RandomEngine = other.RandomEngine;
	this->Center = other.Center;
	this->Size = other.Size;
	this->Color = other.Color;

}

RETURNVOID Rect::ScaleByScreen(int W, int H){

	this->Size.Height = this->Size.Height * (static_cast<float>(W) * 0.001f);
	this->Size.Width = this->Size.Width * (static_cast<float>(H) * 0.001f);

}

RETURNVOID Rect::Translate(int PixelX, int PixelY){



	int Width = glutGet(GLUT_WINDOW_WIDTH);
	int Height = glutGet(GLUT_WINDOW_HEIGHT);

	float glX, glY;

	glX = static_cast<float>(PixelX) / static_cast<float>(Width) * 2.0f - 1.0f;
	glY = 1.0f - static_cast<float>(PixelY) / static_cast<float>(Height) * 2.0f;


	this->Center.x = glX;
	this->Center.y = glY;






	return RETURNVOID();
}


