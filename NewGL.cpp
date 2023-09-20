

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"



int main(int argc, char** argv) {

	INIT(argc, argv);


	GLW* MAINWINDOW = new GLW("THIS IS TEST");




	glutSetWindow(1);

	MAINWINDOW->ResisterCallBackFunctions(CallBackFunctions::CreateCallBackFunction());
	MAINWINDOW->Run();

}

