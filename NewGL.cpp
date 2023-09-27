

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"
#include "Shader.h"
#include "FileReader.h"




void InitBuffer();

GLvoid drawScene();
GLvoid ReShape(int w, int h);




const GLfloat VertexData[] = {
	0.5f , 0.5f , 0.0f,			1.0f, 0.0f, 0.0f,
	0.5f , -0.5f, 0.0f,			0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,			0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f , 0.0f,			0.1f, 0.1f, 0.1f	
};

const GLuint index[] = {
	0,1,3,
	1,2,3
};


Shader* TestShader;
void InitShader();


GLuint VAO, VBO, EBO;

int main(int argc, char** argv) {


	INIT(&argc, argv);


	GLW* MAINWINDOW = new GLW(800,600,"THIS IS TEST");



	//MAINWINDOW->ResisterCallBackFunctions(Scene1_CallBackFunctions::CreateCallBackFunction());
	//MAINWINDOW->ResisterCallBackFunctions(Scene2_CallBackFunctions::CreateCallBackFunction());

	CallbackFunc CF;



	InitBuffer();
	InitShader();



	CF.DrawCall = drawScene;
	CF.ReShapeCall = ReShape;

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



void InitShader() {

	TestShader = new Shader;


	TestShader->Resister_ShaderSource("Vertex.glsl", Vertex);
	TestShader->Resister_ShaderSource("Fragment.glsl", Fragment);

	TestShader->Create_Shader(Vertex);
	TestShader->Create_Shader(Fragment);


	TestShader->LINK_SHADER();
}




GLvoid drawScene() {
	Color4f BackGroundColor{ 0.f,0.f,0.f,1.f};

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	


	glutSwapBuffers();


}


GLvoid ReShape(int w, int h) {
	glViewport(0, 0, w, h);
}



void InitBuffer() {


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);



	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), ( (void*)(3 * sizeof(float) ) ));
	glEnableVertexAttribArray(1);



	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //--- GL_ELEMENT_ARRAY_BUFFER 버퍼 유형으로 바인딩
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);









}