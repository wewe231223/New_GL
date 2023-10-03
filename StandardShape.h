#pragma once

#include <tuple>

#include "Object.h"
#include "RandomGenerater.h"

class IsoscelesTriangle : public VertexObject {
private:

	//이등변삼각형을 그린다 
	Point3F Center{};
	GLfloat Width{};
	GLfloat Height{};

	Color3f Color{};

	RandomGenerater RG;

	GLenum DrawMode = GL_TRIANGLES;

public:
	IsoscelesTriangle() { };

	RETURNVOID Resister();


	RETURNVOID Properties(PropertiesType, float, float, float, float, Color3f);
	RETURNVOID RenderMode(GLenum);
	virtual RETURNVOID Render() override;


	
	RETURNVOID Move(Vector2F);

	Point3F GetCenter() { return this->Center; }
	GLfloat GetWidth() { return this->Width; }
	GLfloat GetHeight() { return this->Height; }

};




class RightTriangle : public VertexObject {
private:
	Point3F Center{};
	GLfloat Side{};
	Color3f Color{};


	RandomGenerater RG;

public:
	RightTriangle() { this->Init(); };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};



class Rectangle_ {

private:
	RightTriangle T1{};
	RightTriangle T2{};


	Point3F Center{};
	GLfloat Side{};
	Color3f Color{};



	RandomGenerater RG{};

public:
	Rectangle_() {}

	RETURNVOID Init();

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
	RETURNVOID Render();

	RETURNVOID Move(Vector2F);


};





class Dot : public VertexObject {
private:
	Point3F Center{};

	Color3f Color{};

	RandomGenerater RG;

public:
	Dot() { };

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, float, float, float, Color3f);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};


class Line : public VertexObject {
private:
	Point3F Start{};
	Point3F End{};
	Color3f Color{};

	GLfloat Thickness = 5.0f;

	RandomGenerater RG;
public:
	Line() { }

	RETURNVOID Resister();
	RETURNVOID Properties(PropertiesType, Point2F, Point2F, Color3f);
	RETURNVOID ApplyThickness(GLfloat);
	virtual RETURNVOID Render() override;

	RETURNVOID Move(Vector2F);


};


/// <summary>
/// Must Following this rules 
/// 1. One class can express All Shapes
/// 2. Use own Element Packgaes
/// </summary>
namespace AdvanceShape {
	class Dot : public AdvanceObject::Object {
	private:

		std::vector<VertexElement> Vertex{};

		GLfloat Size = 5.0f;

		RandomGenerater RG;


	public:

		Dot() {};

		//============
		RETURNVOID NewVertex(VertexElement,GLfloat);
		//============



		
		virtual RETURNVOID Render() override;


	};




	enum VectorType {
		Rand,
		ZigZag,
		RectSpiral,
		Spiral
	};


constexpr auto Interval = 100;
constexpr auto RectSpiral_Interval = 10;
constexpr auto pi = 3.141592;

	/// <summary>
	/// 1.Center
	/// 2.Width
	/// 3.Height
	/// 4.Directrion
	/// 5.Color
	/// </summary>
	typedef struct _ISOTRIANGLEPACKAGE {
		Point3I Center;
		GLint Width;
		GLint Height;
		Direction TopDirection;
		

		Color3f Color;


		Vector2I Vector = { 0, };
		VectorType MovementType = Rand;




		//=======AnimationFactor============

		Direction ZigZag_Y_Factor = DOWN;
		

		GLint OldX = 0;
		GLint OldY = 0;



		GLint NextDistance = 20;


		GLint Theta = 1;


	}IsoTriElement;






	class IsoscelesTriangle : public AdvanceObject::Object {
	private:
		std::vector <IsoTriElement> Properties{};


		Direction TopDirection = UP;
		RandomGenerater RG;


		std::tuple<VertexElement,VertexElement,VertexElement> CalculateVertex(IsoTriElement);


		bool ZigZag_Going_Down = true;


		


	public:
		IsoscelesTriangle() {}


		//====Render======
		virtual RETURNVOID Render() override;

		





		//===New===================
		RETURNVOID NewIsoscelesTriangle(IsoTriElement);



		//============================








		RETURNVOID Vector_Apply();
		RETURNVOID Vector_Animation(PARAMETERVOID);
		RETURNVOID Vector_Movement(PARAMETERVOID);

		//==========================Animations======================================




		RETURNVOID ResetAnimationFactors(PARAMETERVOID);
		
		


	};



	//===============================================Structs








}