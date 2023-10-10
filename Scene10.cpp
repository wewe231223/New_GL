#include "Scene10.h"



RETURNVOID Scene10::Init()
{
	this->Init_ShaderID();

	this->NewMesh("Cube.obj");
	this->NewModel("Cube.obj");

	this->ScaleModel(glm::vec3(0.1f, 0.1f, 0.1f));

	return RETURNVOID();
}



Scene10 SC10;


RETURNVOID Scene10_::Draw()
{
	// 바탕색을 설정
	glClearColor(0.f,0.f,0.f,0.0f);
	// 설정된 색으로 전체를 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::cout << "Draw!" << std::endl;
	SC10.Render();

	return RETURNVOID();
}

RETURNVOID Scene10_::Reshape(int w, int h)
{

	glViewport(0, 0, w, h);
	return RETURNVOID();
}

CallbackFunc Scene10_::Run()
{
	CallbackFunc result{};
	SC10.Init();


	result.DrawCall = Scene10_::Draw;
	result.ReShapeCall = Scene10_::Reshape;




	return result;
}
