

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Shader.h"
#include "FileReader.h"





void InitBuffer();

GLvoid drawScene();
GLvoid ReShape(int w, int h);




const GLfloat VertexData[] = {
	0.5f , 0.5f , 0.0f,			1.0f, 0.0f, 0.0f,
	0.5f , -0.5f, 0.0f,			0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,			0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f , 0.0f,			1.0f, 1.0f, 1.0f	
};

const GLuint index[] = {
	0,1,3,
	1,2,3
};


Shader* TestShader;

void InitShader();



int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(800,600,"THIS IS TEST");


	TestShader = new Shader;


	TestShader->Resister_ShaderSource("Vertex.glsl", Vertex);
	TestShader->Resister_ShaderSource("Fragment.glsl", Fragment);

	TestShader->Create_Shader(Vertex);
	TestShader->Create_Shader(Fragment);


	TestShader->LINK_SHADER();


	MAINWINDOW->ResisterCallBackFunctions(Scene3_CallBackFunctions::CreateCallBackFuctions());
	MAINWINDOW->Run();


}



void InitShader() {


}





