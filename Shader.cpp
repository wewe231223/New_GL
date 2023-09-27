#include "Shader.h"

bool Shader::Resister_ShaderSource(const char* path, ShaderType T)
{

	if (T == Vertex) {
		this->VertexShader_FileReaderptr = new FileReader(path);
		if (!this->VertexShader_FileReaderptr->GetAvailable()) {
			std::cerr << "FILE OPEN FAILED" << std::endl;
			return false;
		}
		else {
			return true;
		}
	}

	if (T == Fragment) {
		this->FragmentShader_FileReaderptr = new FileReader(path);
		if (!this->FragmentShader_FileReaderptr->GetAvailable()) {
			std::cerr << "FILE OPEN FAILED" << std::endl;
			return false;
		}
		else {
			return true;
		}
		
	}

	return true;
}

void Shader::Create_Shader(ShaderType)
{








}
