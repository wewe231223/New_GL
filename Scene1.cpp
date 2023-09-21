#include "Scene1.h"

Scene1_Rect::Scene1_Rect(PARAMETERVOID){
	
	
	this->VectorX = this->RandomEngine.RandFloat(-0.005f, 0.005f);
	this->VectorY = this->RandomEngine.RandFloat(-0.005f, 0.005f);


	this->RectCollider.TopRight.x = this->Center.x + this->Size.Width / 2;
	this->RectCollider.TopRight.y = this->Center.y + this->Size.Height / 2;


	this->RectCollider.BottomLeft.x = this->Center.x - this->Size.Width / 2;
	this->RectCollider.BottomLeft.y = this->Center.y - this->Size.Height / 2;





}

RETURNVOID Scene1_Rect::Draw(PARAMETERVOID)
{


	this->OnWindow();


	this->RectCollider.Update(this->Size, this->Center);

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


	if (glX > this->Center.x - this->Size.Width / 2 && glX < this->Center.x + this->Size.Width / 2) {
		if (glY > this->Center.y - this->Size.Height / 2 && glY < this->Center.y + this->Size.Height / 2) {
			return true;
		}
	}



	return false;

}



RETURNVOID Scene1_Rect::OnWindow(PARAMETERVOID) {
	if (this->Center.x > 1.f - this->Size.Width / 2) {
		this->VectorX *= -1.f;
	}

	if (this->Center.x < -1.f + this->Size.Width / 2) {
		this->VectorX *= -1.f;
	}




	if (this->Center.y > 1.f - this->Size.Height / 2) {
		this->VectorY *= -1.f;
	}
	if (this->Center.y < -1.f + this->Size.Height / 2) {
		this->VectorY *= -1.f;
	}



}




// ===============================Scene=======================================================================




Scene1::Scene1(PARAMETERVOID) {
	glutSetWindowTitle("#5");

	for (auto i = 0; i < this->RandomEngine.RandInt(5, 20); ++i) {
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

	if (this->Eraser != nullptr) {
		this->Eraser->Draw();
	}


}

RETURNVOID Scene1::ReFill(PARAMETERVOID)
{
	std::vector<Scene1_Rect>().swap(this->Rects);


	for (auto i = 0; i < this->RandomEngine.RandInt(5, 20); ++i) {
		Scene1_Rect NewRect;
		this->Rects.push_back(NewRect);
	}

	return RETURNVOID();
}





// ===============================CallBacks=======================================================================




namespace Scene1_CallBackFunctions {

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



	
	RETURNVOID MouseOnClick(int Button, int state , int pixelX, int pixelY) {
		if (state == GLUT_DOWN) {
		
			SC1.Eraser = new Scene1_Rect;
			SC1.Eraser->Translate(pixelX, pixelY);
			SC1.Eraser->Color.r = 0.f;
			SC1.Eraser->Color.g = 0.f;
			SC1.Eraser->Color.b = 0.f;
			SC1.Eraser->Size.Width = 0.25f;
			SC1.Eraser->Size.Height = 0.25f;
			SC1.Eraser->ScaleByScreen(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));


			SC1.Eraser->RectCollider.TopRight.x = SC1.Eraser->Center.x + SC1.Eraser->Size.Width / 2;
			SC1.Eraser->RectCollider.TopRight.y = SC1.Eraser->Center.y + SC1.Eraser->Size.Height / 2;

			SC1.Eraser->RectCollider.BottomLeft.x = SC1.Eraser->Center.x - SC1.Eraser->Size.Width / 2;
			SC1.Eraser->RectCollider.BottomLeft.y = SC1.Eraser->Center.y - SC1.Eraser->Size.Height / 2;




			for (auto i = 0; i < SC1.Rects.size(); ++i) {
				if (SC1.Eraser->RectCollider.Check(SC1.Rects[i].RectCollider)) {
					SC1.Eraser->Color.r += (SC1.Rects[i].Color.r * 0.1f);
					SC1.Eraser->Color.g += (SC1.Rects[i].Color.g * 0.1f);
					SC1.Eraser->Color.b += (SC1.Rects[i].Color.b * 0.1f);

					SC1.Eraser->Size.Width += 0.01f;
					SC1.Eraser->Size.Height += 0.01f;


					SC1.Rects.erase(SC1.Rects.begin() + i);
				
				
				}

			}




		}
		else if (state == GLUT_UP) {
			
			
			delete SC1.Eraser;
			SC1.Eraser = nullptr;




		}


		



		glutPostRedisplay();
	}


	RETURNVOID MouseDrag(int pixelX, int pixelY) {

		SC1.Eraser->Translate(pixelX, pixelY);
		SC1.Eraser->RectCollider.Update(SC1.Eraser->Size, SC1.Eraser->Center);

		for (auto i = 0; i < SC1.Rects.size(); ++i) {
			if (SC1.Eraser->RectCollider.Check(SC1.Rects[i].RectCollider)) {
				SC1.Eraser->Color.r += (SC1.Rects[i].Color.r * 0.1f);
				SC1.Eraser->Color.g += (SC1.Rects[i].Color.g * 0.1f);
				SC1.Eraser->Color.b += (SC1.Rects[i].Color.b * 0.1f);
				SC1.Eraser->Size.Width += 0.01f;
				SC1.Eraser->Size.Height += 0.01f;


				SC1.Rects.erase(SC1.Rects.begin() + i);


			}

		}


		glutPostRedisplay();
	}




	RETURNVOID Idle(PARAMETERVOID) {

		for (auto& i : SC1.Rects) {
			i.Center.x += i.VectorX;
			i.Center.y += i.VectorY;
		}
		glutPostRedisplay();

	}



	RETURNVOID KeyboardInput(unsigned char key, int x, int y) {
		if (key == 'r') {
			
			SC1.ReFill();


		}


		glutPostRedisplay();
	}





	CallbackFunc CreateCallBackFunction(PARAMETERVOID) {
		CallbackFunc result;

		result.DrawCall = Scene1_CallBackFunctions::Render;
		result.ReShapeCall = Scene1_CallBackFunctions::ReShape;
		

		result.KeyboardInputCall = Scene1_CallBackFunctions::KeyboardInput;
		result.IdleCall = Scene1_CallBackFunctions::Idle;
		result.MouseCall = Scene1_CallBackFunctions::MouseOnClick;
		result.MouseDragCall = Scene1_CallBackFunctions::MouseDrag;

		
		return result;
	}



}












