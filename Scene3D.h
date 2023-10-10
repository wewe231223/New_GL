#pragma once
#include <map>

#include "Object3D.h"
#include "Shader.h"
#include "GLH.h"
class Camera {

private:
	glm::vec3 CameraPosition{ };
	glm::vec3 CameraFocusOn{ };
	glm::vec3 CameraUp{};


public:
	Camera();

	RETURNVOID CameraMovement(glm::vec3 pos) { this->CameraPosition += pos; };
	RETURNVOID CameraFocusMovement(glm::vec3 fpos) { this->CameraFocusOn = fpos; }


	glm::mat4 CreateLookAtMatrix();
};

class Scene3D{
private:
	Camera MainCamera{};
	
	std::map<std::string, Object3D*> MeshMap{};
	std::vector<Model*> ModelArray{};

	GLfloat FovY = 60.f;
	GLfloat NearZ = 0.1f;
	GLfloat FarZ = 100.f;


	ShaderID Shaderid{};

public:

	
	Scene3D() = default;
	RETURNVOID Init_ShaderID() { this->Shaderid = Shader::GetShaderInstance()->GetShaderID(); };

	RETURNVOID NewMesh(std::string path);
	RETURNVOID NewModel(std::string path);

	RETURNVOID Render();


	RETURNVOID Reshape(int w,int h);

	RETURNVOID ScaleModel(glm::vec3);

	
};

