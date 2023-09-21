#include "Scene2.h"

Particle::Particle(SizeF s,Vector2F dir, Color3f c){






	this->Size.Height = s.Height / 2;
	this->Size.Width = s.Width / 2;


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


	return RETURNVOID();
}





RETURNVOID ParticleRect::Draw(){

	if (this->Visible) {
		glColor3f(this->Color.r, this->Color.g, this->Color.b);
		glRectf(
			this->Center.x - this->Size.Width / 2,
			this->Center.y - this->Size.Height / 2,
			this->Center.x + this->Size.Width / 2,
			this->Center.y + this->Size.Height / 2);
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
	for (auto i = 0; i < RandomEngine.RandInt(1,3); ++i) {
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
				if (i.IsPointInside(x, y)) {
					i.Clicked();
				}


			}



		}
		else if (GLUT_RIGHT_BUTTON) {





		}


	}






























	CallbackFunc CreateCallBackFunction(PARAMETERVOID) {
		CallbackFunc result;

		result.DrawCall = Scene2_CallBackFunctions::Render;
		result.ReShapeCall = Scene2_CallBackFunctions::ReShape;
		result.MouseCall = Scene2_CallBackFunctions::MouseOnClick;


		return result;
	}





}

