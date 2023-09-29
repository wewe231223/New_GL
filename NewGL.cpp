

#include <iostream>
#include "GLH.h"
#include "GLW.h"


#include "Scene1.h"
#include "Scene2.h"
#include "Shader.h"
#include "FileReader.h"
#include "Object.h"




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


GLuint VAO, VBO, EBO;

float V1[3] = {	-0.5f,	-0.5f,	0.0f};
float V2[3] = {	0.5f,	-0.5f,0.0f };
float V3[3] = { 0.0f,0.5f,0.0f };


float VC1[3] = { 1.0f,0.0f,0.0f };
float VC2[3] = { 0.0f,1.0f,0.0f };
float VC3[3] = { 0.0f,0.0f,1.0f };

VertexObject* Vo;

int main(int argc, char** argv) {
	INIT(&argc, argv);
	GLW* MAINWINDOW = new GLW(800,600,"THIS IS TEST");



	CallbackFunc CF;

	

	InitShader();
	//InitBuffer();

	Vo = new VertexObject;
	Vo->Init();
	Vo->ResisterVertex(Vertex_1, TVertex, V1);
	Vo->ResisterVertex(Vertex_2, TVertex, V2);
	Vo->ResisterVertex(Vertex_3, TVertex, V3);

	Vo->ResisterVertex(Vertex_1, TColor, VC1);
	Vo->ResisterVertex(Vertex_2, TColor, VC2);
	Vo->ResisterVertex(Vertex_3, TColor, VC3);


	CF.DrawCall = drawScene;
	CF.ReShapeCall = ReShape;

	MAINWINDOW->ResisterCallBackFunctions(CF);

	MAINWINDOW->Run();


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

	Color4f BackGroundColor{ 1.f,1.f,1.f,1.f};

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

	//glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	glUseProgram(TestShader->GetInfo(ShaderProgramID));
	Vo->Render();

	glutSwapBuffers();


}


GLvoid ReShape(int w, int h) {
	glViewport(0, 0, w, h);
}



void InitBuffer() {

	// 쓰기위한 VAO 생성
	glGenVertexArrays(1, &VAO);
	
	//정점 쓰기위한 VBO 생성
	glGenBuffers(1, &VBO);
	
	// 이제부터 VAO를 사용한다 
	glBindVertexArray(VAO);
	// 이제부터 VBO를 사용한다 
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	// VertexData의 내용을 가져온다
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);


	// 아래 두 행위는 총 6개의 float를 하나의 블럭으로 인식한다 
	// VertexData중에 블록당 3개의 정보를 0번지부터 VBO에 쓴다 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	// Shader Layout 0번에 넘겨준다 
	glEnableVertexAttribArray(0);

	//VertexData중에 블록당 3개의 정보를 3번지부터 VBO에 쓴다 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), ( (void*)(3 * sizeof(float) ) ));
	// Shader Layout 1번에 넘겨준다 
	glEnableVertexAttribArray(1);

	

	//쓰기위한 EBO생성 
	glGenBuffers(1, &EBO);

	//이제부터 EBO를 사용한다 ( 아직 VAO사용중 )
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //--- GL_ELEMENT_ARRAY_BUFFER 버퍼 유형으로 바인딩

	//EBO에 Index의 내용을 가져온다
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);









}