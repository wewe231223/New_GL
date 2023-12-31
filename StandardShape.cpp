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

	this->ClearBuffer();

	for (auto& i : this->Vertex) {
		this->Resister(i);
	}

	AdvanceObject::Object::Render();
	glPointSize(this->Size);
	glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(this->Vertex.size()));

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
	VertexElement Vertex1{ {0.f,},{e.Color.r,e.Color.g,e.Color.b} };
	VertexElement Vertex2{ {0.f,},{e.Color.r,e.Color.g,e.Color.b} };
	VertexElement Vertex3{ {0.f,},{e.Color.r,e.Color.g,e.Color.b} };

	Point2F PixelVertex1 = { 0, };
	Point2F PixelVertex2 = { 0, };
	Point2F PixelVertex3 = { 0, };


	switch (e.TopDirection) {
	case LEFT:

		PixelVertex1.x = e.Center.x;
		PixelVertex1.y = e.Center.y - e.Width / 2;

		PixelVertex2.x = e.Center.x;
		PixelVertex2.y = e.Center.y + e.Width / 2;

		PixelVertex3.x = e.Center.x - e.Height;
		PixelVertex3.y = e.Center.y;





		break;
	case RIGHT:

		PixelVertex1.x = e.Center.x;
		PixelVertex1.y = e.Center.y - e.Width / 2;

		PixelVertex2.x = e.Center.x + e.Height;
		PixelVertex2.y = e.Center.y;


		PixelVertex3.x = e.Center.x;
		PixelVertex3.y = e.Center.y + e.Width / 2;

		break;

	case UP:

		PixelVertex1 = Point2F{ e.Center.x + e.Width / 2,e.Center.y };
		PixelVertex2 = Point2F{ e.Center.x ,e.Center.y + e.Height};
		PixelVertex3 = Point2F{ e.Center.x - e.Width / 2,e.Center.y };



		break;
	case DOWN:
		PixelVertex1 = Point2F{ e.Center.x + e.Width / 2,e.Center.y };
		PixelVertex2 = Point2F{ e.Center.x - e.Width / 2,e.Center.y };
		PixelVertex3 = Point2F{ e.Center.x ,e.Center.y - e.Height };
		break;
		
	default:
		break;
		

	}

	Vertex1.VertexPosition = Translate(PixelVertex1);
	Vertex2.VertexPosition = Translate(PixelVertex2);
	Vertex3.VertexPosition = Translate(PixelVertex3);


	return std::make_tuple(Vertex1, Vertex2, Vertex3);
}



RETURNVOID AdvanceShape::IsoscelesTriangle::NewIsoscelesTriangle(IsoTriElement e)
{
	this->Properties.push_back(e);

	return RETURNVOID();
}

RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Apply(){

	

	for (auto& i : this->Properties) {
		switch (i.MovementType){
		case Rand:
			i.Vector = Vector2F{ this->RG.RandFloat(-3.f,3.f),this->RG.RandFloat(-3.f,3.f) };
			break;
		case ZigZag:
			i.Vector = Vector2F{i.Vector.x,0};
			break;
		case RectSpiral:
			i.Vector = Vector2F{ i.Vector.x,0 };
			i.OldX = i.Center.x;
			i.OldY = i.Center.y;
			break;

		case Spiral:
			i.Vector = Vector2F{ 0.f,0.f };
			break;
		default:
			break;
		}
	}


	return RETURNVOID();
}



RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Animation(PARAMETERVOID)
{

	GLfloat Boundary_X_Max = GET_WINDOW_WIDTHF / 2;
	GLfloat Boundary_X_Min = - GET_WINDOW_WIDTHF / 2;

	GLfloat Boundary_Y_Max = GET_WINDOW_HEIGHTF / 2;
	GLfloat Boundary_Y_Min =  - GET_WINDOW_HEIGHTF / 2;




	for (auto& i : this->Properties) {
		switch (i.MovementType){
		case Rand:
			if (i.Center.x <= Boundary_X_Min) {
				i.TopDirection = RIGHT;
				i.Vector.x *= -1;
			}

			if (i.Center.x >= Boundary_X_Max) {
				i.TopDirection = LEFT;
				i.Vector.x *= -1;
			}

			if (i.Center.y <= Boundary_Y_Min) {
				i.TopDirection = UP;
				i.Vector.y *= -1;
			}

			if (i.Center.y >= Boundary_Y_Max) {
				i.TopDirection = DOWN;
				i.Vector.y *= -1;
			}
			break;
		case ZigZag:

			if (i.Center.x <= Boundary_X_Min || i.Center.x >= Boundary_X_Max) {
				if (i.Center.x <= Boundary_X_Min) {
					i.TopDirection = RIGHT;
					i.Center.x = Boundary_X_Min + 5;
				}

				if (i.Center.x >= Boundary_X_Max) {
					i.TopDirection = LEFT;
					i.Center.x = Boundary_X_Max - 5;
				}

				if (i.ZigZag_Y_Factor == DOWN) {
					i.Vector.y = -abs(i.Vector.x);
				}
				else {
					i.Vector.y = abs(i.Vector.x);
				}

				i.Vector.x = 0;
				i.OldY = i.Center.y;
			}


			if (i.Vector.y < 0) {
				if (i.Center.y <= i.OldY - Interval) {
					if (i.TopDirection == RIGHT) {
						i.Vector.x = abs(i.Vector.y);
						i.Vector.y = 0;
					}
					else if(i.TopDirection == LEFT) {
						i.Vector.x = -abs(i.Vector.y);
						i.Vector.y = 0;
					}

					i.OldY = 0;
				}
			}else if (i.Vector.y > 0) {
				if (i.Center.y >= i.OldY + Interval) {
					if (i.TopDirection == RIGHT) {
						i.Vector.x = abs(i.Vector.y);
						i.Vector.y = 0;
					}
					else if (i.TopDirection == LEFT) {
						i.Vector.x = -abs(i.Vector.y);
						i.Vector.y = 0;
					}

					i.OldY = 0;
				}

				
			}


			if (i.Center.y <= Boundary_Y_Min + Interval) {
				i.ZigZag_Y_Factor = UP;
			}

			if (i.Center.y >= Boundary_Y_Max - Interval ) {
				i.ZigZag_Y_Factor = DOWN;
			}

			break;
		case RectSpiral:

			if (i.Center.x <= Boundary_X_Min) {
				i.TopDirection = RIGHT;
				i.Vector = Vector2F{ 0,0 };
			}

			if (i.Center.x >= Boundary_X_Max) {
				i.TopDirection = LEFT;
				i.Vector = Vector2F{ 0,0 };
			}

			if (i.Center.y <= Boundary_Y_Min) {
				i.TopDirection = UP;
				i.Vector = Vector2F{ 0,0 };
			}

			if (i.Center.y >= Boundary_Y_Max) {
				i.TopDirection = DOWN;
				i.Vector = Vector2F{ 0,0 };
			}

			if (i.Vector.x > 0 && i.Vector.y == 0) {
				if (i.Center.x >= i.OldX + i.NextDistance) {
					i.Vector.y = -abs(i.Vector.x);
					i.Vector.x = 0;
					i.OldX = i.Center.x;
					i.OldY = i.Center.y;
					i.NextDistance += RectSpiral_Interval;
				}
			}
			

			if (i.Vector.y < 0 && i.Vector.x == 0) {
				if (i.Center.y <= i.OldY - i.NextDistance) {
					i.Vector.x = -abs(i.Vector.y);
					i.Vector.y = 0;

					i.OldX = i.Center.x;
					i.OldY = i.Center.y;

					i.NextDistance += RectSpiral_Interval;
				}
			}



			if (i.Vector.x < 0 && i.Vector.y == 0) {
				if (i.Center.x <= i.OldX - i.NextDistance) {
					i.Vector.y = abs(i.Vector.x);
					i.Vector.x = 0;
					i.OldX = i.Center.x;
					i.OldY = i.Center.y;
					i.NextDistance += RectSpiral_Interval;
				}
			}

			if (i.Vector.y > 0 && i.Vector.x == 0) {
				if (i.Center.y >= i.OldY + i.NextDistance) {
					i.Vector.x = abs(i.Vector.y);
					i.Vector.y = 0;

					i.OldX = i.Center.x;
					i.OldY = i.Center.y;

					i.NextDistance += RectSpiral_Interval;
				}
			}


			break;
		case Spiral:
			
			if (i.Center.x <= Boundary_X_Min) {
				i.TopDirection = RIGHT;
				i.Coefficieient = -1.f;
			}

			if (i.Center.x >= Boundary_X_Max) {
				i.TopDirection = LEFT;
				i.Coefficieient = -1.f;
			}

			if (i.Center.y <= Boundary_Y_Min) {
				i.TopDirection = UP;
				i.Coefficieient = -1.f;
			}

			if (i.Center.y >= Boundary_Y_Max) {
				i.TopDirection = DOWN;
				i.Coefficieient = -1.f;
			}

			if (i.Coefficieient == -1.f) {
				if (i.Radius <= 0.f) {
					i.Coefficieient = 1.f;
				}
			}


			i.Vector.x = i.Coefficieient * i.Radius * ((float)cos(i.Theta * pi / 180.0));
			i.Vector.y = i.Coefficieient * i.Radius * ((float)sin(i.Theta * pi / 180.0));






			break;
		default:
			break;
		}







	}


	return RETURNVOID();
}



RETURNVOID AdvanceShape::IsoscelesTriangle::Vector_Movement(PARAMETERVOID)
{

	this->Vector_Animation();

	
	for (auto& i : this->Properties) {
		i.Center.x += i.Vector.x;
		i.Center.y += i.Vector.y;
	}

	return RETURNVOID();
}






//========================================================For Scene 5 =================================================================



RETURNVOID AdvanceShape::IsoscelesTriangle::ResetAnimationFactors(VectorType t)
{
	for (auto& i : this->Properties) {
		i.MovementType = t;

		i.ZigZag_Y_Factor = DOWN;
		i.OldX = 0;
		i.OldY = 0;
		i.NextDistance = 20;
		i.Theta = 0;
		i.Radius = 0;
		i.Coefficieient = 1.f;

	}



	this->Vector_Apply();
	return RETURNVOID();
}

RETURNVOID AdvanceShape::IsoscelesTriangle::AddSpiral(PARAMETERVOID)
{

	for (auto& i : this->Properties) {
		if (i.MovementType == Spiral) {
			i.Radius += 0.0005f * i.Coefficieient ;
			i.Theta += 1.f * i.Coefficieient;
		}
	}

	return RETURNVOID();
}