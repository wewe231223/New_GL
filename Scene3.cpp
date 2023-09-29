#include "Scene3.h"

RETURNVOID IsoscelesTriangle::Resister()
{
	const float V1[] = {
	this->Center.x - this->Width / 2, 
	this->Center.y,
	0.0f
	};


	const float V2[] = {
	this->Center.x + this->Width / 2,
	this->Center.y,
	this->Center.z
	};


	const float V3[] = {
	this->Center.x ,
	this->Center.y + this->Height,
	this->Center.z
	};


	float R = this->RG.RandFloat(0.0f, 1.0f);
	float G = this->RG.RandFloat(0.0f, 1.0f);
	float B = this->RG.RandFloat(0.0f, 1.0f);


	// Random Color all Vertex
	const float VC1[] = {
	R,
	G,
	B
	};


	const float VC2[] = {
	R,
	G,
	B	
	};


	const float VC3[] = {
	R,
	G,
	B
	};







	// Random Color each Vertex

	//const float VC1[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};

	//const float VC2[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};

	//const float VC3[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};



	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V3);


	this->ResisterVertex(Vertex_1, TColor, VC1);
	this->ResisterVertex(Vertex_2, TColor, VC2);
	this->ResisterVertex(Vertex_3, TColor, VC3);
	
	// 반시계!

	





	return RETURNVOID();
}

RETURNVOID IsoscelesTriangle::Properties(PropertiesType T, float Cx , float Cy  , float W , float H )
{
	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.z = 0.0f;
		
		this->Width = this->RG.RandFloat(0.1f, 0.3f);
		this->Height = this->RG.RandFloat(0.3f, 0.5f);
	}
	else {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;

		this->Width = W;
		this->Height = H;
	}
		

	return RETURNVOID();
}

RETURNVOID IsoscelesTriangle::Render()
{

	VertexObject::Render();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	


	return RETURNVOID();
}
//============================RightTriangle==========================================================


RETURNVOID RightTriangle::Resister()
{
	

	const float V1[] = {
		this->Center.x,
		this->Center.y,
		this->Center.z
	};

	const float V2[] = {
		this->Center.x + this->Side,
		this->Center.y,
		this->Center.z
	};


	const float V3[] = {
		this->Center.x,
		this->Center.y + this->Side,
		this->Center.z
	};



	float R = this->RG.RandFloat(0.0f, 1.0f);
	float G = this->RG.RandFloat(0.0f, 1.0f);
	float B = this->RG.RandFloat(0.0f, 1.0f);


	// Random Color all Vertex
	const float VC1[] = {
	R,
	G,
	B
	};


	const float VC2[] = {
	R,
	G,
	B
	};


	const float VC3[] = {
	R,
	G,
	B
	};







	// Random Color each Vertex

	//const float VC1[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};

	//const float VC2[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};

	//const float VC3[] = {
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f),
	//this->RG.RandFloat(0.0f,1.0f)
	//};



	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V3);


	this->ResisterVertex(Vertex_1, TColor, VC1);
	this->ResisterVertex(Vertex_2, TColor, VC2);
	this->ResisterVertex(Vertex_3, TColor, VC3);

	// 반시계!



	


	return RETURNVOID();
}

RETURNVOID RightTriangle::Properties(PropertiesType T, float Cx, float Cy, float s)
{

	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.z = 0.0f;

		this->Side = this->RG.RandFloat(0.1f, 0.3f);
	}
	else {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;

		this->Side = s;
	}


	return RETURNVOID();
}

RETURNVOID RightTriangle::Render()
{

	VertexObject::Render();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return RETURNVOID();
}


//============================Rectangle==========================================================

RETURNVOID Rectangle_::Resister()
{
	this->T1.Properties(Defined, this->Center.x - this->Side / 2, this->Center.y - this->Side / 2, this->Side);

	this->T2.Properties(Defined, this->Center.x + this->Side / 2, this->Center.y + this->Side / 2, -this->Side);

	this->T1.Resister();
	this->T2.Resister();

	return RETURNVOID();
}



RETURNVOID Rectangle_::Properties(PropertiesType T, float Cx, float Cy, float s) {

	if (T == Random) {

		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Side = this->RG.RandFloat(0.1f, 0.5f);


	}
	else if (T == Defined) {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;

		this->Side = s;
	}



}

RETURNVOID Rectangle_::Render()
{
	T1.Render();
	T2.Render();
	return RETURNVOID();
}










//============================Dots==========================================================

RETURNVOID Dot::Resister()
{
	float Color[] = {this->RG.RandFloat(0.0f,1.0f),this->RG.RandFloat(0.0f,1.0f),this->RG.RandFloat(0.0f,1.0f)};
	float Point[] = {this->Center.x,this->Center.y,this->Center.y};

	this->ResisterVertex(Vertex_1, TVertex, Point);
	this->ResisterVertex(Vertex_1, TColor, Color);



	this->ResisterVertex(Vertex_2, TVertex, Point);
	this->ResisterVertex(Vertex_2, TColor, Color);


	this->ResisterVertex(Vertex_3, TVertex, Point);
	this->ResisterVertex(Vertex_3, TColor, Color);

	return RETURNVOID();
}

RETURNVOID Dot::Properties(PropertiesType T, float x, float y, float z)
{
	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.f, 1.f);
		this->Center.y = this->RG.RandFloat(-1.f, 1.f);
		this->Center.z = 0.0f;
	}
	else {

		this->Center.x = x;
		this->Center.y = y;
		this->Center.z = z;
	}


	return RETURNVOID();
}


RETURNVOID Dot::Render()
{
	glPointSize(10.0f);
	VertexObject::Render();
	glDrawArrays(GL_POINTS, 0, 1);
	return RETURNVOID();
}




//============================Scenes==========================================================

RETURNVOID Scene3::NewTriangle(IsoscelesTriangle T)
{
	if (this->ShapeCount < 100) {
		this->Triangles.push_back(T);
		this->ShapeCount += 1;
	}

	return RETURNVOID();
}

RETURNVOID Scene3::NewDot(Dot D){
	if (this->ShapeCount < 100) {
		this->Dots.push_back(D);
		this->ShapeCount += 1;
	}

	return RETURNVOID();
}

RETURNVOID Scene3::NewRect(Rectangle_ R) 
{
	if (this->ShapeCount < 100) {
		this->Rectangles.push_back(R);
		this->ShapeCount += 1;
	}


	return RETURNVOID();
}






//============================CallBacks==========================================================

namespace Scene3_CallBackFunctions {
	Scene3 SC3{};
}


RETURNVOID Scene3_CallBackFunctions::Draw()
{


	Color4f BackGroundColor{ 0.f,0.f,0.f,1.f };

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	for (auto& i : Scene3_CallBackFunctions::SC3.GetTriangles()) {
		i.Render();
	}

	for (auto& i : Scene3_CallBackFunctions::SC3.GetDots()) {
		i.Render();
	}

	for (auto& i : Scene3_CallBackFunctions::SC3.GetRects()) {
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

	if (key == 't' || key == 'T') {
		
		IsoscelesTriangle newTriangle;
		newTriangle.Properties(Random, 0.f, 0.f, 0.f, 0.f);
		newTriangle.Resister();
		SC3.NewTriangle(newTriangle);
	} 

	if (key == 'p' || key == 'P') {

		Dot newDot;
		newDot.Properties(Random, 0.0f, 0.0f, 0.0f);
		newDot.Resister();
		SC3.NewDot(newDot);

	}

	if (key == 'r' || key == 'R') {
		Rectangle_ newRect;
		newRect.Properties(Random, 0.0f, 0.0f, 0.0f);
		newRect.Resister();
		SC3.NewRect(newRect);

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

