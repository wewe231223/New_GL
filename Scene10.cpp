#include "Scene10.h"



RETURNVOID Scene10::Init()
{
	this->Init_ShaderID();

	this->NewMesh("teapot.obj");
	this->NewModel("teapot.obj");

	

	return RETURNVOID();
}



Scene10 SC10;


RETURNVOID Scene10_::Draw()
{
	// �������� ����
	glClearColor(0.f,0.f,0.f,0.0f);
	// ������ ������ ��ü�� ĥ�ϱ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::cout << "Draw!" << std::endl;
	SC10.Render();

	return glutSwapBuffers();
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