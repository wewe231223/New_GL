#pragma once
#include "Object.h"
#include "RandomGenerater.h"
#include <cmath>



class Pentagon : public AdvanceObject::Object {
private:
	std::vector<VertexElement> VertexArray{};
	RandomGenerater RG;

	GLfloat Radius = 100;
public:
	Pentagon() {};


	RETURNVOID Initialize(Point2F);
	virtual RETURNVOID Render() override final;
};




class Scene7{
	Pentagon P{};

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