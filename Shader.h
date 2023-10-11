#pragma once

#include <iostream>

#include "GLH.h"
#include "FileReader.h"
#include "Definition.h"

enum ShaderType {
	Vertex,
	Fragment
};

enum DataName {
	ShaderProgramID
};

#define VERTEXSHADER_PATH "3D_Vertex_Shader.glsl"
#define FRAGMENTSHADER_PATH "3D_Fragment_Shader.glsl"


class Shader{
private:
	FileReader* VertexShader_FileReaderptr = nullptr;
	FileReader* FragmentShader_FileReaderptr = nullptr;

	
	GLuint VertexShaderID{};
	GLuint FragmentShaderID{};
	GLuint ShaderProgramID{};
	

	Shader() {}	
	Shader(const Shader& other) {}
	Shader& operator=(const Shader& ohter) {}


	static Shader* Instance;


private:

	bool Resister_ShaderSource(const char*,ShaderType);
	RETURNVOID Create_Shader(ShaderType);
	RETURNVOID LINK_SHADER(PARAMETERVOID);
public:
	static Shader* GetShaderInstance();
	GLuint GetShaderID() { return this->ShaderProgramID; }
};

