#include "Shader.h"
Shader* Shader::Instance = nullptr;

bool Shader::Resister_ShaderSource(const char* path, ShaderType T)
{

	if (T == Vertex) {
		this->VertexShader_FileReaderptr = new FileReader(path);
		if (!this->VertexShader_FileReaderptr->GetAvailable()) {
			std::cerr << "FILE OPEN FAILED" << std::endl;
			return false;
		}
		else {
			std::cerr << "FILE OPEN" << std::endl;
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
			std::cerr << "FILE OPEN" << std::endl;

			return true;
		}
		
	}



	

	return true;
}

RETURNVOID Shader::Create_Shader(ShaderType T)
{
	if (T == Vertex) {
		GLchar* VertexShaderSource;


		VertexShaderSource = this->VertexShader_FileReaderptr->GetSource();
		this->VertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(this->VertexShaderID, 1, &VertexShaderSource, NULL);
		glCompileShader(this->VertexShaderID);



		GLint result;
		GLchar errorLog[512]{};

		glGetShaderiv(this->VertexShaderID, GL_COMPILE_STATUS, &result);

		if (!result) {

			glGetShaderInfoLog(this->VertexShaderID, 512, NULL, errorLog);
			std::cerr << "ERROR : VERTEX SHADER COMPILE FAILED" << std::endl << errorLog << std::endl;
			return;
		}
		else {
			std::cerr << "VERTEX SHADER SUCESSFULLY COMPILED" << std::endl;
		}




	}

	if (T == Fragment) {
		GLchar* FragmentShaderSource;


		FragmentShaderSource = this->FragmentShader_FileReaderptr->GetSource();
		this->FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(this->FragmentShaderID, 1, &FragmentShaderSource, NULL);
		glCompileShader(this->FragmentShaderID);



		GLint result;
		GLchar errorLog[512]{};

		glGetShaderiv(this->FragmentShaderID, GL_COMPILE_STATUS, &result);

		if (!result) {

			glGetShaderInfoLog(this->FragmentShaderID, 512, NULL, errorLog);
			std::cerr << "ERROR : Fragment SHADER COMPILE FAILED" << std::endl << errorLog << std::endl;
			return;
		}
		else {
			std::cerr << "Fragment SHADER SUCESSFULLY COMPILED" << std::endl;
		}



	}

}


RETURNVOID Shader:: LINK_SHADER(PARAMETERVOID) {

	this->ShaderProgramID = glCreateProgram();

	glAttachShader(this->ShaderProgramID, this->VertexShaderID);
	glAttachShader(this->ShaderProgramID, this->FragmentShaderID);


	glLinkProgram(this->ShaderProgramID);

	glDeleteShader(this->VertexShaderID);	
	glDeleteShader(this->FragmentShaderID);


	this->VertexShader_FileReaderptr->ReleaseMemory();
	this->FragmentShader_FileReaderptr->ReleaseMemory();

	delete this->FragmentShader_FileReaderptr;
	delete this->VertexShader_FileReaderptr;



	GLint result;
	GLchar errorLog[512]{};

	glGetProgramiv(this->ShaderProgramID, GL_LINK_STATUS, &result);

	if (!result) {

		glGetProgramInfoLog(this->ShaderProgramID, 512, NULL, errorLog);
		std::cerr << "ERROR : SHADER LINK FAILED" << std::endl << errorLog << std::endl;
		return ;
	}
	else {
		std::cerr << "SHADERS SUCESSFULLY LINKED" << std::endl;
	}

	glUseProgram(this->ShaderProgramID);

}



Shader* Shader::GetShaderInstance()
{
	if (Instance == nullptr) {

		Instance = new Shader;
		Instance->Resister_ShaderSource(VERTEXSHADER_PATH, Vertex);
		Instance->Resister_ShaderSource(FRAGMENTSHADER_PATH, Fragment);

		Instance->Create_Shader(Vertex);
		Instance->Create_Shader(Fragment);


		Instance->LINK_SHADER();

		std::cout << "Shader Created" << std::endl;

	}




	return Instance;
}



