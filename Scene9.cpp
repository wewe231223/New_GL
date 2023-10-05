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
		Color3f Color{ this->RG.RandFloat(0.f,1.f),this->RG.RandFloat(0.f,1.f) ,this->RG.RandFloat(0.f,1.f) };

		if (poly == 1) {
			this->VertexArray.push_back(VertexElement{ Point3F{Center.x,Center.y,0.0f},Color });
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
					,Color
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



RETURNVOID Scene9::Init(){

	std::Polygon NewPolygon{};
	NewPolygon.Initialize(7, Point2F{ 0.f,0.f }, 100.f);

	this->Polygons.push_back(NewPolygon);

	return RETURNVOID();
}

RETURNVOID Scene9::Render()
{
	for (auto& i : this->Polygons) {
		i.Render();
	}

	return RETURNVOID();
}







Scene9 SC9{};

RETURNVOID Scene_CallBackFunctions::Draw()
{

	Color4f BackColor{ 0.f,0.f,0.f,1.f };
	glClearColor(BackColor.r, BackColor.g, BackColor.b, BackColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




	SC9.Render();

	return glutSwapBuffers();
}

RETURNVOID Scene_CallBackFunctions::Reshape(int w, int h){

	return glViewport(0, 0, w, h);
}






CallbackFunc ResisterScene9(){
	CallbackFunc result{};
	SC9.Init();



	result.DrawCall = Scene_CallBackFunctions::Draw;
	result.ReShapeCall = Scene_CallBackFunctions::Reshape;





	return result;
}