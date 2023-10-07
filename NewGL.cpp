

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"



#include "Scene6.h"
#include "Scene7.h"
#include "Scene8.h"
#include "Scene9.h"

#include "FileReader.h"


Shader* MainShader;


RETURNVOID Draw();
RETURNVOID ReShape(int w, int h);

GLUquadricObj* qobj;


int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(static_cast<int>(DEFAULT_SCREEN_WIDTH),static_cast<int>(DEFAULT_SCREEN_HEIGHT),"THIS IS TEST");


	MainShader = new Shader;

	MainShader->Resister_ShaderSource("Vertex.glsl", Vertex);
	MainShader->Resister_ShaderSource("Fragment.glsl", Fragment);
	MainShader->Create_Shader(Vertex);
	MainShader->Create_Shader(Fragment);
	MainShader->LINK_SHADER();

	// # 10
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene6());

	// # 11
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene7());

	// # 12
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene9());

	// # 13
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene8());



	glutDisplayFunc(Draw);
	glutReshapeFunc(ReShape);




	MAINWINDOW->Run();


}



RETURNVOID Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);

	gluLookAt(10.0f, 0.0f, 12.0f, 0.0f, 0.0f, -10.f, 0.0f, 1.f, 0.f);

	qobj = gluNewQuadric();

	 gluQuadricDrawStyle(qobj, GLU_LINE);
	 gluQuadricNormals(qobj, GLU_SMOOTH);
	 gluQuadricOrientation(qobj, GLU_OUTSIDE);
	 gluSphere(qobj, 0.5f, 50, 50); // 객체 만들기

	 glutSwapBuffers();

	return RETURNVOID();
}


RETURNVOID ReShape(int w, int h)
{
	glViewport(0, 0, w, h);
	return RETURNVOID();
}


