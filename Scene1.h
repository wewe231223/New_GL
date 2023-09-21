#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "RandomGenerater.h"
#include "Definition.h"
#include "Geometry.h"
#include "Rect.h"
#include "GLH.h"

#include "Collider.h"


class Scene1_Rect : public Rect {
public:
	Scene1_Rect(PARAMETERVOID);
	
	Collider RectCollider{};

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
	Scene1_Rect* Eraser = nullptr;



	float OldWidth = DEFAULT_SCREEN_WIDTH;
	float OldHeight = DEFAULT_SCREEN_HEIGHT;



public:
	Scene1(PARAMETERVOID);


	
	RETURNVOID Render(PARAMETERVOID);
	RETURNVOID ReFill(PARAMETERVOID);


};



namespace Scene1_CallBackFunctions {
	RETURNVOID Render(PARAMETERVOID);

	RETURNVOID ReShape(int, int);

	RETURNVOID MouseOnClick(int, int, int, int);

	RETURNVOID MouseDrag(int, int);
	RETURNVOID Idle(PARAMETERVOID);
	RETURNVOID KeyboardInput(unsigned char, int, int);


	CallbackFunc CreateCallBackFunction(PARAMETERVOID);


}