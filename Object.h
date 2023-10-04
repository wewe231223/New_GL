#pragma once
#include "Geometry.h"

#include <iostream>
#include <vector>
#include <algorithm>

enum VertexNo {
	Vertex_1,
	Vertex_2,
	Vertex_3
};

enum VertexType {
	TVertex,
	TColor
};


class VertexObject
{
private:
	VertexElement Vertex1{};
	VertexElement Vertex2{};
	VertexElement Vertex3{};

	GLuint VAO = 0 ;
	GLuint VBO_Position{};
	GLuint VBO_Color{};



public:

	VertexObject() {}
	RETURNVOID Init();
	RETURNVOID ResisterVertex(VertexNo,VertexType,const float*);
	virtual RETURNVOID Render();
};


namespace AdvanceObject {
	class Object {
	private:
		std::vector<GLfloat> VertexPosition{};
		std::vector<GLfloat> VertexColor{};


		VertexArrayObject VAO{};
		VertexBufferObject VBO{};




	public:
		Object() {};
		RETURNVOID Init();
		RETURNVOID ClearBuffer(PARAMETERVOID);
		RETURNVOID Resister(VertexElement&);

		


		virtual RETURNVOID Render();




	};
}