#include "Scene3D.h"

Camera::Camera(){

	this->CameraPosition = glm::vec3(20.f, 5.f, -5.f);
	this->CameraFocusOn = glm::vec3(1.f, 0.f, 0.f);
	this->CameraUp = glm::vec3(0.f, 0.f, 1.f);

}

glm::mat4 Camera::CreateLookAtMatrix()
{
	return glm::lookAt(this->CameraPosition, this->CameraFocusOn, this->CameraUp);
}



RETURNVOID Scene3D::NewMesh(std::string path){

	Object3D* mesh = new Object3D(path.c_str());
	this->MeshMap.insert(std::make_pair(path, mesh));
	return RETURNVOID();
}

RETURNVOID Scene3D::NewModel(std::string path)
{// path로 mesh를 찾아서 model 생성 
	auto iter = this->MeshMap.find(path);
	
	if (iter == this->MeshMap.end()) {
		std::cout << "Mesh is not Definded" << std::endl;
		return RETURNVOID();
	}

	Model* model = 	iter->second->NewModel();

	this->ModelArray.push_back(model);

	return RETURNVOID();
}

RETURNVOID Scene3D::Render(){

	GLuint PerspectiveLocation = glGetUniformLocation(this->Shaderid, "perspective");
	GLuint CameraLookAtLocation = glGetUniformLocation(this->Shaderid, "lookat");

	
	glm::mat4 Lookat = this->MainCamera.CreateLookAtMatrix();
	glm::mat4 Perspective = glm::perspective(glm::radians(this->FovY), GET_WINDOW_WIDTHF / GET_WINDOW_HEIGHTF, this->NearZ, this->FarZ);



	glUniformMatrix4fv(CameraLookAtLocation,1,GL_FALSE,glm::value_ptr(Lookat));
	glUniformMatrix4fv(PerspectiveLocation, 1, GL_FALSE, glm::value_ptr(Perspective));


	//glm::mat4 one = glm::mat4(1.f);

	//glUniformMatrix4fv(CameraLookAtLocation, 1, GL_FALSE, glm::value_ptr(one));
	//glUniformMatrix4fv(PerspectiveLocation, 1, GL_FALSE, glm::value_ptr(one));


	this->ModelArray[0]->Render();

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



