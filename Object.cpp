#include "Object.h"

// 3개짜리말고 
// 10개나 20개짜리도?
// 무제한이라면?



RETURNVOID VertexObject::Init()
{
	


	glGenVertexArrays(1, &(this->VAO));
	glBindVertexArray(this->VAO);


	glGenBuffers(1, &(this->VBO_Position));
	glGenBuffers(1, &(this->VBO_Color));

}

RETURNVOID VertexObject::ResisterVertex(VertexNo T,VertexType V,const float* Array) {
	if (V == TVertex) {
		if (T == Vertex_1) {
			this->Vertex1.VertexPosition.x = Array[0];
			this->Vertex1.VertexPosition.y = Array[1];
			this->Vertex1.VertexPosition.z = Array[2];
		}
		else if (T == Vertex_2) {
			this->Vertex2.VertexPosition.x = Array[0];
			this->Vertex2.VertexPosition.y = Array[1];
			this->Vertex2.VertexPosition.z = Array[2];
		}
		else if (T == Vertex_3) {
			this->Vertex3.VertexPosition.x = Array[0];
			this->Vertex3.VertexPosition.y = Array[1];
			this->Vertex3.VertexPosition.z = Array[2];
		}
	}
	else if (V == TColor) {
		if (T == Vertex_1) {
			this->Vertex1.VertexColor.r = Array[0];
			this->Vertex1.VertexColor.g = Array[1];
			this->Vertex1.VertexColor.b = Array[2];
		}
		else if (T == Vertex_2) {
			this->Vertex2.VertexColor.r = Array[0];
			this->Vertex2.VertexColor.g = Array[1];
			this->Vertex2.VertexColor.b = Array[2];
		}
		else if (T == Vertex_3) {
			this->Vertex3.VertexColor.r = Array[0];
			this->Vertex3.VertexColor.g = Array[1];
			this->Vertex3.VertexColor.b = Array[2];
		}
	}




}



RETURNVOID VertexObject::Render()
{
	glBindVertexArray(this->VAO);
	

	const float Verties[] = {
		this->Vertex1.VertexPosition.x,this->Vertex1.VertexPosition.y,this->Vertex1.VertexPosition.z,
		this->Vertex2.VertexPosition.x,this->Vertex2.VertexPosition.y,this->Vertex2.VertexPosition.z,
		this->Vertex3.VertexPosition.x,this->Vertex3.VertexPosition.y,this->Vertex3.VertexPosition.z
	};

	const float Colors[] = {
		this->Vertex1.VertexColor.r,this->Vertex1.VertexColor.g,this->Vertex1.VertexColor.b,
		this->Vertex2.VertexColor.r,this->Vertex2.VertexColor.g,this->Vertex2.VertexColor.b,
		this->Vertex3.VertexColor.r,this->Vertex3.VertexColor.g,this->Vertex3.VertexColor.b
	};


//	std::cout << this->Vertex1.VertexColor.r << std::endl;


	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Verties), Verties, GL_DYNAMIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);



	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_Color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);




}

namespace AdvanceObject {

	RETURNVOID Object::Init()
	{
		glGenVertexArrays(1, &(this->VAO));
		glBindVertexArray(this->VAO);


		glGenBuffers(1, &(this->VBO.Position));
		glGenBuffers(1, &(this->VBO.Color));

		return RETURNVOID();
	}
	RETURNVOID AdvanceObject::Object::ClearBuffer(PARAMETERVOID)
	{
		std::vector<GLfloat>().swap(this->VertexPosition);
		std::vector<GLfloat>().swap(this->VertexColor);

		return RETURNVOID();
	}

	RETURNVOID Object::Resister(VertexElement& e)
	{


		this->VertexPosition.push_back(e.VertexPosition.x);
		this->VertexPosition.push_back(e.VertexPosition.y);
		this->VertexPosition.push_back(e.VertexPosition.z);


		this->VertexColor.push_back(e.VertexColor.r);
		this->VertexColor.push_back(e.VertexColor.g);
		this->VertexColor.push_back(e.VertexColor.b);


		return RETURNVOID();
	}


	RETURNVOID Object::Render()
	{



		GLfloat* Pptr = new GLfloat[this->VertexPosition.size()];
		GLfloat* Cptr = new GLfloat[this->VertexColor.size()];

		std::copy(this->VertexPosition.begin(), this->VertexPosition.end(), Pptr);
		std::copy(this->VertexColor.begin(), this->VertexColor.end(), Cptr);



		glBindVertexArray(this->VAO);


		glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Position);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->VertexPosition.size(), Pptr, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);


		glBindBuffer(GL_ARRAY_BUFFER, this->VBO.Color);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->VertexColor.size(), Cptr, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);


		delete[] Pptr;
		delete[] Cptr;

		return RETURNVOID();
	}

}