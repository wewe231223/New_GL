#pragma once
#include "StandardShape.h"

#include <vector>
#include <iostream>


#include <Windows.h>


class Scene3
{
private:

	std::vector<IsoscelesTriangle> Triangles{};
	std::vector<Dot> Dots{};
	std::vector<Rectangle_> Rectangles{};
	std::vector<Line> Lines{};

	int ShapeCount = 0;


public:
	bool MoveRight = false;
	bool MoveLeft = false;
	bool MoveUp = false;
	bool MoveDown = false;


	Scene3() {  };
	std::vector<IsoscelesTriangle> GetTriangles() { return this->Triangles; };
	std::vector<Dot> GetDots() { return this->Dots; }
	std::vector<Rectangle_> GetRects() { return this->Rectangles; }
	std::vector<Line> GetLines() { return this->Lines; }



	RETURNVOID NewTriangle(IsoscelesTriangle);
	RETURNVOID NewDot(Dot);
	RETURNVOID NewRect(Rectangle_);
	RETURNVOID NewLine(Line);


	RETURNVOID Move(Direction );

	RETURNVOID Render();

	RETURNVOID Clear();


};

namespace Scene3_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID MouseOnClick(int,int,int,int);
	RETURNVOID KeyboardInput(unsigned char, int, int);
	RETURNVOID KeyboardOff(unsigned char, int, int);
	RETURNVOID IdleCall(PARAMETERVOID);


	CallbackFunc CreateCallBackFuctions(PARAMETERVOID);
}