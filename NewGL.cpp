

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"
#include "FileReader.h"



void Make_VertexShaders();
void Make_FragmentShaders();
GLuint Make_shadeProgram();
GLvoid drawScene();
GLvoid ReShape(int w, int h);


GLint Width, Height;
GLuint shaderProgramId;

GLuint fragmentShader{};





	

int main(int argc, char** argv) {


	INIT(&argc, argv);


	GLW* MAINWINDOW = new GLW(800,600,"THIS IS TEST");




	//MAINWINDOW->ResisterCallBackFunctions(Scene1_CallBackFunctions::CreateCallBackFunction());
	//MAINWINDOW->ResisterCallBackFunctions(Scene2_CallBackFunctions::CreateCallBackFunction());

	CallbackFunc CF;


	CF.DrawCall = drawScene;
	CF.ReShapeCall = ReShape;




	Make_VertexShaders();
	Make_FragmentShaders();
	shaderProgramId = Make_shadeProgram();




	MAINWINDOW->ResisterCallBackFunctions(CF);

	MAINWINDOW->Run();



	//int width = 500;
	//int height = 500;


	//glutInit(&argc, argv);

	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//glutInitWindowPosition(100, 100);

	//glutInitWindowSize(width, height);


	//glutCreateWindow("Example 1");


	//glewExperimental = GL_TRUE;
	//glewInit();


	//Make_VertexShaders();
	//Make_FragmentShaders();
	//shaderProgramId = Make_shadeProgram();


	//glutDisplayFunc(drawScene);
	//glutReshapeFunc(ReShape);

	//glutMainLoop();





}








GLvoid drawScene() {
	Color4f BackGroundColor{ 0.f,0.f,1.f,1.f};

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgramId);


	glPointSize(5.0f);

	glDrawArrays(GL_POINTS, 0, 1);

	glutSwapBuffers();


}


GLvoid ReShape(int w, int h) {
	glViewport(0, 0, w, h);
}

#define _CRT_SECURE_NO_WARNINGS

GLuint vertexShader{};
void Make_VertexShaders(){
	GLchar* vertexSource;
	FileReader Fr("Vertex.glsl");


	vertexSource = Fr.GetSource();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);




	glShaderSource(vertexShader, 1, &vertexSource, NULL);

	glCompileShader(vertexShader);

	GLint result;
	GLchar errorLog[512]{};

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);

	if (!result) {

		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR : VERTEX SHADER COMPILE FAILED" << std::endl << errorLog << std::endl;
		return;
	}
	else {
		std::cerr << "VERTEX SHADER SUCESSFULLY COMPILED" << std::endl;
	}



}
















void Make_FragmentShaders()
{
	GLchar* FragmentSource;
	FileReader Fr("Fragment.glsl");


	FragmentSource = Fr.GetSource();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &FragmentSource, NULL);

	glCompileShader(fragmentShader);

	GLint result;
	GLchar errorLog[512]{};

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);

	if (!result) {

		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);
		std::cerr << "ERROR : FRAGMENT SHADER COMPILE FAILED" << std::endl << errorLog << std::endl;
		return;
	}
	else {
		std::cerr << "FRAGMENT SHADER SUCESSFULLY COMPILED" << std::endl;
	}


}




GLuint Make_shadeProgram()
{

	GLuint ShaderId{};

	ShaderId = glCreateProgram();

	glAttachShader(ShaderId, vertexShader);
	glAttachShader(ShaderId, fragmentShader);

	glLinkProgram(ShaderId);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	GLint result;
	GLchar errorLog[512]{};

	glGetShaderiv(vertexShader, GL_LINK_STATUS, &result);

	if (!result) {

		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR : SHADER LINK FAILED" << std::endl << errorLog << std::endl;
		return -1;
	}
	else {
		std::cerr << "SHADERS SUCESSFULLY LINKED" << std::endl;
	}


	glUseProgram(ShaderId);


	return GLuint();
}