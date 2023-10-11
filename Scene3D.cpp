#include "Scene3D.h"

Camera::Camera(){

	this->CameraPosition = glm::vec3(0.f, 10.f, -10.f);
	this->CameraFocusOn = glm::vec3(0.f, 0.f, 0.f);
	this->CameraUp = glm::vec3(0.f, 1.f, 0.f);

}

glm::mat4 Camera::CreateLookAtMatrix()
{

//	std::cout << "Camera : " << this->CameraPosition.x << " , " << this->CameraPosition.y << " , " << this->CameraPosition.z << std::endl;
	return glm::lookAt(this->CameraPosition, this->CameraFocusOn, this->CameraUp);
	
}








RETURNVOID Scene3D::NewMesh(std::string path){

	Object3D* mesh = new Object3D(path.c_str());
	this->MeshMap.insert(std::make_pair(path, mesh));
	return RETURNVOID();
}

std::shared_ptr<Model> Scene3D::NewModel(std::string path)
{// path로 mesh를 찾아서 model 생성 
	auto iter = this->MeshMap.find(path);
	
	if (iter == this->MeshMap.end()) {
		std::cout << "Mesh is not Definded" << std::endl;
		return nullptr;
	}

	std::shared_ptr<Model> model = 	iter->second->NewModel();

	this->ModelArray.push_back(model);

	return model;
}

RETURNVOID Scene3D::Render(){

	GLuint PerspectiveLocation = glGetUniformLocation(this->Shaderid, "perspective");
	GLuint CameraLookAtLocation = glGetUniformLocation(this->Shaderid, "lookat");

	
	glm::mat4 Lookat = this->MainCamera.CreateLookAtMatrix();
	glm::mat4 Perspective = glm::perspective(glm::radians(this->MainCamera.GetFov()), GET_WINDOW_WIDTHF / GET_WINDOW_HEIGHTF, this->NearZ, this->FarZ);



	glUniformMatrix4fv(CameraLookAtLocation,1,GL_FALSE,glm::value_ptr(Lookat));
	glUniformMatrix4fv(PerspectiveLocation, 1, GL_FALSE, glm::value_ptr(Perspective));

	for (auto& i : this->ModelArray) {
		i->Render();
	}
	
	return RETURNVOID();
}

RETURNVOID Scene3D::Reshape(int w, int h){
	return glViewport(0, 0, w, h);
}

RETURNVOID Scene3D::ScaleModel(glm::vec3 scale)
{
	for (auto& i : this->ModelArray) {
		i->Transition(ObjectScale, scale);
	}

	return RETURNVOID();
}

RETURNVOID Scene3D::MoveCamera(CameraMovement M, glm::vec3 Vector)
{
	switch (M)
	{
	case Realative:

		this->MainCamera.CameraMovement_R(Vector);


		break;
	case Absolute:

		this->MainCamera.CameraMovement_A(Vector);

		break;
	default:
		break;
	}


	return RETURNVOID();
}

RETURNVOID Coordinate::Init() {

	const GLfloat Arrays[18] = {
		-100.f,0.f,0.f,
		100.f,0.f,0.f,

		0.f,-100.f,0.f,
		0.f,100.f,0.f,

		0.f,0.f,-100.f,
		0.f,0.f,100.f
	};


	Color3f Xcolor{ 1.f,0.f,0.f};
	Color3f Ycolor{ 0.f,1.f,0.f};
	Color3f Zcolor{ 0.f,0.f,1.f};


	const GLfloat ColorArrays[18] = {
		Xcolor.r,Xcolor.g,Xcolor.b,
		Xcolor.r,Xcolor.g,Xcolor.b,

		Ycolor.r,Ycolor.g,Ycolor.b,
		Ycolor.r,Ycolor.g,Ycolor.b,

		Zcolor.r,Zcolor.g,Zcolor.b,
		Zcolor.r,Zcolor.g,Zcolor.b
	};




	glGenVertexArrays(1, &(this->VAO));
	glBindVertexArray(this->VAO);


	glGenBuffers(1, &(this->VBO.Position));
	glGenBuffers(1, &(this->VBO.Color));

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, Arrays, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE ,0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, ColorArrays, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);





	return RETURNVOID();
}

RETURNVOID Coordinate::Render(){





	glBindVertexArray(this->VAO);
	glDrawArrays(GL_LINES, 0, 6);

	return RETURNVOID();
}
