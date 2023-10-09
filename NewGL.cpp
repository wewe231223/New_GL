

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"
#include "Object3D.h"




#include "Scene6.h"
#include "Scene7.h"
#include "Scene8.h"
#include "Scene9.h"

#include "FileReader.h"

using namespace std;

Shader* MainShader;
const glm::vec3 background_rgb = glm::vec3(0.0f, 0.0f, 0.0f);

bool isCulling = true;
bool isFill = true;
double xMove = 0.0, yMove = 0.0, zMove = 0.0;
float xRotateAni = 0.0f;
float yRotateAni = 0.0f;
int rotateKey = 0;

GLfloat mx = 0.0f;
GLfloat my = 0.0f;

Object3D test{};




bool isCube = true;


//--- 콜백 함수: 그리기 콜백 함수 
GLvoid drawScene()
{
	// 바탕색을 설정
	glClearColor(background_rgb.x, background_rgb.y, background_rgb.z, 1.0f);
	// 설정된 색으로 전체를 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	std::cout << "draw " << std::endl;
	test.Render();
	test.Transition(Movement, glm::vec3(0.01f, 0.001f, 0.01f));
	test.Buffering();
	test.Render();



	glutSwapBuffers();
}

//--- 콜백 함수: 다시 그리기 콜백 함수 
GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

GLvoid TimerFunction1(int value)
{
	glutPostRedisplay(); // 화면 재 출력
	if (rotateKey == 1)
		xRotateAni += 1.f;
	if (rotateKey == 2)
		xRotateAni -= 1.f;
	if (rotateKey == 3)
		yRotateAni += 1.f;
	if (rotateKey == 4)
		yRotateAni -= 1.f;
	glutTimerFunc(100, TimerFunction1, 1);
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'c':
		isCube = true;
		break;
	case 'p':
		isCube = false;
		break;
	case 'h':
		isCulling = 1 - isCulling;
		break;
	case 'x':
		test.Transition(RotateX, glm::vec3(1.f, 0.f, 0.f));
		break;
	case 'X':
		rotateKey = 2;
		glutTimerFunc(100, TimerFunction1, 1);
		break;
	case 'y':
		
	
		break;
	case 'Y':
		rotateKey = 4;
		glutTimerFunc(100, TimerFunction1, 1);
		break;
	case 'w':
		isFill = false;
		break;
	case 'W':
		isFill = true;
		break;
	case 'j':
			
		break;
	case 'l':
		xMove += 0.1;
		break;
	case 'i':
		yMove += 0.1;
		break;
	case 'k':
		yMove -= 0.1;
		break;
	case 'S':
		rotateKey = 0;
		xMove = 0.0, yMove = 0.0f, zMove = 0.0f;
		xRotateAni = 0.0f;
		yRotateAni = 0.0f;
		break;
	}
	glutPostRedisplay(); //--- 배경색이 바뀔때마다 출력 콜백함수를 호출하여 화면을 refresh 한다
}

void Idle() {
	//test.Transition(RotateX, glm::vec3(0.f, 0.f, 0.f));
	UPDATE;
}

void Mouse(int button, int state, int x, int y)
{
	GLfloat half_w = DEFAULT_SCREEN_WIDTH / 2.0f;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mx = (x - half_w) / half_w;
		my = (half_w - y) / half_w;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	//윈도우 생성
	glutInit(&argc, argv);																// glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);				// 디스플레이 모드 설정
	glutInitWindowPosition(10, 10);								// 윈도우의 위치 지정
	glutInitWindowSize(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);									// 윈도우의 크기 지정
	glutCreateWindow("Example1");												// 윈도우 생성(윈도우 이름)

	//GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		std::cout << "GLEW Initialized\n";
	}

	MainShader = new Shader;



	MainShader->Resister_ShaderSource("3D_Vertex_Shader.glsl", Vertex);
	MainShader->Create_Shader(Vertex);
	MainShader->Resister_ShaderSource("3D_Fragment_Shader.glsl", Fragment);
	MainShader->Create_Shader(Fragment);

	MainShader->LINK_SHADER();

	

	test.Initialize("teapot.obj", MainShader->GetInfo(ShaderProgramID));
	test.Transition(ObjectScale, glm::vec3(0.1f, 0.1f, 0.1f));
	test.Transition(RotateX, glm::vec3(30.f, 0.f, 0.f));
	test.Transition(RotateY, glm::vec3(0.f, 30.f, 0.f));
	//test.SetProperty(RandColor, true);
	test.Buffering();


	test.Transition(Movement, glm::vec3(0.1f, 0.1f, 0.1f));
	test.Buffering();



	glutDisplayFunc(drawScene);													// 출력 함수의 지정
	glutReshapeFunc(Reshape);														// 다시 그리기 함수 지정
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutIdleFunc(Idle);
	glutMainLoop();																			// 이벤트 처리 시작
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
