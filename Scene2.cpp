#include "Scene2.h"


Particle::Particle(SizeF s,Point2F p,Vector2F dir, Color3f c){


	this->Center.x = p.x;
	this->Center.y = p.y;



	this->Size.Height = s.Height;
	this->Size.Width = s.Width;


	this->Color.r = c.r;
	this->Color.g = c.g;
	this->Color.b = c.b;

	this->Direction.x = dir.x;
	this->Direction.y = dir.y;





}


RETURNVOID Particle::Draw()
{
	
	glColor3f(this->Color.r, this->Color.g, this->Color.b);
	glRectf(
		this->Center.x - this->Size.Width / 2,
		this->Center.y - this->Size.Height / 2,
		this->Center.x + this->Size.Width / 2,
		this->Center.y + this->Size.Height / 2);

	return RETURNVOID();
}



//=================================Particle Rect====================================================================



ParticleRect::ParticleRect(){
	this->Size.Width = 0.5f;
	this->Size.Height = 0.5f;

	this->ScaleByScreen(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}





RETURNVOID ParticleRect::Clicked(PARAMETERVOID)
{
	this->Visible = false;

	int type = this->RandomEngine.RandInt(1, 3);

	if (type == 1) {

		this->CreateParticle_CrossType(0.005f);
	}
	else if (type == 2) {
		this->CreateParticle_DiagnalType(0.005f);
	}
	else if (type == 3) {
		this->CreateParticle_OctagonType(0.005f);
	}

	return RETURNVOID();
}

RETURNVOID ParticleRect::CreateParticle_CrossType(float interval){

	//일단 4등분한 센터 4개 생성
	// 사이즈(너비, 높이)는 모두 같다  
	SizeF Particle_size{this->Size.Width / 2 - interval / 2 , this->Size.Height / 2 - interval / 2};
	Color3f Particle_color{ this->Color };

	//왼쪽위
	Point2F P1_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y + this->Size.Height / 4 + interval / 2};

	//왼쪽 아래 
	Point2F P2_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y - this->Size.Height / 4 - interval / 2 };
	
	//오른쪽 위
	Point2F P3_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y + this->Size.Height / 4 + interval / 2 };

	//오른쪽 아래 	
	Point2F P4_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y - this->Size.Height / 4 - interval / 2 };

	
	const float Vratio = 0.0003f;
	//위와 연동 
	Vector2F P1_Vector{				0.0f,				1.0f * Vratio};
	Vector2F P2_Vector{				-1.0f * Vratio,		0.0f };
	Vector2F P3_Vector{				1.0f * Vratio,		0.0f	};			//오른쪽 		
	Vector2F P4_Vector{				0.0f,				-1.0f * Vratio};	// 아래


	
	Particle P1(Particle_size, P1_Center, P1_Vector, Particle_color);
	Particle P2(Particle_size, P2_Center, P2_Vector, Particle_color);
	Particle P3(Particle_size, P3_Center, P3_Vector, Particle_color);
	Particle P4(Particle_size, P4_Center, P4_Vector, Particle_color);



	this->Particles.push_back(P1);
	this->Particles.push_back(P2);
	this->Particles.push_back(P3);
	this->Particles.push_back(P4);
	
	
	return RETURNVOID();
}

RETURNVOID ParticleRect::CreateParticle_DiagnalType(float interval){

	//일단 4등분한 센터 4개 생성
	// 사이즈(너비, 높이)는 모두 같다  
	SizeF Particle_size{ this->Size.Width / 2 - interval / 2 , this->Size.Height / 2 - interval / 2 };
	Color3f Particle_color{ this->Color };

	//왼쪽위
	Point2F P1_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y + this->Size.Height / 4 + interval / 2 };

	//왼쪽 아래 
	Point2F P2_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y - this->Size.Height / 4 - interval / 2 };

	//오른쪽 위
	Point2F P3_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y + this->Size.Height / 4 + interval / 2 };

	//오른쪽 아래 	
	Point2F P4_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y - this->Size.Height / 4 - interval / 2 };


	const float Vratio = 0.0003f;
	//위와 연동 
	Vector2F P1_Vector{		-1.0f*Vratio,	1.0f  * Vratio };// -1,1
	Vector2F P2_Vector{		-1.0f*Vratio,	-1.0f * Vratio };//-1,-1
	Vector2F P3_Vector{		 1.0f*Vratio,	1.0f  * Vratio };			//1,1	
	Vector2F P4_Vector{		 1.0f*Vratio,	-1.0f * Vratio };	// 1,-1



	Particle P1(Particle_size, P1_Center, P1_Vector, Particle_color);
	Particle P2(Particle_size, P2_Center, P2_Vector, Particle_color);
	Particle P3(Particle_size, P3_Center, P3_Vector, Particle_color);
	Particle P4(Particle_size, P4_Center, P4_Vector, Particle_color);



	this->Particles.push_back(P1);
	this->Particles.push_back(P2);
	this->Particles.push_back(P3);
	this->Particles.push_back(P4);



	return RETURNVOID();
}

RETURNVOID ParticleRect::CreateParticle_OctagonType(float interval){


	//일단 4등분한 센터 4개 생성
// 사이즈(너비, 높이)는 모두 같다  
	SizeF Particle_size{ this->Size.Width / 2 - interval / 2 , this->Size.Height / 2 - interval / 2 };
	Color3f Particle_color{ this->Color };

	//왼쪽위
	Point2F P1_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y + this->Size.Height / 4 + interval / 2 };

	//왼쪽 아래 
	Point2F P2_Center{ this->Center.x - this->Size.Width / 4 - interval / 2 , this->Center.y - this->Size.Height / 4 - interval / 2 };

	//오른쪽 위
	Point2F P3_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y + this->Size.Height / 4 + interval / 2 };

	//오른쪽 아래 	
	Point2F P4_Center{ this->Center.x + this->Size.Width / 4 + interval / 2, this->Center.y - this->Size.Height / 4 - interval / 2 };


	const float Vratio = 0.0003f;
	//위와 연동 
	Vector2F P1_Vector{ 0.0f,				1.0f * Vratio };
	Vector2F P2_Vector{ -1.0f * Vratio,		0.0f };
	Vector2F P3_Vector{ 1.0f * Vratio,		0.0f };			//오른쪽 		
	Vector2F P4_Vector{ 0.0f,				-1.0f * Vratio };	// 아래
	Vector2F P5_Vector{ -1.5f * Vratio,	1.5f * Vratio };// -1,1
	Vector2F P6_Vector{ -1.5f * Vratio,	-1.5f * Vratio };//-1,-1
	Vector2F P7_Vector{ 1.5f * Vratio,	1.5f * Vratio };			//1,1	
	Vector2F P8_Vector{ 1.5f * Vratio,	-1.5f * Vratio };	// 1,-1


	Particle P1(Particle_size, P1_Center, P1_Vector, Particle_color);
	Particle P2(Particle_size, P2_Center, P2_Vector, Particle_color);
	Particle P3(Particle_size, P3_Center, P3_Vector, Particle_color);
	Particle P4(Particle_size, P4_Center, P4_Vector, Particle_color);

	Particle P5(Particle_size, P1_Center, P5_Vector, Particle_color);
	Particle P6(Particle_size, P2_Center, P6_Vector, Particle_color);
	Particle P7(Particle_size, P3_Center, P7_Vector, Particle_color);
	Particle P8(Particle_size, P4_Center, P8_Vector, Particle_color);

	



	this->Particles.push_back(P1);
	this->Particles.push_back(P2);
	this->Particles.push_back(P3);
	this->Particles.push_back(P4);

	this->Particles.push_back(P5);
	this->Particles.push_back(P6);
	this->Particles.push_back(P7);
	this->Particles.push_back(P8);


	return RETURNVOID();
}








RETURNVOID ParticleRect::Draw(){

	if (this->Visible) {
		//클릭되기전 
		glColor3f(this->Color.r, this->Color.g, this->Color.b);
		glRectf(
			this->Center.x - this->Size.Width / 2,
			this->Center.y - this->Size.Height / 2,
			this->Center.x + this->Size.Width / 2,
			this->Center.y + this->Size.Height / 2);
	}
	else {
		//클릭되고 난 후 

		for (auto& i : this->Particles) {
			i.Draw();
		}


	}

	return RETURNVOID();
}





bool ParticleRect::IsPointInside(int PixelX, int PixelY) {
	float glX, glY = 0;
	glX = static_cast<float>(PixelX) / static_cast<float>(glutGet(GLUT_WINDOW_WIDTH)) * 2.0f - 1.0f;
	glY = 1.0f - static_cast<float>(PixelY) / static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT)) * 2.0f;


	if (glX > this->Center.x - this->Size.Width / 2 && glX < this->Center.x + this->Size.Width / 2) {
		if (glY > this->Center.y - this->Size.Height / 2 && glY < this->Center.y + this->Size.Height / 2) {
			return true;
		}
	}



	return false;

}





//=================================Scene2=============================================================================

Scene2::Scene2() {
	for (auto i = 0; i < RandomEngine.RandInt(5,15); ++i) {
		ParticleRect NewParticleRect;

		this->Rects.push_back(NewParticleRect);

	}



}


RETURNVOID Scene2::Render(){

	glClearColor(
		this->BackgroundColor.r,
		this->BackgroundColor.g,
		this->BackgroundColor.b,
		this->BackgroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& i : this->Rects) {
		i.Draw();
	}



	return RETURNVOID();
}

RETURNVOID Scene2::Reset(PARAMETERVOID)
{
	for (auto i = 0; i < this->RandomEngine.RandInt(5, 15); ++i) {
		ParticleRect NewParticleRect;

		this->Rects.push_back(NewParticleRect);

	}
	return RETURNVOID();
}

//=================================CallBackFuctions=============================================================================


namespace Scene2_CallBackFunctions {

	Scene2 SC2;

	RETURNVOID Render(PARAMETERVOID) {

		SC2.Render();



		glutSwapBuffers();

	}



	RETURNVOID ReShape(int width, int height) {

		float ScaleX = SC2.OldWidth / static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
		float ScaleY = SC2.OldHeight / static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));


		for (auto& i : SC2.Rects) {
			i.Size.Width *= ScaleX;
			i.Size.Height *= ScaleY;
		}

		SC2.OldWidth = static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
		SC2.OldHeight = static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));


		glViewport(0, 0, width, height);
	}








	RETURNVOID MouseOnClick(int Button, int State, int x, int y) {
		
		if (Button == GLUT_LEFT_BUTTON) {
			for (auto& i : SC2.Rects) {
				if (i.IsPointInside(x, y) && i.Visible) {
					i.Clicked();
					return;
				}


			}



		}
		else if (GLUT_RIGHT_BUTTON) {





		}


	}








	RETURNVOID Idle(PARAMETERVOID) {
		for (auto& i : SC2.Rects) {

			if (!i.Visible) {
				for (auto& j : i.Particles) {
					j.Center.x += j.Direction.x;
					j.Center.y += j.Direction.y;
					j.Size.Width *= 0.99f;
					j.Size.Height *= 0.99f;
				}
			}
		}


		glutPostRedisplay();
	}








	RETURNVOID KeyBoardInput(unsigned char key, int x, int y) {
		if (key == 'r') {
			std::vector<ParticleRect>().swap(SC2.Rects);
			
			SC2.Reset();
		}
		glutPostRedisplay();
	}












	CallbackFunc CreateCallBackFunction(PARAMETERVOID) {
		CallbackFunc result;

		result.DrawCall = Scene2_CallBackFunctions::Render;
		result.ReShapeCall = Scene2_CallBackFunctions::ReShape;
		result.MouseCall = Scene2_CallBackFunctions::MouseOnClick;
		result.IdleCall = Scene2_CallBackFunctions::Idle;
		result.KeyboardInputCall = Scene2_CallBackFunctions::KeyBoardInput;

		return result;
	}





}

