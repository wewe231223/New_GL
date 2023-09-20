#include "Rect.h"

Rect::Rect(PARAMETERVOID){
	this->Center.x = this->RandomEngine.RandFloat(-1.f, 1.f);
	this->Center.y = this->RandomEngine.RandFloat(-1.f, 1.f);


	this->Color.r = this->RandomEngine.RandFloat(0.f,1.f);
	this->Color.g = this->RandomEngine.RandFloat(0.f, 1.f);
	this->Color.b = this->RandomEngine.RandFloat(0.f, 1.f);


	this->Size.Width = DEFAULT_WIDTH;
	this->Size.Height = DEFAULT_HEIGHT;






}

RETURNVOID Rect::ScaleByScreen(int W, int H){

	this->Size.Height = this->Size.Height * (static_cast<float>(W) * 0.001f);
	this->Size.Width = this->Size.Width * (static_cast<float>(H) * 0.001f);

}


