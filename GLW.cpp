#include "GLW.h"
#include <iostream>



GLW::GLW(int W, int H,const char* title) {
	glutInitWindowSize(W, H);
	glutInitWindowPosition(DEFAULT_SCREEN_POSITION_X, DEAFAULT_SCREEN_POSITION_Y);

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


GLW::GLW(const char* title) {
	glutInitWindowSize(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
	glutInitWindowPosition(DEFAULT_SCREEN_POSITION_X, DEAFAULT_SCREEN_POSITION_Y);

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




RETURNVOID GLW::ResisterCallBackFunctions(CallbackFunc CF) {

	

	
	if (CF.DrawCall != nullptr) {
		glutDisplayFunc(CF.DrawCall);
	}
	else {
		glutDisplayFunc(DEFAULTDRAW);
	}

	if (CF.ReShapeCall != nullptr) {
		glutReshapeFunc(CF.ReShapeCall);
	}
	else {
		glutReshapeFunc(DEFAULTRESHAPE);
	}



}

RETURNVOID GLW::Run() {
	glutMainLoop();
}
