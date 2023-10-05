#pragma once
#include "Object.h"
#include "RandomGenerater.h"
#include <cmath>

constexpr auto Triangle_Coefficient = 0.8660254f;


class Polygon_Pentagon : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	GLfloat Radius = 100.f;
public:
	Polygon_Pentagon() = default;


	RETURNVOID Initialize(Point2F);
	virtual RETURNVOID Render() override final;
};


class Polygon_Rectangle : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	GLfloat size = 50.f;

public:
	Polygon_Rectangle() = default;



	RETURNVOID Initialize(Point2F);
	virtual RETURNVOID Render() override final;
	

};


class Polygon_Triangle : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	GLfloat size = 100.f;

public:

	Polygon_Triangle() {}

	RETURNVOID Initalize(Point2F);
	virtual RETURNVOID Render() override final;




};


class Scene7{
	Polygon_Pentagon P{};
	Polygon_Rectangle R{};

public:
	Scene7() {}
	RETURNVOID Init();

	RETURNVOID Render();



};

namespace Scene7_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);


}

CallbackFunc ResisterScene7();