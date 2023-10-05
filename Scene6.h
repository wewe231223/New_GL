#pragma once
#include "StandardShape.h"
#include <cmath>

constexpr auto pi = 3.141592f;
constexpr auto MaxSpiral = 200;
constexpr auto MaxTheta = 360.f * 3.f;
constexpr auto Positive = 1.f;
constexpr auto Negative = -1.f;

enum SpiralType {
	LEFTPART,RIGHTPART
};

class Spiral : public AdvanceObject::Object {

private:


	GLfloat dt{};
	GLfloat dr{};

	
	GLenum RenderMode = GL_LINE_STRIP;
	//GLenum RenderMode = GL_POINTS;
	
	GLfloat PointSize = 4.f;

	

	std::vector<VertexElement> VertexArray{};



	RandomGenerater RG{};

public:
	GLint RenderSize = 1;
	GLint RenderDirection = 1;

	Spiral(Point2F);


	RETURNVOID ChangeRenderMode(GLenum Mode) { this->RenderMode = Mode; }
	RETURNVOID NextFrame();

	virtual RETURNVOID Render() final override;


};








class Scene6 {
private:

	std::vector<Spiral> Shapes{};
	RandomGenerater RG{};
	Color4f BackGroundColor{ 0.f,0.f,0.f,0.f };


public:
	Scene6() {}




	RETURNVOID NewSpiral();
	RETURNVOID Reset();

	RETURNVOID ResetBackGroundColor() { 
		this->BackGroundColor.r = this->RG.RandFloat(0.f, 1.f); 
		this->BackGroundColor.g = this->RG.RandFloat(0.f, 1.f);
		this->BackGroundColor.b = this->RG.RandFloat(0.f, 1.f);
		this->BackGroundColor.a = 0.f;}

	Color4f GetBackColor() { return this->BackGroundColor; }

	RETURNVOID ShapesRenderMode(GLenum M);


	RETURNVOID Timer();



	RETURNVOID Init();

	RETURNVOID Render();

};



namespace Scene6_CallBackFunctions {
	RETURNVOID Draw();
	RETURNVOID Reshape(int, int);


	RETURNVOID IdleCall(PARAMETERVOID);


	RETURNVOID TimerCall(int);


	RETURNVOID KeyBoardInputCall(unsigned char, int, int);

}

CallbackFunc ResisterScene6();