#pragma once
#include "Object.h"
#include "RandomGenerater.h"

class IsoscelesTriangle : public VertexObject {
private:

	//이등변삼각형을 그린다 
	Point3F Center{};
	GLfloat Width{};
	GLfloat Height{};

	Color3f Color{};

	RandomGenerater RG;


public:
	IsoscelesTriangle() { this->Init(); };

	RETURNVOID Resister();


	RETURNVOID Properties(PropertiesType, float, float, float, float, Color3f);
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
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
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
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
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
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
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
	RETURNVOID Properties(PropertiesType, Point2F, Point2F, Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};

