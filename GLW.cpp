#include "GLW.h"

#include <iostream>

GLW::GLW(int W, int H,const char* title) {
	glutInitWindowSize(W, H);
	glutInitWindowPosition(INITPOSX, INITPOSY);

	glutCreateWindow(title);


#ifndef _GLEWINITED
#define _GLEWINITED
	if (glewInit() != GLEW_OK) {
		std::cerr << "FAIL TO INIT" << std::endl;
	}
	else {
		std::cout << "INIT GLEW!" << std::endl;
	}
#endif // !_GLEWINITED






}




RETURNVOID GLW::ResisterCallBackFunctions(PARAMETERVOID) {

	if (this->WindowCallBackFuctions.DrawCall != nullptr) {
		glutDisplayFunc(this->WindowCallBackFuctions.DrawCall);
	}
	else {
		glutDisplayFunc(DEFAULTDRAW);
	}

	if (this->WindowCallBackFuctions.ReShapeCall != nullptr) {
		glutReshapeFunc(this->WindowCallBackFuctions.ReShapeCall);
	}
	else {
		glutReshapeFunc(DEFAULTRESHAPE);
	}



}

RETURNVOID GLW::Run() {
	glutMainLoop();
}
