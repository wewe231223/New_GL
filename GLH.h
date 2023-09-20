#pragma once

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include "Definition.h"



typedef struct _CALLBACKFUNC {

	GLvoid(*DrawCall)					(GLvoid) = nullptr;
	GLvoid(*ReShapeCall)				(int, int) = nullptr;
	GLvoid(*KeyboardInputCall)			(unsigned char, int, int) = nullptr;
	GLvoid(*KeyboardSpecialInputCall)	(int, int, int) = nullptr;
	GLvoid(*KeyboardSpecialOffCall)		(int, int, int) = nullptr;
	GLvoid(*KeyboardOffCall)			(unsigned char, int, int) = nullptr;
	GLvoid(*TimerCall)					(int) = nullptr;
	GLvoid(*IdleCall)					(GLvoid) = nullptr;
	GLvoid(*MouseCall)					(int, int, int, int) = nullptr;
	GLvoid(*MouseDragCall)				(int, int) = nullptr;




}CallbackFunc;





