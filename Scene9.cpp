#include "Scene9.h"

constexpr auto pi = 3.141592f;



namespace std {
	RETURNVOID Polygon::Initialize(int poly, Point2F Center, GLfloat Length) {
		this->Init();

		this->poly = poly;
		this->Center = Center;
		this->Length = Length;


		GLfloat Unit_theta = 360.f / poly;


		GLfloat ThetaBuffer = 0.f;


		// Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
		this->Color = { this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

		if (poly == 1) {
			this->VertexArray.push_back(VertexElement{ Point3F{Center.x,Center.y,0.0f},this->Color });
			this->RenderType = GL_POINTS;
			return RETURNVOID();
		}

		if (poly == 2) {
			this->RenderType = GL_LINES;
		}


		if (poly % 2 == 0) {
			// 짝수일때(선, 사각형)
			ThetaBuffer = Unit_theta / 2;


			for (auto i = 0; i < poly; ++i) {
				this->VertexArray.push_back(VertexElement{
					Translate(Point2F{
						this->Center.x + this->Length * cosf(ThetaBuffer * pi / 180.f),
						this->Center.y + this->Length * sinf(ThetaBuffer * pi / 180.f)
					})
					,this->Color
					//,Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
					});

				ThetaBuffer += Unit_theta;

			}


		}
		else {
			// 홀수일때 
			ThetaBuffer = 90.f;


			for (auto i = 0; i < poly; ++i) {
				this->VertexArray.push_back(VertexElement{
					{Translate(Point2F{
						this->Center.x + this->Length * cosf(ThetaBuffer * pi / 180.f),
						this->Center.y + this->Length * sinf(ThetaBuffer * pi / 180.f)
					})}
					,Color
					//,Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
					});

				ThetaBuffer += Unit_theta;

			}



		}




		return RETURNVOID();
	}

	const std::vector<VertexElement> Polygon::GetVertex()
	{
		return this->VertexArray;
	}

	RETURNVOID Polygon::Render() {
		this->ClearBuffer();

		for (auto& i : this->VertexArray) {
			this->Resister(i);
		}

		AdvanceObject::Object::Render();


		glLineWidth(5.f);
		glPointSize(5.f);
		glDrawArrays(this->RenderType, 0, (GLsizei)this->VertexArray.size());


		return RETURNVOID();
	}

}

RETURNVOID std::Polygon::Update(){

	std::vector<VertexElement>().swap(this->VertexArray);


	if (this->Center.x + this->Length > GET_WINDOW_WIDTHF / 2 || this->Center.x - this->Length < - GET_WINDOW_WIDTHF / 2) {
		this->Vector.x *= -1.f;
	}

	if (this->Center.y + this->Length > GET_WINDOW_HEIGHTF / 2 || this->Center.y - this->Length <  - GET_WINDOW_HEIGHTF / 2) {
		this->Vector.y *= -1.f;
	}

	//this->Center.x += this->Vector.x;
	//this->Center.y += this->Vector.y;


	GLfloat Unit_theta = 360.f / this->poly;
	GLfloat ThetaBuffer = 0.f;


	// Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
	Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

	if (poly == 1) {
		this->VertexArray.push_back(VertexElement{ Point3F{this->Center.x,this->Center.y,0.0f},this->Color });
		this->RenderType = GL_POINTS;
		return RETURNVOID();
	}

	if (poly == 2) {
		this->RenderType = GL_LINES;
	}


	if (poly % 2 == 0) {
		// 짝수일때(선, 사각형)
		ThetaBuffer = Unit_theta / 2;


		for (auto i = 0; i < this->poly; ++i) {
			this->VertexArray.push_back(VertexElement{
				Translate(Point2F{
					this->Center.x + this->Length * cosf(ThetaBuffer * pi / 180.f),
					this->Center.y + this->Length * sinf(ThetaBuffer * pi / 180.f)
				})
				,this->Color
				//,Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
				});

			ThetaBuffer += Unit_theta;

		}


	}
	else {
		// 홀수일때 
		ThetaBuffer = 90.f;


		for (auto i = 0; i < this->poly; ++i) {
			this->VertexArray.push_back(VertexElement{
				{Translate(Point2F{
					this->Center.x + this->Length * cosf(ThetaBuffer * pi / 180.f),
					this->Center.y + this->Length * sinf(ThetaBuffer * pi / 180.f)
				})}
				,this->Color
				//,Color3f{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) }
				});

			ThetaBuffer += Unit_theta;

		}



	}




	return RETURNVOID();
}

RETURNVOID std::Polygon::Picking()
{
	this->Picked = true;
	std::cout << "Picked" << std::endl;
	this->Vector = { 0.f,0.f };

	return RETURNVOID();
}

RETURNVOID std::Polygon::Drag(GLfloat dx,GLfloat dy)
{

	if (this->Picked) {
		this->Center.x += dx;
		this->Center.y += dy;
	}

	return RETURNVOID();
}



RETURNVOID std::Polygon::UnPicking()
{
	if (this->Picked) {
		this->Picked = false;
		this->Vector = { this->RG.RandFloat(-1.f,1.f), this->RG.RandFloat(-1.f,1.f) };
	}
	return RETURNVOID();
}






RETURNVOID Scene9::Init(){
	

	for (auto i = 0; i < this->RG.RandInt(3, 7); ++i) {
		std::Polygon NewPolygon{};
		NewPolygon.Initialize(this->RG.RandInt(1, 5), Point2F{ this->RG.RandFloat(-200,200),this->RG.RandFloat(-200,200) }, this->RG.RandFloat(100, 200));
		this->Polygons.push_back(NewPolygon);
	}

	return RETURNVOID();
}

RETURNVOID Scene9::Render()
{
	for (auto& i : this->Polygons) {
		i.Render();
	}

	return RETURNVOID();
}


RETURNVOID Scene9::Update()
{
	for (auto& i : this->Polygons) {
		i.Update();
	}
	return UPDATE;
}

RETURNVOID Scene9::Pick(Point3F Point)
{
	
	std::vector<Point2F> pg{};

	for (auto& i : this->Polygons) {
		for (auto& j : i.GetVertex()) {
			pg.push_back(Point2F{ j.VertexPosition.x,j.VertexPosition.y });
		}

		if (Is_Point_in_Polygon(pg, Point2F{ Point.x,Point.y })) {
			this->OldPoint = { Point.x,Point.y };
			i.Picking();
		}

		std::vector<Point2F>().swap(pg);
	}


	return RETURNVOID();
}

RETURNVOID Scene9::Drag(Point3F Point)
{
	for (auto& i : this->Polygons) {
	
		i.Drag(this->OldPoint.x - Point.x, this->OldPoint.y - Point.y);
		this->OldPoint = { Point.x,Point.y };
	}

	return RETURNVOID();
}

RETURNVOID Scene9::UnPick(){

	for (auto& i : this->Polygons) {
		i.UnPicking();
	}

	return RETURNVOID();
}




Scene9 SC9{};

RETURNVOID Scene9_CallBackFunctions::Draw()
{

	Color4f BackColor{ 0.f,0.f,0.f,1.f };
	glClearColor(BackColor.r, BackColor.g, BackColor.b, BackColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




	SC9.Render();

	return glutSwapBuffers();
}

RETURNVOID Scene9_CallBackFunctions::Reshape(int w, int h){

	return glViewport(0, 0, w, h);
}

RETURNVOID Scene9_CallBackFunctions::Idle()
{
	SC9.Update();
	return RETURNVOID();
}

RETURNVOID Scene9_CallBackFunctions::MouseClick(int Button, int State, int x, int y)
{
	if (State == GLUT_DOWN) {
		SC9.Pick(WindowCoord_to_GLCoord(x,y));
	}

	if (State == GLUT_UP) {
		SC9.UnPick();
	}

	return RETURNVOID();
}

RETURNVOID Scene9_CallBackFunctions::MouseDrag(int x, int y)
{
	Point3F p = WindowCoord_to_GLCoord(x, y);

	SC9.Drag(p);


	return RETURNVOID();
}



CallbackFunc ResisterScene9(){
	CallbackFunc result{};
	SC9.Init();



	result.DrawCall = Scene9_CallBackFunctions::Draw;
	result.ReShapeCall = Scene9_CallBackFunctions::Reshape;
	result.IdleCall = Scene9_CallBackFunctions::Idle;
	result.MouseCall = Scene9_CallBackFunctions::MouseClick;
	result.MouseDragCall = Scene9_CallBackFunctions::MouseDrag;



	return result;
}


