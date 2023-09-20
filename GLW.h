#pragma once
#include "GLH.h"


#define INITPOSX 300
#define INITPOSY 300




inline void DEFAULTDRAW(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

inline void DEFAULTRESHAPE(int w, int h) {
	glViewport(0, 0, w, h);
}



class GLW
{
private:
	CallbackFunc WindowCallBackFuctions{};

public:
	GLW(int,int,const char*);
	


	RETURNVOID ResisterCallBackFunctions(PARAMETERVOID);


	RETURNVOID Run();


};

