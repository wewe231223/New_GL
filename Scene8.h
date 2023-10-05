#pragma once
#include "Object.h"
#include "RandomGenerater.h"

constexpr auto MouseCorrection = 100.f;




class Empty_Rectangle : public AdvanceObject::Object {

private:

	Point2F Point1{};
	Point2F Point2{};
	Point2F Point3{};
	Point2F Point4{};

	Color3f Color1{};
	Color3f Color2{};
	Color3f Color3{};
	Color3f Color4{};

	RandomGenerater RG{};
public:

	Empty_Rectangle() = default;


	RETURNVOID Initialize();

	RETURNVOID Drag(Point2F);

	virtual RETURNVOID Render() override final;
};



class Scene8{
private:
	Empty_Rectangle Rect{};

public:

	Scene8() = default;

	RETURNVOID Init();



	RETURNVOID Render();

	RETURNVOID DragEvent(Point3F);

};

namespace Scene8_CallBackFunctions {

	RETURNVOID Draw();
	RETURNVOID Reshape(int, int);

	RETURNVOID MouseDrag(int, int);

}

CallbackFunc ResisterScene8();