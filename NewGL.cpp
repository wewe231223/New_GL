

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
#include "Scene10.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DBG_NEW
//#endif // DBG_NEW
//#endif // _DEBUG





int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(static_cast<int>(DEFAULT_SCREEN_WIDTH),static_cast<int>(DEFAULT_SCREEN_HEIGHT),"THIS IS TEST");



	// # 10
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene6());

	// # 11
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene7());

	// # 12
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene9());

	// # 13
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene8());

	MAINWINDOW->ResisterCallBackFunctions(Scene10_::Run());




	MAINWINDOW->Run();


}


