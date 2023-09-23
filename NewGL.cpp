

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"




void Make_VertexShaders();
void Make_VertexShaders();
GLuint Make_shadeProgram();
GLvoid drawScene();
GLvoid ReShape(int w, int h);


	

int main(int argc, char** argv) {

	INIT(argc, argv);


	GLW* MAINWINDOW = new GLW("THIS IS TEST");




	glutSetWindow(1);
	//MAINWINDOW->ResisterCallBackFunctions(Scene1_CallBackFunctions::CreateCallBackFunction());
	MAINWINDOW->ResisterCallBackFunctions(Scene2_CallBackFunctions::CreateCallBackFunction());
	MAINWINDOW->Run();

}

