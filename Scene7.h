#pragma once
#include "Object.h"
#include "RandomGenerater.h"
#include <cmath>

constexpr auto Triangle_Coefficient = 0.8660254f;


class Polygon_Pentagon : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };
	GLfloat Radius = 100.f;
	Point2F Center;


	bool Polymorph = false;
	

public:

	Polygon_Pentagon() = default;


	RETURNVOID Initialize(Point2F);

	RETURNVOID Polymorph_ON() { this->Polymorph = true; }


	RETURNVOID Update();

	virtual RETURNVOID Render() override final;
};


class Polygon_Rectangle : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };
	GLfloat size = 100.f;
	Point2F Center;


	bool Polymorph = false;
	GLfloat t = 0.f;

public:
	Polygon_Rectangle() = default;



	RETURNVOID Initialize(Point2F);

	RETURNVOID Polymorph_ON() { this->Polymorph = true; }


	RETURNVOID Update();

	virtual RETURNVOID Render() override final;
	

};


class Polygon_Triangle : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;


	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };
	GLfloat size = 100.f;
	Point2F Center;


	bool Polymorph = false;
	GLfloat t = 0.f;
	GLfloat Polymorph_size = 0.f;

public:

	Polygon_Triangle() = default;

	RETURNVOID Initialize(Point2F);

	RETURNVOID Polymorph_ON() { this->Polymorph = true; }

	RETURNVOID Update();

	virtual RETURNVOID Render() override final;
};



class Polygon_Line : public AdvanceObject::Object {
private:
	std::vector < VertexElement> VertexArray{};
	RandomGenerater RG{};

	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };
	GLfloat Length = 100.f;
	GLfloat Thickness = 5.0f;
	Point2F Center;


	bool Polymorph = false;
	GLfloat Polymorph_theta = 0.f;

public:
	Polygon_Line() = default;

	RETURNVOID Initialize(Point2F);

	RETURNVOID Polymorph_ON() { this->Polymorph = true; }
	
	RETURNVOID Update();



	virtual RETURNVOID Render() override final;



};

class Scene7{
	Polygon_Pentagon P{};
	Polygon_Rectangle R{};
	Polygon_Triangle T{};
	Polygon_Line L{};

public:
	Scene7() {}
	RETURNVOID Init();
	RETURNVOID Render();
	RETURNVOID Update();
	
	RETURNVOID PolymorthSwitch(int);

};





namespace Scene7_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);
	RETURNVOID Idle();
	RETURNVOID Timer(int);
	RETURNVOID KeyboardInput(unsigned char, int, int);
}

CallbackFunc ResisterScene7();