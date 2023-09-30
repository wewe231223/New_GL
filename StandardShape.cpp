#include "StandardShape.h"


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



	const float VC1[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};

	const float VC2[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};

	const float VC3[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};




	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V3);


	this->ResisterVertex(Vertex_1, TColor, VC1);
	this->ResisterVertex(Vertex_2, TColor, VC2);
	this->ResisterVertex(Vertex_3, TColor, VC3);

	// 반시계!






}

RETURNVOID IsoscelesTriangle::Properties(PropertiesType T, float Cx, float Cy, float W, float H, Color3f c)
{
	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.z = 0.0f;

		this->Width = this->RG.RandFloat(0.1f, 0.3f);
		this->Height = this->RG.RandFloat(0.3f, 0.5f);

		this->Color.r = this->RG.RandFloat(0.f, 1.f);
		this->Color.g = this->RG.RandFloat(0.f, 1.f);
		this->Color.b = this->RG.RandFloat(0.f, 1.f);

	}
	else {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;

		this->Width = W;
		this->Height = H;

		this->Color.r = c.r;
		this->Color.g = c.g;
		this->Color.b = c.b;


	}


}

RETURNVOID IsoscelesTriangle::Render()
{



	this->Resister();
	VertexObject::Render();

	glDrawArrays(GL_TRIANGLES, 0, 3);




}




RETURNVOID IsoscelesTriangle::Move(Vector2F V)
{


	this->Center.x += V.x;
	this->Center.y += V.y;








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





	// Random Color all Vertex
	const float VC1[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};

	const float VC2[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};

	const float VC3[] = {
	this->Color.r,
	this->Color.g,
	this->Color.b
	};




	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V3);


	this->ResisterVertex(Vertex_1, TColor, VC1);
	this->ResisterVertex(Vertex_2, TColor, VC2);
	this->ResisterVertex(Vertex_3, TColor, VC3);

	// 반시계!






}

RETURNVOID RightTriangle::Properties(PropertiesType T, float Cx, float Cy, float s, Color3f C)
{

	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.z = 0.0f;

		this->Side = this->RG.RandFloat(0.1f, 0.3f);

		float ColorCode = this->RG.RandFloat(0.f, 1.f);
		this->Color.r = ColorCode;
		this->Color.g = ColorCode;
		this->Color.b = ColorCode;

	}
	else if (T == Defined) {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;


		this->Side = s;

		this->Color.r = C.r;
		this->Color.g = C.g;
		this->Color.b = C.b;


	}


}

RETURNVOID RightTriangle::Render()
{
	this->Resister();
	VertexObject::Render();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}



RETURNVOID RightTriangle::Move(Vector2F V)
{

}

//============================Rectangle==========================================================

RETURNVOID Rectangle_::Init()
{
	this->T1.Init();
	this->T2.Init();
	return RETURNVOID();
}

RETURNVOID Rectangle_::Resister()
{



	this->T1.Properties(Defined, this->Center.x - this->Side / 2, this->Center.y - this->Side / 2, this->Side, this->Color);
	this->T2.Properties(Defined, this->Center.x + this->Side / 2, this->Center.y + this->Side / 2, -this->Side, this->Color);

	this->T1.Resister();
	this->T2.Resister();

}



RETURNVOID Rectangle_::Properties(PropertiesType T, float Cx, float Cy, float s, Color3f C) {

	if (T == Random) {

		this->Center.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Center.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Side = this->RG.RandFloat(0.1f, 0.5f);

		this->Color.r = this->RG.RandFloat(0.f, 1.f);
		this->Color.g = this->RG.RandFloat(0.f, 1.f);
		this->Color.b = this->RG.RandFloat(0.f, 1.f);
	}
	else if (T == Defined) {
		this->Center.x = Cx;
		this->Center.y = Cy;
		this->Center.z = 0.0f;

		this->Color.r = C.r;
		this->Color.g = C.g;
		this->Color.b = C.b;


		this->Side = s;
	}



}

RETURNVOID Rectangle_::Render()
{
	this->Resister();
	T1.Render();
	T2.Render();
	return RETURNVOID();
}

RETURNVOID Rectangle_::Move(Vector2F V)
{


	this->Center.x += V.x;
	this->Center.y += V.y;

	this->Resister();


}










//============================Dots==========================================================

RETURNVOID Dot::Resister()
{
	float Color[] = { this->Color.r,this->Color.g,this->Color.b };
	float Point[] = { this->Center.x,this->Center.y,this->Center.y };

	this->ResisterVertex(Vertex_1, TVertex, Point);
	this->ResisterVertex(Vertex_1, TColor, Color);



	this->ResisterVertex(Vertex_2, TVertex, Point);
	this->ResisterVertex(Vertex_2, TColor, Color);


	this->ResisterVertex(Vertex_3, TVertex, Point);
	this->ResisterVertex(Vertex_3, TColor, Color);

	return RETURNVOID();
}

RETURNVOID Dot::Properties(PropertiesType T, float x, float y, float z, Color3f C)
{
	if (T == Random) {
		this->Center.x = this->RG.RandFloat(-1.f, 1.f);
		this->Center.y = this->RG.RandFloat(-1.f, 1.f);
		this->Center.z = 0.0f;


		this->Color.r = this->RG.RandFloat(0.f, 1.f);
		this->Color.g = this->RG.RandFloat(0.f, 1.f);
		this->Color.b = this->RG.RandFloat(0.f, 1.f);
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
	this->Resister();
	glPointSize(10.0f);
	VertexObject::Render();
	glDrawArrays(GL_POINTS, 0, 1);
	return RETURNVOID();
}

RETURNVOID Dot::Move(Vector2F V)
{

	this->Center.x += V.x;
	this->Center.y += V.y;



	return RETURNVOID();
}

//============================Lines==========================================================


RETURNVOID Line::Resister()
{
	const float Color[] = { this->Color.r,this->Color.g,this->Color.b };
	const float V1[] = { this->Start.x,this->Start.y,this->Start.z };
	const float V2[] = { this->End.x,this->End.y,this->End.z };


	this->ResisterVertex(Vertex_1, TVertex, V1);
	this->ResisterVertex(Vertex_2, TVertex, V2);
	this->ResisterVertex(Vertex_3, TVertex, V1);


	this->ResisterVertex(Vertex_1, TColor, Color);
	this->ResisterVertex(Vertex_2, TColor, Color);
	this->ResisterVertex(Vertex_3, TColor, Color);




	return RETURNVOID();
}


RETURNVOID Line::Properties(PropertiesType T, Point2F S, Point2F E, Color3f C) {

	if (T == Random) {
		this->Color.r = this->RG.RandFloat(0.0f, 1.0f);
		this->Color.g = this->RG.RandFloat(0.0f, 1.0f);
		this->Color.b = this->RG.RandFloat(0.0f, 1.0f);


		this->Start.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->Start.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->Start.z = 0.0f;


		this->End.x = this->RG.RandFloat(-1.0f, 1.0f);
		this->End.y = this->RG.RandFloat(-1.0f, 1.0f);
		this->End.z = 0.0f;

	}
	else if (T == Defined) {
		this->Color.r = C.r;
		this->Color.g = C.g;
		this->Color.b = C.b;


		this->Start.x = S.x;
		this->Start.y = S.y;
		this->Start.z = 0.f;

		this->End.x = E.x;
		this->End.y = E.y;
		this->End.z = 0.0f;


	}



	return RETURNVOID();
}

RETURNVOID Line::ApplyThickness(GLfloat T)
{

	this->Thickness = T;
	return RETURNVOID();
}



RETURNVOID Line::Render()
{
	this->Resister();

	glLineWidth(this->Thickness);

	VertexObject::Render();
	glDrawArrays(GL_LINES, 0, 2);
	return RETURNVOID();
}

RETURNVOID Line::Move(Vector2F V)
{

	this->Start.x += V.x;
	this->Start.y += V.y;

	this->End.x += V.x;
	this->End.y += V.y;


}