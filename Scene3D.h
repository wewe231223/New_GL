#pragma once
#include <map>
#include <Windows.h>

#include "Object3D.h"
#include "Shader.h"
#include "GLH.h"


class Camera {

private:
	glm::vec3 CameraPosition{ };
	glm::vec3 CameraFocusOn{ };
	glm::vec3 CameraUp{};


	GLfloat Fovy = 60.f;

public:
	Camera();

	RETURNVOID CameraMovement_R(glm::vec3 pos) { this->CameraPosition += pos; };
	RETURNVOID CameraMovement_A(glm::vec3 pos) { this->CameraPosition = pos; };

	RETURNVOID CameraFocusMovement(glm::vec3 fpos) { this->CameraFocusOn = fpos; }

	GLfloat GetFov() { return this->Fovy; };


	glm::mat4 CreateLookAtMatrix();
};

enum CameraMovement {
	Realative,
	Absolute
};


class Coordinate {
private:



	VertexArrayObject VAO{};
	VertexBufferObject VBO{};
public:
	Coordinate() = default;

	RETURNVOID Init();

	RETURNVOID Render();

};


class Scene3D{
private:
	Camera MainCamera{};
	Coordinate Coord{};
	
	std::map<std::string, Object3D*> MeshMap{};
	std::vector<std::shared_ptr<Model>> ModelArray{};


	GLfloat NearZ = 0.1f;
	GLfloat FarZ = 100.f;


	ShaderID Shaderid{};

public:

	
	Scene3D() = default;
	RETURNVOID Init() { this->Shaderid = Shader::GetShaderInstance()->GetShaderID(); this->Coord.Init(); };

	RETURNVOID NewMesh(std::string path);
	std::shared_ptr<Model> NewModel(std::string path);

	RETURNVOID Render();
	RETURNVOID CoordRender() { this->Coord.Render(); };


	RETURNVOID Reshape(int w,int h);

	RETURNVOID ScaleModel(glm::vec3);

	RETURNVOID MoveCamera(CameraMovement,glm::vec3);
	
};


