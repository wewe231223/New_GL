#pragma once
#include "GLH.h"





inline RETURNVOID DEFAULTDRAW(PARAMETERVOID) {
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

inline RETURNVOID DEFAULTRESHAPE(int w, int h) {
	glViewport(0, 0, w, h);
}







inline RETURNVOID INIT(int* argc, char** argv) {

#ifndef GLINIT_
#define GLINIT_
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glewExperimental = GL_TRUE;
	glewInit();
#endif
}

class GLW
{
private:
	CallbackFunc WindowCallBackFuctions{};

public:
	GLW(const char*);
	GLW(int,int,const char*);
	


	RETURNVOID ResisterCallBackFunctions(CallbackFunc);


	RETURNVOID Run();


};

