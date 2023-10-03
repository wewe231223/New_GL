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

RETURNVOID IsoscelesTriangle::RenderMode(GLenum M)
{
	this->DrawMode = M;
	return RETURNVOID();
}

RETURNVOID IsoscelesTriangle::Render()
{



	this->Resister();
	VertexObject::Render();

	glDrawArrays(this->DrawMode, 0, 3);



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


//=================================OBJ=========================================


RETURNVOID AdvanceShape::Dot::NewVertex(VertexElement e,GLfloat s)
{
	this->Vertex.push_back(e);
	this->Size = s;

	return RETURNVOID();
}





RETURNVOID AdvanceShape::Dot::Render() {



	for (auto& i : this->Vertex) {
		this->Resister(i);
	}

	AdvanceObject::Object::Render();
	glPointSize(this->Size);
	glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->Vertex.size()));

}



//===============================Triangle====================================



RETURNVOID AdvanceShape::IsoscelesTriangle::Render() {
	
	VertexElement V1{};
	VertexElement V2{};
	VertexElement V3{};

	this->ClearBuffer();

	for (auto& i : this->Properties) {


		std::tie(V1, V2, V3) = this->CalculateVertex(i);

		this->Resister(V1);
		this->Resister(V2);
		this->Resister(V3);


	}







	AdvanceObject::Object::Render();
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->Properties.size() * 3));
}


std::tuple<VertexElement, VertexElement, VertexElement> AdvanceShape::IsoscelesTriangle::CalculateVertex(IsoTriElement e)
{
	std::tuple<VertexElement, VertexElement, VertexElement> result;

	VertexElement Vertex1{
	{0.f,},
	{e.Color.r,e.Color.g,e.Color.b}
	};
	
	VertexElement Vertex2{
	{0.f,},
	{e.Color.r,e.Color.g,e.Color.b}
	};

	VertexElement Vertex3{
	{0.f,},
	{e.Color.r,e.Color.g,e.Color.b}
	};






	switch (e.TopDirection){
	case UP:

		Vertex1.VertexPosition.x = e.Center.x - e.Width / 2;
		Vertex1.VertexPosition.y = e.Center.y;


		Vertex2.VertexPosition.x = e.Center.x + e.Width / 2;
		Vertex2.VertexPosition.y = e.Center.y;

		Vertex3.VertexPosition.x = e.Center.x;
		Vertex3.VertexPosition.y = e.Center.y + e.Height;


		break;
	case DOWN:

		Vertex1.VertexPosition.x = e.Center.x - e.Width / 2;
		Vertex1.VertexPosition.y = e.Center.y;


		Vertex2.VertexPosition.x = e.Center.x;
		Vertex2.VertexPosition.y = e.Center.y - e.Height;

		Vertex3.VertexPosition.x = e.Center.x + e.Width / 2;
		Vertex3.VertexPosition.y = e.Center.y;




		break;

	case RIGHT:


		Vertex1.VertexPosition.x = e.Center.x;
		Vertex1.VertexPosition.y = e.Center.y - e.Width / 2;


		Vertex2.VertexPosition.x = e.Center.x + e.Height;
		Vertex2.VertexPosition.y = e.Center.y;

		Vertex3.VertexPosition.x = e.Center.x;
		Vertex3.VertexPosition.y = e.Center.y + e.Width / 2;


		break;
	case LEFT:


		Vertex1.VertexPosition.x = e.Center.x;
		Vertex1.VertexPosition.y = e.Center.y - e.Width / 2;


		Vertex2.VertexPosition.x = e.Center.x;
		Vertex2.VertexPosition.y = e.Center.y + e.Width / 2;

		Vertex3.VertexPosition.x = e.Center.x - e.Height;
		Vertex3.VertexPosition.y = e.Center.y;




		break;
	default:
		break;
	}










	return std::make_tuple(Vertex1, Vertex2, Vertex3);
}



RETURNVOID AdvanceShape::IsoscelesTriangle::NewIsoscelesTriangle(IsoTriElement e)
{



	this->Properties.push_back(e);
	return RETURNVOID();
}



RETURNVOID AdvanceShape::IsoscelesTriangle::Reshape(GLfloat XRatio, GLfloat YRatio)
{
	GLfloat Width = GETWIN_WIDTH;
	GLfloat Height = GETWIN_HEIGHT;

	//if (Width > Height) {
	//	GLfloat Ratio = Height / Width;

	//	for (auto& i : this->Properties) {

	//		if (i.TopDirection == LEFT || i.TopDirection == RIGHT) {
	//			i.Height *= Ratio;
	//		}
	//		else {
	//			i.Width *= Ratio;
	//		}

	//	}



	//}
	//else if (Width < Height) {
	//	GLfloat Ratio = Width / Height;

	//	for (auto& i : this->Properties) {

	//		if (i.TopDirection == LEFT || i.TopDirection == RIGHT) {
	//			i.Width *= Ratio;
	//		}
	//		else {
	//			i.Height *= Ratio;
	//		}

	//	}



	//}




	return RETURNVOID();
}


RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Apply(PARAMETERVOID)
{
	for (auto& i : this->Properties) {
		i.Vector.x = this->RG.RandFloat(-0.005f, 0.005f);
		i.Vector.y = this->RG.RandFloat(-0.005f, 0.005f);
	}


	return RETURNVOID();
}




RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Reflection(PARAMETERVOID)
{
	
	for (auto& i : this->Properties) {
		if (i.Center.x >= 1.f) {
			i.TopDirection = LEFT;
			i.Vector.x *= -1.f;
		}

		if (i.Center.x <= -1.f) {
			i.TopDirection = RIGHT;
			i.Vector.x *= -1.f;
		}


		if (i.Center.y >= 1.f) {
			i.TopDirection = DOWN;
			i.Vector.y *= -1.f;
		}

		

		if (i.Center.y <= -1.f) {
			i.TopDirection = UP;
			i.Vector.y *= -1.f;
		}
	}






	return RETURNVOID();
}




RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Movement(PARAMETERVOID)
{
	this->Vector_Reflection();

	for (auto& i : this->Properties) {
		i.Center.x += i.Vector.x;
		i.Center.y += i.Vector.y;
	}

	


	return RETURNVOID();
}
