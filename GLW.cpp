#include "GLW.h"
#include <iostream>



GLW::GLW(int W, int H,const char* title) {
	glutInitWindowSize(W, H);
	glutInitWindowPosition(DEFAULT_SCREEN_POSITION_X, DEAFAULT_SCREEN_POSITION_Y);

	glutCreateWindow(title);


	if (glewInit() != GLEW_OK) {
		std::cerr << "FAIL TO INIT" << std::endl;
	}
	else {
		std::cout << "INIT GLEW!" << std::endl;
	}




}


GLW::GLW(const char* title) {
	glutInitWindowSize(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
	glutInitWindowPosition(DEFAULT_SCREEN_POSITION_X, DEAFAULT_SCREEN_POSITION_Y);

	glutCreateWindow(title);


	if (glewInit() != GLEW_OK) {
		std::cerr << "FAIL TO INIT" << std::endl;
	}
	else {
		std::cout << "INIT GLEW!" << std::endl;
	}
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

	if (CF.IdleCall != nullptr) {
		glutIdleFunc(CF.IdleCall);
	}


	if (CF.KeyboardInputCall != nullptr) {
		glutKeyboardFunc(CF.KeyboardInputCall);
	}

	if (CF.KeyboardOffCall != nullptr) {
		glutKeyboardUpFunc(CF.KeyboardOffCall);
	}


	if (CF.MouseCall != nullptr) {
		glutMouseFunc(CF.MouseCall);
	}

	if (CF.MouseDragCall != nullptr) {
		glutMotionFunc(CF.MouseDragCall);
	}

	if (CF.TimerCall != nullptr) {
		glutTimerFunc(10, CF.TimerCall, 1);
	}


}

RETURNVOID GLW::Run() {
	glutMainLoop();
}
