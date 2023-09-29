#pragma once
#include "Geometry.h"
#include "GLH.h"

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
	RETURNVOID Render();
};

