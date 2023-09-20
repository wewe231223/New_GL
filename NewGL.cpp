

#include <iostream>
#include "GLH.h"
#include "GLW.h"




int main(int argc, char** argv) {

	INIT(argc, argv);


	GLW* MAINWINDOW = new GLW(300, 300, "TEST");

	MAINWINDOW->ResisterCallBackFunctions();

	MAINWINDOW->Run();

}

