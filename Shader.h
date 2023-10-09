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



class Shader{
private:
	FileReader* VertexShader_FileReaderptr = nullptr;
	FileReader* FragmentShader_FileReaderptr = nullptr;

	
	GLuint VertexShaderID{};
	GLuint FragmentShaderID{};
	GLuint ShaderProgramID{};
	




public:

	Shader() {}
	
	

	bool Resister_ShaderSource(const char*,ShaderType);



	RETURNVOID Create_Shader(ShaderType);
	RETURNVOID LINK_SHADER(PARAMETERVOID);


	GLuint GetInfo(DataName);

};

