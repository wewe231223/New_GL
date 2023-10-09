#pragma once

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>



// 컴퓨터에서 
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/ext/matrix_transform.hpp>


//
//#include <gl/glm/glm.hpp>
//#include <gl/glm/ext.hpp>
//#include <gl/glm/gtc/matrix_transform.hpp>



#include "Definition.h"

#define UPDATE glutPostRedisplay()


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





