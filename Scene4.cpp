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

	this->GuideLine1.Init();
	this->GuideLine2.Init();
	this->GuideLine3.Init();
	this->GuideLine4.Init();



	//========================Lines================================================

	this->Horizen.Properties(Defined, Point2F{ -1.0f,0.f }, Point2F{ 1.0f,0.f }, Color3f{ 1.f,1.f,1.f });
	this->Horizen.Resister();
	this->Horizen.ApplyThickness(0.3f);


	this->Vertial.Properties(Defined, Point2F{ 0.0f,-1.f }, Point2F{ 0.0f,1.f }, Color3f{ 1.f,1.f,1.f });
	this->Vertial.Resister();
	this->Vertial.ApplyThickness(0.3f);

	this->GuideLine1.Properties(Defined, Point2F{ -1.f,-1.f }, Point2F{ -1.f,1.f }, Color3f{ 1.f,1.f,1.f });
	this->GuideLine1.Resister();
	this->GuideLine1.ApplyThickness(0.3f);


	this->GuideLine2.Properties(Defined, Point2F{ -1.f,1.f }, Point2F{ 1.f,1.f }, Color3f{ 1.f,1.f,1.f });
	this->GuideLine2.Resister();
	this->GuideLine2.ApplyThickness(0.3f);


	this->GuideLine3.Properties(Defined, Point2F{ 1.f,1.f }, Point2F{ 1.f,-1.f }, Color3f{ 1.f,1.f,1.f });
	this->GuideLine3.Resister();
	this->GuideLine3.ApplyThickness(0.3f);


	this->GuideLine4.Properties(Defined, Point2F{ 1.f,-1.f }, Point2F{ -1.f,-1.f }, Color3f{ 1.f,1.f,1.f });
	this->GuideLine4.Resister();
	this->GuideLine4.ApplyThickness(0.3f);



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




	return RETURNVOID();
}




RETURNVOID Scene4::Render()
{

	this->Horizen.Render();
	this->Vertial.Render();

	this->GuideLine1.Render();
	this->GuideLine2.Render();
	this->GuideLine3.Render();
	this->GuideLine4.Render();


	this->T1.Render();
	this->T2.Render();
	this->T3.Render();
	this->T4.Render();


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


		glutPostRedisplay();
		return RETURNVOID();
	}




	CallbackFunc Resister_Scene4(PARAMETERVOID) {
		Scene4_CallBackFunctions::SC4.Init();


		CallbackFunc result{};

		result.DrawCall = Scene4_CallBackFunctions::Draw;
		result.KeyboardInputCall = KeyboardInput;



		return result;

	}



}
