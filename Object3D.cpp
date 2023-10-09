#include "Object3D.h"


RETURNVOID Object3D::Initialize(const char* path, ShaderID ShaderProgramId) {
	this->ShaderProgramId = ShaderProgramId;

	this->File.open(path);

	if (!this->File) {
		std::cerr << "OBJ FILE ERROR!" << std::endl;
		exit(-1);
	}


	return this->Resister();
}



RETURNVOID Object3D::Resister() {
	std::vector<glm::vec3>().swap(this->Verties);
	std::vector<glm::vec2>().swap(this->UVs);
	std::vector<glm::vec3>().swap(this->Normals);


	std::vector<GLuint>().swap(this->Vertex_Indices);
	std::vector<GLuint>().swap(this->UV_Indices);
	std::vector<GLuint>().swap(this->Normal_Indices);


	std::string head{};

	while (!this->File.eof()) {
		this->File >> head;
		if (head[0] == '#') {
			getline(this->File, head);
		}



		if (head[0] == 'v' && head[1] == 't') {
			glm::vec2 uv{};
			this->File >> uv.x >> uv.y;
			this->UVs.push_back(uv);
		}
		else if (head[0] == 'v' && head[1] == 'n') {
			glm::vec3 Normal{};

			this->File >> Normal.x >> Normal.y >> Normal.z;
			this->Normals.push_back(Normal);

		}
		else if (head[0] == 'v' && head.size() == 1) {
			glm::vec3 Vertex_{};

			this->File >> Vertex_.x >> Vertex_.y >> Vertex_.z;
			this->Verties.push_back(Vertex_);
		}
		else if (head[0] == 'f') {

			std::string Line[3]{};

			GLuint VertexIndex[3]{};
			GLuint UVIndec[3]{};
			GLuint NormalIndex[3]{};

			this->File >> Line[0] >> Line[1] >> Line[2];



			for (auto i = 0; i < 3; ++i) {
				std::istringstream iss(Line[i]);
				std::string token{};
				GLuint Data[3]{};
				int dataindex = 0;
				if (Line[i].find("//") != std::string::npos) {
					// 있으면
					std::getline(iss, token, '/');
					this->Vertex_Indices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					std::getline(iss, token, '/');


					this->Normal_Indices.push_back(static_cast<GLuint>(stoi(token) - 1));
				}
				else {
					//없으면 
					std::getline(iss, token, '/');
					this->Vertex_Indices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					this->UV_Indices.push_back(static_cast<GLuint>(stoi(token) - 1));


					std::getline(iss, token, '/');
					this->Normal_Indices.push_back(static_cast<GLuint>(stoi(token) - 1));



				}




			}
		}


	}

	this->File.close();


	size_t Vertexnum = this->Verties.size();

	Color3f* BaseColor = new Color3f[Vertexnum];

	for (auto i = 0; i < Vertexnum; ++i) {

		if (this->RandomColor) {
			BaseColor[i].r = this->ColorGenerater.RandF();
			BaseColor[i].g = this->ColorGenerater.RandF();
			BaseColor[i].b = this->ColorGenerater.RandF();
		}
		else {
			BaseColor[i].r = 1.f;
			BaseColor[i].g = 1.f;
			BaseColor[i].b = 1.f;


		}


	}




	for (const auto& i : this->Vertex_Indices) {
		this->IndexedColor.push_back(BaseColor[i]);
	}

	delete[] BaseColor;
}




RETURNVOID Object3D::Buffering() {

	glGenVertexArrays(1, &(this->VAO));
	glBindVertexArray(this->VAO);


	glGenBuffers(1, &(this->VBO.Position));
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Position);
	glBufferData(GL_ARRAY_BUFFER, this->Verties.size() * sizeof(glm::vec3), &(this->Verties[0]), GL_STATIC_DRAW);

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Vertex_Indices.size() * sizeof(unsigned int), &(this->Vertex_Indices[0]), GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);


	glGenBuffers(1, &(this->VBO.Color));
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Color);

	glBufferData(GL_ARRAY_BUFFER, this->IndexedColor.size() * sizeof(Color3f), &(this->IndexedColor[0]), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);


}


Model* Object3D::NewModel() {
	Model* newModel = new Model;
	newModel->ShaderId = this->ShaderProgramId;
	newModel->VAO = VAO;
	newModel->VertexSize = static_cast<GLsizei>(this->Vertex_Indices.size());
	return newModel;
}








RETURNVOID Model::Render(){

	this->Culling ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
	this->Culling ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
	this->Filled ? glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBindVertexArray(this->VAO);

	glm::mat4 Trans = glm::mat4(1.f);

	Trans = glm::scale(Trans, this->Scale);



	GLuint WorldLocation = glGetUniformLocation(this->ShaderId, "transform");


	Trans = glm::translate(Trans, this->Position);
	Trans = glm::rotate(Trans, glm::radians(this->XRotate), glm::vec3(1.f, 0.f, 0.f));
	Trans = glm::rotate(Trans, glm::radians(this->YRotate), glm::vec3(0.f, 1.f, 0.f));



	glUniformMatrix4fv(WorldLocation, 1, GL_FALSE, glm::value_ptr(Trans));



	glDrawElements(GL_TRIANGLES, this->VertexSize, GL_UNSIGNED_INT, 0);




	return RETURNVOID();
}

RETURNVOID Model::Transition(Object3DVecEnum Ve, glm::vec3 Vector)
{
	switch (Ve)
	{
	case RotateX:

		this->XRotate += Vector.x;


		break;
	case RotateY:

		this->YRotate += Vector.y;

		break;
	case Movement:

		this->Position += Vector;

		break;
	case ObjectScale:

		this->Scale = Vector;

		break;
	default:
		break;
	}




	return RETURNVOID();
}
