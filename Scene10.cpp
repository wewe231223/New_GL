#include "Scene10.h"


RETURNVOID Scene10::Init()
{
	
      Scene3D::Init();
	


	this->NewMesh("Cube.obj");
	std::shared_ptr<Model> cube = this->NewModel("Cube.obj");
	this->ScaleModel(glm::vec3(2.f,2.f, 2.f));


	this->NewMesh("Tetrahedon.obj");
	std::shared_ptr<Model> teapot1 = this->NewModel("Tetrahedon.obj");
	teapot1->Transition(Movement, glm::vec3(10.f,0.f,0.f));


	return RETURNVOID();
}



Scene10 SC10;


RETURNVOID Scene10_::Draw()
{
	// 바탕색을 설정
	glClearColor(0.f,0.f,0.f,0.0f);
	// 설정된 색으로 전체를 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SC10.Render();

	SC10.CoordRender();

	return glutSwapBuffers();
}

RETURNVOID Scene10_::Reshape(int w, int h)
{

	glViewport(0, 0, w, h);
	return RETURNVOID();
}


RETURNVOID Scene10_::KeyboardSpcialInput(int key, int, int)
{
	


	glm::vec3 CameraVec{};
	
	
	if (GetAsyncKeyState(VK_LEFT) & 0x08000) {
		CameraVec.x += 0.1f;
	}
	
	if (GetAsyncKeyState(VK_RIGHT) & 0x08000) {
		CameraVec.x -= 0.1f;
	}


	if (GetAsyncKeyState(VK_UP) & 0x08000) {
		CameraVec.z += 0.1f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x08000) {
		CameraVec.z -= 0.1f;
	}


	if (GetAsyncKeyState(VK_PRIOR) & 0x08000) {
		CameraVec.y += 0.1f;
	}

	if (GetAsyncKeyState(VK_NEXT) & 0x08000) {
		CameraVec.y -= 0.1f;
	}


	SC10.MoveCamera(Realative, CameraVec);

	return UPDATE;
}



CallbackFunc Scene10_::Run()
{
	CallbackFunc result{};
	SC10.Init();


	result.DrawCall = Scene10_::Draw;
	result.ReShapeCall = Scene10_::Reshape;
	result.KeyboardSpecialInputCall = Scene10_::KeyboardSpcialInput;



	return result;
}
