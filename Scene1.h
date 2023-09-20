#pragma once

#include <iostream>
#include <vector>

#include "RandomGenerater.h"
#include "Definition.h"
#include "Geometry.h"
#include "Rect.h"
#include "GLH.h"

class Scene1_Rect : public Rect {
public:
	Scene1_Rect(PARAMETERVOID);

	
	virtual RETURNVOID Draw(PARAMETERVOID);

};









class Scene1{

private:
	RandomGenerater RandomEngine;
public:

	Color4f BackgroundColor{};
	std::vector<Scene1_Rect> Rects;

	int OldWidth = DEFAULT_SCREEN_WIDTH;
	int OldHeight = DEFAULT_SCREEN_HEIGHT;



public:
	Scene1(PARAMETERVOID);


	
	RETURNVOID Render(PARAMETERVOID);

};



namespace CallBackFunctions {
	RETURNVOID Render(PARAMETERVOID);
	RETURNVOID ReShape(int, int);
	CallbackFunc CreateCallBackFunction(PARAMETERVOID);


}