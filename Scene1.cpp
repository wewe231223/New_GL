#include "Scene1.h"

Scene1_Rect::Scene1_Rect(PARAMETERVOID){
	
	
	this->VectorX = this->RandomEngine.RandFloat(-0.05f, 0.05f);
	this->VectorY = this->RandomEngine.RandFloat(-0.05f, 0.05f);


	this->ScaleByScreen(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);


}

RETURNVOID Scene1_Rect::Draw(PARAMETERVOID)
{

	float ScreenW = static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
	float ScreenH = static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));





	this->Center.x = std::clamp(this->Center.x, -1.0f, 1.0f);
	this->Center.y = std::clamp(this->Center.y, -1.0f, 1.0f);


	glColor3f(this->Color.r, this->Color.g, this->Color.b);
	glRectf(
		this->Center.x - this->Size.Width	/	2,
		this->Center.y - this->Size.Height	/	2,
		this->Center.x + this->Size.Width	/	2,
		this->Center.y + this->Size.Height	/	2);


	if (this->Picking) {
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);

		glVertex2f(
			this->Center.x - this->Size.Width / 2, 
			this->Center.y - this->Size.Height / 2);

		glVertex2f(
			this->Center.x - this->Size.Width / 2 + this->Size.Width, 
			this->Center.y - this->Size.Height / 2);

		glVertex2f(
			this->Center.x - this->Size.Width / 2 + this->Size.Width, 
			this->Center.y - this->Size.Height / 2 + this->Size.Height);

		glVertex2f(
			this->Center.x - this->Size.Width / 2, 
			this->Center.y - this->Size.Height / 2 + this->Size.Height);


		glEnd();
	}
	


}


bool Scene1_Rect::IsPointInside(int PixelX, int PixelY) {
	float glX, glY = 0;


	glX = static_cast<float>(PixelX) / static_cast<float>(glutGet(GLUT_WINDOW_WIDTH)) * 2.0f - 1.0f;
	glY = 1.0f - static_cast<float>(PixelY) / static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT)) * 2.0f;


	std::cout << this->Center.x - this->Size.Width / 2.f << " , " << this->Center.y - this->Size.Height / 2 << std::endl;
	std::cout << glX << " , " << glY << std::endl;
	std::cout << this->Center.x + this->Size.Width / 2.f << " , " << this->Center.y + this->Size.Height / 2 << std::endl << std::endl;


	if (glX > this->Center.x - this->Size.Width / 2 && glX < this->Center.x + this->Size.Width / 2) {
		if (glY > this->Center.y - this->Size.Height / 2 && glY < this->Center.y + this->Size.Height / 2) {
			return true;
		}
	}



	return false;

}





// ===============================Scene=======================================================================




Scene1::Scene1(PARAMETERVOID) {


	for (auto i = 0; i < this->RandomEngine.RandInt(5,20); ++i) {
		Scene1_Rect NewRect;
		this->Rects.push_back(NewRect);
	}




	this->BackgroundColor.r = this->RandomEngine.RandFloat(0.f, 1.f);
	this->BackgroundColor.g = this->RandomEngine.RandFloat(0.f, 1.f);
	this->BackgroundColor.b = this->RandomEngine.RandFloat(0.f, 1.f);
	this->BackgroundColor.a = this->RandomEngine.RandFloat(0.f, 1.f);







}


RETURNVOID Scene1::Render(PARAMETERVOID) {

	glClearColor(
		this->BackgroundColor.r, 
		this->BackgroundColor.g, 
		this->BackgroundColor.b, 
		this->BackgroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& i : this->Rects) {
		i.Draw();
		
	}


}


namespace CallBackFunctions {

	Scene1 SC1;


	RETURNVOID Render(PARAMETERVOID) {

		SC1.Render();

		glutSwapBuffers();

	}


	RETURNVOID ReShape(int width, int height) {

		float ScaleX =  SC1.OldWidth / static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
		float ScaleY = SC1.OldHeight / static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));
		for (auto& i : SC1.Rects) {
			i.Size.Width *= ScaleX;
			i.Size.Height *= ScaleY;
		}




		SC1.OldWidth = static_cast<float>(glutGet(GLUT_WINDOW_WIDTH));
		SC1.OldHeight = static_cast<float>(glutGet(GLUT_WINDOW_HEIGHT));

	
		glViewport(0, 0, width, height);
	}



	
	RETURNVOID MouseOnClick(int Button, int state , int x, int y) {
		if (state == GLUT_DOWN) {

			for (auto iter = SC1.Rects.rbegin(); iter != SC1.Rects.rend(); ++iter) {

				if ((*iter).IsPointInside(x,y)) {
					(*iter).Picking = true;
					break;
				}

			}


		}
		else if (state == GLUT_UP) {

			for (auto& i : SC1.Rects) {
				i.Picking = false;
			}



		}

		glutPostRedisplay();
	}


	RETURNVOID MouseDrag(int pixelX, int pixelY) {
		int Width = glutGet(GLUT_WINDOW_WIDTH);
		int Height = glutGet(GLUT_WINDOW_HEIGHT);

		float glX, glY;

		glX = static_cast<float>(pixelX) / static_cast<float>(Width) * 2.0f - 1.0f;
		glY = 1.0f - static_cast<float>(pixelY) / static_cast<float>(Height) * 2.0f;



		for (auto iter = SC1.Rects.rbegin(); iter != SC1.Rects.rend(); ++iter) {
			if ((*iter).Picking) {
				(*iter).Center.x = glX;
				(*iter).Center.y = glY;
				break;
			}
		}

		glutPostRedisplay();
	}




	RETURNVOID Idle(PARAMETERVOID) {

	}









	CallbackFunc CreateCallBackFunction(PARAMETERVOID) {
		CallbackFunc result;

		result.DrawCall = CallBackFunctions::Render;
		result.ReShapeCall = CallBackFunctions::ReShape;
		result.MouseCall = CallBackFunctions::MouseOnClick;
		result.MouseDragCall = CallBackFunctions::MouseDrag;
		return result;
	}



}












