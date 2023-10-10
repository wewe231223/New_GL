

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"
#include "Object3D.h"



//
//#include "Scene6.h"
//#include "Scene7.h"
//#include "Scene8.h"
//#include "Scene9.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // DBG_NEW
#endif // _DEBUG


using namespace std;

Shader* MainShader;
const glm::vec3 background_rgb = glm::vec3(0.0f, 0.0f, 0.0f);


Object3D test{};
Model* Model1{};
Model* Model2{};



bool isCube = true;


//--- 콜백 함수: 그리기 콜백 함수 
GLvoid drawScene()
{
	// 바탕색을 설정
	glClearColor(background_rgb.x, background_rgb.y, background_rgb.z, 1.0f);
	// 설정된 색으로 전체를 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);









	Model1->Render();
	//Model2->Render();


	glutSwapBuffers();
}

//--- 콜백 함수: 다시 그리기 콜백 함수 
GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}


RETURNVOID DummyDraw() {

}

RETURNVOID DummyReshape(int w,int h) {

}


int main(int argc, char** argv)
{




	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW((int)DEFAULT_SCREEN_WIDTH, (int)DEFAULT_SCREEN_HEIGHT, "Computer Graphics");

	MainShader = new Shader;



	MainShader->Resister_ShaderSource("3D_Vertex_Shader.glsl", Vertex);
	MainShader->Create_Shader(Vertex);
	MainShader->Resister_ShaderSource("3D_Fragment_Shader.glsl", Fragment);
	MainShader->Create_Shader(Fragment);

	MainShader->LINK_SHADER();

	
	

	test.Initialize("teapot.obj", MainShader->GetInfo(ShaderProgramID));
	test.Buffering();

	Model1 = test.NewModel();
	Model2 = test.NewModel();


	//확대축소변환 
	Model1->Transition(ObjectScale, glm::vec3(0.1f, 0.1f, 0.1f));

	//이게 카메라 변환 
	Model1->Transition(RotateX, glm::vec3(30.f, 0.f, 0.f));
	Model1->Transition(RotateY, glm::vec3(0.f,-40.f,0.f));
	Model1->Transition(Movement, glm::vec3(-1.f, 0.f,-10.f));


	glutDisplayFunc(drawScene);													// 출력 함수의 지정
	glutReshapeFunc(Reshape);													// 다시 그리기 함수 지정

	glutMainLoop();																// 이벤트 처리 시작
}



//
//int main(int argc, char** argv) {
//	INIT(&argc, argv);
//	GLW* MAINWINDOW = new GLW(static_cast<int>(DEFAULT_SCREEN_WIDTH),static_cast<int>(DEFAULT_SCREEN_HEIGHT),"THIS IS TEST");
//
//
//	MainShader = new Shader;
//
//	MainShader->Resister_ShaderSource("Vertex.glsl", Vertex);
//	MainShader->Resister_ShaderSource("Fragment.glsl", Fragment);
//	MainShader->Create_Shader(Vertex);
//	MainShader->Create_Shader(Fragment);
//	MainShader->LINK_SHADER();
//
//	// # 10
//	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene6());
//
//	// # 11
//	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene7());
//
//	// # 12
//	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene9());
//
//	// # 13
//	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene8());
//
//
//
//
//
//	MAINWINDOW->Run();
//
//
//}
//
//
