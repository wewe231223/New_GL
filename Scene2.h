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


class Particle : public Rect {
private:
	Vector2F Direction{};
public:
	Particle() {};
	Particle(SizeF,Vector2F,Color3f);
	virtual RETURNVOID Draw() ;
	


};




class ParticleRect : public Rect{
public:
	ParticleRect() {}
	bool IsPointInside(int, int);



};


class Scene2{
private:
	COLOR4F BackgroundColor{ 1.0f,1.0f,1.0f,1.0f };

public:
	Scene2();

	float OldWidth = DEFAULT_SCREEN_WIDTH;
	float OldHeight = DEFAULT_SCREEN_HEIGHT;


	RETURNVOID Render();
	

};



namespace Scene2_CallBackFunctions {






	RETURNVOID Render(PARAMETERVOID);
	RETURNVOID ReShape(int, int);


	CallbackFunc CreateCallBackFunction(PARAMETERVOID);
}