#include "Scene3.h"

RETURNVOID Triangle::CalculateVertex()
{
	const float V1[] = {
	this->Center.x - this->Width / 2, 
	this->Center.y,
	0.0f
	};


	const float V2[] = {
	this->Center.x + this->Width / 2, 
	this->Center.y, 
	0.0f
	};


	const float V3[] = {
	this->Center.x , 
	this->Center.y + this->Height,
	0.0f
	};


	const float VC1[] = {
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f)
	};

	const float VC2[] = {
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f)
	};

	const float VC3[] = {
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f),
	this->RG.RandFloat(0.0f,1.0f)
	};



	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V3);


	this->ResisterVertex(Vertex_1, TColor, VC1);
	this->ResisterVertex(Vertex_2, TColor, VC2);
	this->ResisterVertex(Vertex_3, TColor, VC3);
	
	// ¹Ý½Ã°è!

	





	return RETURNVOID();
}

RETURNVOID Triangle::Properties(float Cx = 0.0f, float Cy = 0.0f , float W = 0.0f, float H = 0.0f)
{
	if (W == 0.0f) {
		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		
		this->Width = this->RG.RandFloat(0.1f, 0.3f);
		this->Height = this->RG.RandFloat(0.3f, 0.5f);
	}
	else {
		this->Center.x = Cx;
		this->Center.y = Cy;

		this->Width = W;
		this->Height = H;
	}
		

	return RETURNVOID();
}


namespace Scene3_CallBackFunctions {
	Scene3 SC3{};
}


RETURNVOID Scene3_CallBackFunctions::Draw()
{

	Color4f BackGroundColor{ 1.f,1.f,1.f,1.f };

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	for (auto& i : Scene3_CallBackFunctions::SC3.GetTriangles()) {
		i.CalculateVertex();
		i.Render();
	}

	glutSwapBuffers();


	return RETURNVOID();
}



RETURNVOID Scene3_CallBackFunctions::MouseOnClick(int Button,int State,int x,int y)
{
	if (Button == GLUT_LEFT_BUTTON) {

	}



	return RETURNVOID();
}

RETURNVOID Scene3_CallBackFunctions::KeyboardInput(unsigned char key, int x, int y)
{

	if (key == 't') {
		Triangle newTriangle;
		SC3.NewTriangle(newTriangle);
	}


	glutPostRedisplay();

	return RETURNVOID();
}




CallbackFunc Scene3_CallBackFunctions::CreateCallBackFuctions(PARAMETERVOID) {


	CallbackFunc result;

	result.DrawCall = Scene3_CallBackFunctions::Draw;
	result.KeyboardInputCall = Scene3_CallBackFunctions::KeyboardInput;


	return result;
}

