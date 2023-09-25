

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"
#include "FileReader.h"



//void Make_VertexShaders();
//void Make_FragmentShaders();
//GLuint Make_shadeProgram();
GLvoid drawScene();
GLvoid ReShape(int w, int h);


GLint Width, Height;
GLuint shaderProgramId;
GLuint vertexShader;
GLuint fragmentShader;





	

int main(int argc, char** argv) {

	FileReader Fr("Vertex.glsl");
	Fr.Test();

	INIT(argc, argv);


	GLW* MAINWINDOW = new GLW("THIS IS TEST");




	glutSetWindow(1);
	//MAINWINDOW->ResisterCallBackFunctions(Scene1_CallBackFunctions::CreateCallBackFunction());
	//MAINWINDOW->ResisterCallBackFunctions(Scene2_CallBackFunctions::CreateCallBackFunction());
	CallbackFunc Cf;





	//Make_VertexShaders();
	//Make_FragmentShaders();




	//shaderProgramId = Make_shadeProgram();



	Cf.DrawCall = drawScene;
	Cf.ReShapeCall = ReShape;



	MAINWINDOW->ResisterCallBackFunctions(Cf);
	

	MAINWINDOW->Run();

}


GLvoid drawScene() {
	Color4f BackGroundColor{ 0.f,0.f,1.f,1.f};

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgramId);


	glPointSize(5.0f);




}


GLvoid ReShape(int w, int h) {
	glViewport(0, 0, w, h);
}


