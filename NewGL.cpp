

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"
#include "Object3D.h"




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


	MAINWINDOW->ResisterCallBackFunctions(Scene10_::Run());




	MAINWINDOW->Run();


}


