

#include <iostream>
#include "GLH.h"
#include "GLW.h"

#include "Shader.h"



#include "Scene6.h"
#include "Scene7.h"

#include "FileReader.h"


Shader* MainShader;


int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT,"THIS IS TEST");


	MainShader = new Shader;


	MainShader->Resister_ShaderSource("Vertex.glsl", Vertex);
	MainShader->Resister_ShaderSource("Fragment.glsl", Fragment);

	MainShader->Create_Shader(Vertex);
	MainShader->Create_Shader(Fragment);


	MainShader->LINK_SHADER();


	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene5());
	//MAINWINDOW->ResisterCallBackFunctions(ResisterScene6());
	MAINWINDOW->ResisterCallBackFunctions(ResisterScene7());

	MAINWINDOW->Run();


}






