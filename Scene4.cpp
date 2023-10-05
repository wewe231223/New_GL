#include "Scene4.h"



Scene4::Scene4() {


}

RETURNVOID Scene4::Init()
{
	this->T1.Init();
	this->T2.Init();
	this->T3.Init();
	this->T4.Init();

	this->Horizen.Init();
	this->Vertial.Init();



	//=======================Lines===============================================




	float Width = 0.f;
	float Height = 0.f;

	float CX = 0.f;
	float CY = 0.f;


	//=========================T1===============================================

	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.4f);


	//1사분면 
	CX = this->RG.RandFloat(-1.f + Width / 2, 0.0f - Width / 2); // -
	CY = this->RG.RandFloat(0.0f, 1.f - Height); // +


	this->T1.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T1.Resister();

	//=========================T2===============================================


	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);


	CX = this->RG.RandFloat(0.0f + Width / 2, 1.f - Width / 2); // +
	CY = this->RG.RandFloat(0.0f + Height / 2, 0.9f - Height / 2); // +


	this->T2.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T2.Resister();

	//=========================T3===============================================


	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);

	CX = this->RG.RandFloat(-1.f + Width / 2, 0.0f - Width / 2); // -
	CY = this->RG.RandFloat(-1.f  , 0.0f - Height); // -

	this->T3.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T3.Resister();

	
	//=========================T4===============================================



	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);

	CX = this->RG.RandFloat(0.0f + Width / 2, 1.f - Width / 2); // -
	CY = this->RG.RandFloat(-1.f, 0.0f - Height); // -

	this->T4.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T4.Resister();


	//=========================testarea===================================






	return RETURNVOID();
}




RETURNVOID Scene4::Render()
{

	this->Horizen.Render();
	this->Vertial.Render();


	this->T1.Render();
	this->T2.Render();
	this->T3.Render();
	this->T4.Render();

	






	return RETURNVOID();
}

RETURNVOID Scene4::Clicked(Qudrant Q, Point2F GP)
{
	float Width{};
	float Height{};

	if (Q == Q1) {

		
		Width = this->RG.RandFloat(0.1f, 0.5f);
		Height = this->RG.RandFloat(0.1f, 0.5f);




		this->T1.Properties(Defined,
			GP.x,
			GP.y,
			Width,
			Height,
			Color3f{
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f)
			}
		);
		this->T1.Resister();

	}
	else if (Q == Q2) {
		Width = this->RG.RandFloat(0.1f, 0.5f);
		Height = this->RG.RandFloat(0.1f, 0.5f);




		this->T2.Properties(Defined,
			GP.x,
			GP.y,
			Width,
			Height,
			Color3f{
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f)
			}
		);
		this->T2.Resister();
	}
	else if (Q == Q3) {
		Width = this->RG.RandFloat(0.1f, 0.5f);
		Height = this->RG.RandFloat(0.1f, 0.5f);




		this->T3.Properties(Defined,
			GP.x,
			GP.y,
			Width,
			Height,
			Color3f{
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f)
			}
		);
		this->T3.Resister();





	}
	else {
		Width = this->RG.RandFloat(0.1f, 0.5f);
		Height = this->RG.RandFloat(0.1f, 0.5f);




		this->T4.Properties(Defined,
			GP.x,
			GP.y,
			Width,
			Height,
			Color3f{
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f),
				this->RG.RandFloat(0.f,1.f)
			}
		);
		this->T4.Resister();
	}






	return RETURNVOID();
}


RETURNVOID Scene4::Reset()
{
	float Width = 0.f;
	float Height = 0.f;

	float CX = 0.f;
	float CY = 0.f;


	//=========================T1===============================================

	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.4f);


	//1사분면 
	CX = this->RG.RandFloat(-1.f + Width / 2, 0.0f - Width / 2); // -
	CY = this->RG.RandFloat(0.0f, 1.f - Height); // +


	this->T1.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T1.Resister();

	//=========================T2===============================================


	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);


	CX = this->RG.RandFloat(0.0f + Width / 2, 1.f - Width / 2); // +
	CY = this->RG.RandFloat(0.0f + Height / 2, 0.9f - Height / 2); // +


	this->T2.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T2.Resister();

	//=========================T3===============================================


	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);

	CX = this->RG.RandFloat(-1.f + Width / 2, 0.0f - Width / 2); // -
	CY = this->RG.RandFloat(-1.f, 0.0f - Height); // -

	this->T3.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T3.Resister();


	//=========================T4===============================================



	Width = this->RG.RandFloat(0.1f, 0.5f);
	Height = this->RG.RandFloat(0.1f, 0.5f);

	CX = this->RG.RandFloat(0.0f + Width / 2, 1.f - Width / 2); // -
	CY = this->RG.RandFloat(-1.f, 0.0f - Height); // -

	this->T4.Properties(Defined,
		CX,
		CY,
		Width,
		Height,
		Color3f{
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f),
			this->RG.RandFloat(0.f,1.f)
		}
	);
	this->T4.Resister();



	return RETURNVOID();
}

RETURNVOID Scene4::Mode(GLenum M)
{

	this->T1.RenderMode(M);
	this->T2.RenderMode(M);
	this->T3.RenderMode(M);
	this->T4.RenderMode(M);


	return RETURNVOID();
}


namespace Scene4_CallBackFunctions {
	

	Scene4 SC4;


	
	RETURNVOID Draw() {

		Color4f BackGroundColor{ 0.f,0.f,0.f,1.f };

		glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		Scene4_CallBackFunctions::SC4.Render();

		glutSwapBuffers();

	}


	RETURNVOID KeyboardInput(unsigned char Key, int x , int y)
	{

		if (Key == 'r' || Key == 'R') {
			SC4.Reset();
		}
		if (Key == 'a' || Key == 'A') {
			SC4.Mode(GL_TRIANGLES);
		} 
		if (Key == 'b' || Key == 'B') {
			SC4.Mode(GL_LINE_LOOP);
		}


		glutPostRedisplay();
		return RETURNVOID();
	}

	RETURNVOID MouseInput(int Key, int State, int x, int y)
	{
		
		Point3F temp = WindowCoord_to_GLCoord___REGACY(x, y);
		Point2F GLPoint = Point2F{ temp.x,temp.y };

		if (State == GLUT_DOWN) {
			if (GLPoint.x < 0 && GLPoint.y > 0) {
				//1사분면
				SC4.Clicked(Q1, GLPoint);
			}

			if (GLPoint.x > 0 && GLPoint.y > 0) {
				//2사분면
				SC4.Clicked(Q2, GLPoint);

			}


			if (GLPoint.x < 0 && GLPoint.y < 0) {
				//3사분면
				SC4.Clicked(Q3, GLPoint);

			}


			if (GLPoint.x > 0 && GLPoint.y < 0) {
				//4사분면
				SC4.Clicked(Q4, GLPoint);

			}




		}


		glutPostRedisplay();

		return RETURNVOID();
	}




	CallbackFunc Resister_Scene4(PARAMETERVOID) {
		Scene4_CallBackFunctions::SC4.Init();


		CallbackFunc result{};

		result.DrawCall = Scene4_CallBackFunctions::Draw;
		result.KeyboardInputCall = KeyboardInput;
		result.MouseCall = MouseInput;


		return result;

	}



}
