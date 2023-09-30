#pragma once
#include "Object.h"
#include "RandomGenerater.h"

#include <vector>
#include <iostream>

#include <Windows.h>



class IsoscelesTriangle : public VertexObject {
private:

	//�̵�ﰢ���� �׸��� 
	Point3F Center{};
	GLfloat Width{};
	GLfloat Height{};

	Color3f Color{};

	RandomGenerater RG;


public:
	IsoscelesTriangle() { this->Init(); };
	
	RETURNVOID Resister();

	
	RETURNVOID Properties(PropertiesType,float, float, float, float,Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);
	

};

class RightTriangle : public VertexObject {
private:
	Point3F Center{};
	GLfloat Side{};
	Color3f Color{};


	RandomGenerater RG;

public:
	RightTriangle() { this->Init(); };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float,Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};



class Rectangle_ {

private:
	RightTriangle T1{};
	RightTriangle T2{};


	Point3F Center{};
	GLfloat Side{};
	Color3f Color{};



	RandomGenerater RG{};

public:
	Rectangle_() {}

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float,Color3f);
	RETURNVOID Render();

	RETURNVOID Move(Vector2F);


};





class Dot : public VertexObject {
private:
	Point3F Center{};

	Color3f Color{};

	RandomGenerater RG;

public:
	Dot() { this->Init(); };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType,float, float, float ,Color3f);
	virtual RETURNVOID Render() override;
	
	RETURNVOID Move(Vector2F);


};


class Line : public VertexObject {
private:
	Point3F Start{};
	Point3F End{};
	Color3f Color{};

	RandomGenerater RG;
public:
	Line() { this->Init(); }

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, Point2F, Point2F,Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};








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


};

namespace Scene3_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID MouseOnClick(int,int,int,int);
	RETURNVOID KeyboardInput(unsigned char, int, int);
	RETURNVOID KeyboardOff(unsigned char, int, int);
	RETURNVOID IdleCall(PARAMETERVOID);


	CallbackFunc CreateCallBackFuctions(PARAMETERVOID);
}