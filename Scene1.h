#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "RandomGenerater.h"
#include "Definition.h"
#include "Geometry.h"
#include "Rect.h"
#include "GLH.h"

class Scene1_Rect : public Rect {
public:
	Scene1_Rect(PARAMETERVOID);

	
	virtual RETURNVOID Draw(PARAMETERVOID);


	float VectorX{};
	float VectorY{};


	bool Picking = false;
	bool IsPointInside(int , int);

	RETURNVOID OnWindow(PARAMETERVOID);

};









class Scene1{

private:
	RandomGenerater RandomEngine;
public:

	Color4f BackgroundColor{};
	std::vector<Scene1_Rect> Rects;


	float OldWidth = DEFAULT_SCREEN_WIDTH;
	float OldHeight = DEFAULT_SCREEN_HEIGHT;



public:
	Scene1(PARAMETERVOID);


	
	RETURNVOID Render(PARAMETERVOID);

};



namespace CallBackFunctions {
	RETURNVOID Render(PARAMETERVOID);

	RETURNVOID ReShape(int, int);

	RETURNVOID MouseOnClick(int, int, int, int);

	RETURNVOID MouseDrag(int, int);
	RETURNVOID Idle(PARAMETERVOID);
	CallbackFunc CreateCallBackFunction(PARAMETERVOID);


}