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

	GLenum DrawMode = GL_TRIANGLES;

public:
	IsoscelesTriangle() { };

	RETURNVOID Resister();


	RETURNVOID Properties(PropertiesType, float, float, float, float, Color3f);
	RETURNVOID RenderMode(GLenum);
	virtual RETURNVOID Render() override;


	
	RETURNVOID Move(Vector2F);

	Point3F GetCenter() { return this->Center; }
	GLfloat GetWidth() { return this->Width; }
	GLfloat GetHeight() { return this->Height; }

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

	RETURNVOID Init();

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
	Dot() { };

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

	GLfloat Thickness = 5.0f;

	RandomGenerater RG;
public:
	Line() { }

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, Point2F, Point2F, Color3f);
	RETURNVOID ApplyThickness(GLfloat);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};

