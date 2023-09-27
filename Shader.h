#pragma once
#include "GLH.h"
#include "FileReader.h"
#include "Definition.h"

class Shader{
private:
	FileReader VertexShader_FileReader;
	FileReader FragmentShader_FileReader;

	
	GLuint VertexShaderID{};
	GLuint FragmentShaderID{};
	GLuint ShaderProgramID{};
	




public:

	Shader() {};





};

