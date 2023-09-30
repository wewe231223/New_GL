

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"

#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "FileReader.h"


Shader* MainShader;


int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(800,600,"THIS IS TEST");


	MainShader = new Shader;


	MainShader->Resister_ShaderSource("Vertex.glsl", Vertex);
	MainShader->Resister_ShaderSource("Fragment.glsl", Fragment);

	MainShader->Create_Shader(Vertex);
	MainShader->Create_Shader(Fragment);


	MainShader->LINK_SHADER();


	//MAINWINDOW->ResisterCallBackFunctions(Scene3_CallBackFunctions::CreateCallBackFuctions());
	
	
	
	MAINWINDOW->ResisterCallBackFunctions(Scene4_CallBackFunctions::Resister_Scene4());
	MAINWINDOW->Run();


}






