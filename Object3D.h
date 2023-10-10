#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


#include "Definition.h"
#include "GLH.h"
#include "Geometry.h"
#include "RandomGenerater.h"

enum Object3DBoolEnum {
	Fill,
	Cull,
	RandColor
};


enum Object3DVecEnum {
	RotateX,
	RotateY,
	Movement,
	ObjectScale
};

class Model;

class Object3D{
private:



	//===========INITIALIZEDFIELD================
	std::vector<glm::vec3> Verties{};
	std::vector<glm::vec2> UVs{};
	std::vector<glm::vec3> Normals{};

	std::vector<GLuint> Vertex_Indices{};
	std::vector<GLuint> UV_Indices{};
	std::vector<GLuint> Normal_Indices{};
		
	std::vector<Color3f> IndexedColor{};

	std::fstream File;

	ShaderID ShaderProgramId{};
	VertexArrayObject VAO{};
	VertexElementArrayObject EBO{};

	VertexBufferObject VBO{};

	RandomGenerater ColorGenerater{0.f,1.f};

	std::vector<Model*> Mem{};

	//===========INITIALIZEDFIELD================



	GLboolean Filled = true ;
	GLboolean Culling = true;


	glm::vec3 Position{ 0.f,0.f,0.f };
	glm::vec3 Scale{ 1.f,1.f,1.f };

	GLfloat XRotate = 0.f;
	GLfloat YRotote = 0.f;

	GLboolean RandomColor = false;

private:

	

public:



	Object3D() = default;
	Object3D(const char* path) { this->Initialize(path); }
	~Object3D();


public:

	RETURNVOID Initialize(const char* path);
	RETURNVOID Resister();
	RETURNVOID Buffering();


	Model* NewModel();

public:

	
	
};

// 카메라 만들어!
class Model {
private:
	GLboolean Culling = true;
	GLboolean Filled = false ;

	glm::vec3 Position{};
	glm::vec3 Scale{ 1.f,1.f,1.f };


	GLfloat XRotate{};
	GLfloat YRotate{};



public:
	// For Initialization
	ShaderID ShaderId{NULL};
	VertexArrayObject VAO{};
	GLsizei VertexSize = {};





public:

	Model() = default;


	RETURNVOID Render();
	RETURNVOID Transition(Object3DVecEnum Ve, glm::vec3 Vector);


};