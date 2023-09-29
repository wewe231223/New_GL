#pragma once
#include "Object.h"
#include "RandomGenerater.h"

#include <vector>
#include <iostream>



class Triangle : public VertexObject {
private:

	//이등변삼각형을 그린다 
	Point2F Center{};
	GLfloat Width{};
	GLfloat Height{};

	RandomGenerater RG;


public:
	Triangle() { this->Init(); this->Properties(0.0f, 0.0f, 0.0f, 0.0f); };
	
	RETURNVOID CalculateVertex();

	RETURNVOID Properties(float, float, float, float);
	
	

};


class Scene3
{
private:

	std::vector<Triangle> Triangles{};


public:

	Scene3() {};
	std::vector<Triangle> GetTriangles() { return this->Triangles; };

	RETURNVOID NewTriangle(Triangle T) { this->Triangles.push_back(T); };





};

namespace Scene3_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID MouseOnClick(int,int,int,int);
	RETURNVOID KeyboardInput(unsigned char, int, int);



	CallbackFunc CreateCallBackFuctions(PARAMETERVOID);
}