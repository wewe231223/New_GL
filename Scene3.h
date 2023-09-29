#pragma once
#include "Object.h"
#include "RandomGenerater.h"

#include <vector>
#include <iostream>



class IsoscelesTriangle : public VertexObject {
private:

	//이등변삼각형을 그린다 
	Point3F Center{};
	GLfloat Width{};
	GLfloat Height{};

	RandomGenerater RG;


public:
	IsoscelesTriangle() { this->Init(); };
	
	RETURNVOID Resister();


	RETURNVOID Properties(PropertiesType,float, float, float, float);
	virtual RETURNVOID Render() override;
	

};

class RightTriangle : public VertexObject {
private:
	Point3F Center{};
	GLfloat Side{};

	RandomGenerater RG;

public:
	RightTriangle() { this->Init(); };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float);
	virtual RETURNVOID Render() override;



};



class Rectangle_ {

private:
	RightTriangle T1{};
	RightTriangle T2{};

	
	Point3F Center{};
	GLfloat Side{};


	RandomGenerater RG{};

public:
	Rectangle_() {}

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float);
	RETURNVOID Render();



};





class Dot : public VertexObject {
private:
	Point3F Center{};

	RandomGenerater RG;

public:
	Dot() { this->Init(); };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType,float, float, float z);
	virtual RETURNVOID Render() override;
	


};











class Scene3
{
private:

	std::vector<IsoscelesTriangle> Triangles{};
	std::vector<Dot> Dots{};
	std::vector<Rectangle_> Rectangles{};

	int ShapeCount = 0;

public:

	Scene3() {  };
	std::vector<IsoscelesTriangle> GetTriangles() { return this->Triangles; };
	std::vector<Dot> GetDots() { return this->Dots; }
	std::vector<Rectangle_> GetRects() { return this->Rectangles; }



	RETURNVOID NewTriangle(IsoscelesTriangle);
	RETURNVOID NewDot(Dot);
	RETURNVOID NewRect(Rectangle_);
	



};

namespace Scene3_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID MouseOnClick(int,int,int,int);
	RETURNVOID KeyboardInput(unsigned char, int, int);



	CallbackFunc CreateCallBackFuctions(PARAMETERVOID);
}