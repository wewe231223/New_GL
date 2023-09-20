#include "Scene1.h"

Scene1_Rect::Scene1_Rect(PARAMETERVOID){
	//this->ScaleByScreen(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

RETURNVOID Scene1_Rect::Draw(PARAMETERVOID)
{




	glColor3f(this->Color.r, this->Color.g, this->Color.b);
	glRectf(
		this->Center.x - this->Size.Width	/	2,
		this->Center.y - this->Size.Height	/	2,
		this->Center.x + this->Size.Width	/	2,
		this->Center.y + this->Size.Height	/	2);


}




// ===============================Scene=======================================================================




Scene1::Scene1(PARAMETERVOID) {

	Scene1_Rect NewRect;
	this->Rects.push_back(NewRect);


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
		std::cout << "Draw!" << std::endl;
	}


}


namespace CallBackFunctions {

	Scene1 SC1;


	RETURNVOID Render(PARAMETERVOID) {
		SC1.Render();
		glutSwapBuffers();

	}


	RETURNVOID ReShape(int width, int height) {

		if (height == 0) {
			height = 1;
		}

		// Set the viewport to be the entire window
		glViewport(0, 0, width, height);

		// Reset the coordinate system before modifying
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set the orthographic projection considering the aspect ratio
		float aspectRatio = (float)width / height;
		if (width >= height) {
			glOrtho(-aspectRatio, aspectRatio, -1.0, 1.0, -1.0, 1.0);
		}
		else {
			glOrtho(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, -1.0, 1.0);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}


	CallbackFunc CreateCallBackFunction(PARAMETERVOID) {
		CallbackFunc result;

		result.DrawCall = CallBackFunctions::Render;
		result.ReShapeCall = CallBackFunctions::ReShape;
		return result;
	}



}












