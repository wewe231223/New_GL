#pragma once
#include "Object.h"
#include "RandomGenerater.h"

constexpr auto MouseCorrection = 50.f;




class Empty_Rectangle : public AdvanceObject::Object {

private:

	Point2F Point1{};
	Point2F Point2{};
	Point2F Point3{};
	Point2F Point4{};

	GLboolean Point1_Picked = false;
	GLboolean Point2_Picked = false;
	GLboolean Point3_Picked = false;
	GLboolean Point4_Picked = false;



	Point2F OldDrag{};
	GLboolean Rect_Picked = false;


	Color3f Color1{};
	Color3f Color2{};
	Color3f Color3{};
	Color3f Color4{};

	RandomGenerater RG{};
public:

	Empty_Rectangle() = default;


	RETURNVOID Initialize();
	RETURNVOID Reset();

	RETURNVOID Drag(Point2F);
	RETURNVOID Click(Point2F);
	RETURNVOID ClickRealease();

	virtual RETURNVOID Render() override final;
};



class Scene8{
private:
	Empty_Rectangle Rect{};

public:

	Scene8() = default;

	RETURNVOID Init();

	RETURNVOID Reset();


	RETURNVOID Render();

	RETURNVOID DragEvent(Point3F);
	RETURNVOID ClickEvent(Point3F);
	RETURNVOID ClickRealease();

};

namespace Scene8_CallBackFunctions {

	RETURNVOID Draw();
	RETURNVOID Reshape(int, int);

	RETURNVOID MouseDrag(int, int);
	RETURNVOID MouseClick(int,int,int, int);
	RETURNVOID KeyBoardInput(unsigned char, int, int);
}

CallbackFunc ResisterScene8();