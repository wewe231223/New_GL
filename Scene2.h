#pragma once
#include "RandomGenerater.h"
#include "Definition.h"
#include "Geometry.h"
#include "Rect.h"
#include "GLH.h"

#include "Collider.h"

enum PARTICLETYPE {
	CROSSTYPE,
	DIAGONALTYPE,
	OCTAGONTYPE
};

// 나눠질 사각형 
class Particle : public Rect {
private:
	Vector2F Direction{};
public:
	Particle() {};
	Particle(SizeF,Vector2F,Color3f);
	virtual RETURNVOID Draw() ;
	


};



//클릭하면 이 자체 사각형은 사라지고 각각 particle에게 type에 따른 값 분배하는 역할 
class ParticleRect : public Rect{
public:
	std::vector<Particle> Particles;
	bool Visible = true;
public:
	ParticleRect();
	bool IsPointInside(int, int);

	


	

	RETURNVOID Clicked(PARAMETERVOID);



	virtual RETURNVOID Draw();

};


class Scene2{
private:
	COLOR4F BackgroundColor{ 1.0f,1.0f,1.0f,1.0f };
	RandomGenerater RandomEngine;

public:
	std::vector<ParticleRect> Rects;

	Scene2();

	float OldWidth = DEFAULT_SCREEN_WIDTH;
	float OldHeight = DEFAULT_SCREEN_HEIGHT;


	RETURNVOID Render();
	

};



namespace Scene2_CallBackFunctions {


	RETURNVOID Render(PARAMETERVOID);
	RETURNVOID ReShape(int, int);
	RETURNVOID MouseOnClick(int, int, int, int);



	CallbackFunc CreateCallBackFunction(PARAMETERVOID);
}


