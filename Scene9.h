#pragma once

#include <cmath>
#include "Object.h"
#include "RandomGenerater.h"


namespace std {
	class Polygon : public AdvanceObject::Object {

	private:
		std::vector<VertexElement> VertexArray{};
		RandomGenerater RG{};

		Point2F Center{};
		GLfloat Length{};
		Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };



		GLenum RenderType = GL_TRIANGLE_FAN;

		int poly = 0;

		Vector2F Vector{ this->RG.RandFloat(-1.f,1.f), this->RG.RandFloat(-1.f,1.f)};
		GLboolean Picked = false;


	public:

		Polygon() = default;
		RETURNVOID Initialize(int poly, Point2F Center, GLfloat Length);
		
		const std::vector<VertexElement> GetVertex();
		const int GetPoly() { return this->poly; }
		const Point2F GetCenter() { return this->Center; }
		const GLfloat GetLength() { return this->Length; }
		const GLboolean GetPicked() { return this->Picked; }



		RETURNVOID ModifyPoly(int p) { this->poly = p; }
		RETURNVOID Update();
		RETURNVOID Picking();
		RETURNVOID Drag(GLfloat dx,GLfloat dy);
		RETURNVOID UnPicking();



		RandomGenerater GetRandom() { return this->RG; }


		virtual RETURNVOID Render() override final;
	};

}




class Scene9{


private:
	std::vector<std::Polygon> Polygons{};

	RandomGenerater RG;


	Point2F OldPoint{};


public:

	Scene9() = default;

	RETURNVOID Init();

	RETURNVOID Render();

	RETURNVOID Update();

	RETURNVOID Pick(Point3F );
	RETURNVOID Drag(Point3F);
	RETURNVOID UnPick();

	RETURNVOID Collision();

};


namespace Scene9_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);

	RETURNVOID Idle();

	RETURNVOID MouseClick(int, int, int, int);
	RETURNVOID MouseDrag(int, int);
}


CallbackFunc ResisterScene9();