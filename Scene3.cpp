#include "Scene3.h"

constexpr auto MAX_SHAPES = 100;
constexpr auto SHAPE_SPEED = 0.005f;

//============================Scenes==========================================================

RETURNVOID Scene3::NewTriangle(IsoscelesTriangle T)
{
	if (this->ShapeCount < MAX_SHAPES) {
		this->Triangles.push_back(T);
		this->ShapeCount += 1;
	}

}

RETURNVOID Scene3::NewDot(Dot D){
	if (this->ShapeCount < MAX_SHAPES) {
		this->Dots.push_back(D);
		this->ShapeCount += 1;
	}

}

RETURNVOID Scene3::NewRect(Rectangle_ R) 
{
	if (this->ShapeCount < MAX_SHAPES) {
		this->Rectangles.push_back(R);
		this->ShapeCount += 1;
	}


}


RETURNVOID Scene3::NewLine(Line L)
{
	if (this->ShapeCount < MAX_SHAPES) {
		this->Lines.push_back(L);
		this->ShapeCount += 1;
	}

}

RETURNVOID Scene3::Render()
{

	for (auto& i : this->Triangles) {
		i.Render();
	}


	for (auto& i : this->Dots) {
		i.Render();
	}


	for (auto& i : this->Rectangles) {
		i.Render();
	}

	for (auto& i : this->Lines) {
		i.Render();
	}


}





RETURNVOID Scene3::Move(Direction D)
{
	if (D == RIGHT) {
		Vector2F Right{ SHAPE_SPEED,0.f };

		for (auto& i : this->Triangles) {
			i.Move(Right);
		}

		for (auto& i : this->Rectangles) {
			i.Move(Right);
		}

		for (auto& i : this->Dots) {
			i.Move(Right);
		}

		for (auto& i : this->Lines) {
			i.Move(Right);
		}

	}

	if (D == LEFT) {
		Vector2F Left{ SHAPE_SPEED * -1.0f ,0.f };

		for (auto& i : this->Triangles) {
			i.Move(Left);
		}

		for (auto& i : this->Rectangles) {
			i.Move(Left);
		}

		for (auto& i : this->Dots) {
			i.Move(Left);
		}

		for (auto& i : this->Lines) {
			i.Move(Left);
		}

	}


	if (D == DOWN) {
		Vector2F Down{ 0.f, SHAPE_SPEED * -1.0f };

		for (auto& i : this->Triangles) {
			i.Move(Down);
		}

		for (auto& i : this->Rectangles) {
			i.Move(Down);
		}

		for (auto& i : this->Dots) {
			i.Move(Down);
		}

		for (auto& i : this->Lines) {
			i.Move(Down);
		}

	}


	if (D == UP) {
		Vector2F Up{ 0.f, SHAPE_SPEED };

		for (auto& i : this->Triangles) {
			i.Move(Up);
		}

		for (auto& i : this->Rectangles) {
			i.Move(Up);
		}

		for (auto& i : this->Dots) {
			i.Move(Up);
		}

		for (auto& i : this->Lines) {
			i.Move(Up);
		}

	}

	


	return RETURNVOID();
}


RETURNVOID Scene3::Clear(){
	std::vector<IsoscelesTriangle>().swap(this->Triangles);
	std::vector<Rectangle_>().swap(this->Rectangles);
	std::vector<Dot>().swap(this->Dots);
	std::vector<Line>().swap(this->Lines);

	this->ShapeCount = 0;

	return RETURNVOID();
}



//============================CallBacks==========================================================

namespace Scene3_CallBackFunctions {
	Scene3 SC3{};
}


RETURNVOID Scene3_CallBackFunctions::Draw()
{


	Color4f BackGroundColor{ 0.f,0.f,0.f,1.f };

	glClearColor(BackGroundColor.r, BackGroundColor.g, BackGroundColor.b, BackGroundColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Scene3_CallBackFunctions::SC3.Render();


	glutSwapBuffers();


	return RETURNVOID();
}



RETURNVOID Scene3_CallBackFunctions::MouseOnClick(int Button,int State,int x,int y)
{
	if (Button == GLUT_LEFT_BUTTON) {

	}



	return RETURNVOID();
}

RETURNVOID Scene3_CallBackFunctions::KeyboardInput(unsigned char key, int x, int y)
{

	if (key == 't' || key == 'T') {
		
		IsoscelesTriangle newTriangle;
		newTriangle.Properties(Random, 0.f, 0.f, 0.f, 0.f, Color3f{});
		SC3.NewTriangle(newTriangle);
	} 

	if (key == 'p' || key == 'P') {

		Dot newDot;
		newDot.Properties(Random, 0.0f, 0.0f, 0.0f, Color3f{});
		SC3.NewDot(newDot);

	}

	if (key == 'r' || key == 'R') {
		Rectangle_ newRect;
		newRect.Properties(Random, 0.0f, 0.0f, 0.0f, Color3f{});
		SC3.NewRect(newRect);

	}
	
	if (key == 'l' || key == 'L') {
		Line newLine;
		newLine.Properties(Random, Point2F{0.0f,0.0f}, Point2F{ 0.0f,0.0f }, Color3f{0.0f,0.f,0.f});
		SC3.NewLine(newLine);
	}
	
	
	if (key == 'd' || key == 'D') {

		Scene3_CallBackFunctions::SC3.MoveRight = true;

	}
	if (key == 'a' || key == 'A') {
		Scene3_CallBackFunctions::SC3.MoveLeft = true;
	}

	if (key == 'w' || key == 'W') {
		Scene3_CallBackFunctions::SC3.MoveUp = true;
	}
	if (key == 's' || key == 'S') {
		Scene3_CallBackFunctions::SC3.MoveDown = true;
	}

	if (key == 'c' || key == 'C') {
		Scene3_CallBackFunctions::SC3.Clear();
	}




	glutPostRedisplay();

}



RETURNVOID Scene3_CallBackFunctions::KeyboardOff(unsigned char key, int x, int y)
{
	
	if (key == 'd' || key == 'D') {
		Scene3_CallBackFunctions::SC3.MoveRight = false;
	}

	if (key == 'a' || key == 'A') {
		Scene3_CallBackFunctions::SC3.MoveLeft = false;
	}

	if (key == 'w' || key == 'W') {
		Scene3_CallBackFunctions::SC3.MoveUp = false;
	}
	if (key == 's' || key == 'S') {
		Scene3_CallBackFunctions::SC3.MoveDown = false;
	}

	glutPostRedisplay();

}







RETURNVOID Scene3_CallBackFunctions::IdleCall(PARAMETERVOID) {


	if(Scene3_CallBackFunctions::SC3.MoveRight){
		
		Scene3_CallBackFunctions::SC3.Move(RIGHT);
	
	}


	if (Scene3_CallBackFunctions::SC3.MoveLeft) {
		Scene3_CallBackFunctions::SC3.Move(LEFT);
	}


	if (Scene3_CallBackFunctions::SC3.MoveDown) {
		Scene3_CallBackFunctions::SC3.Move(DOWN);
	}


	if (Scene3_CallBackFunctions::SC3.MoveUp) {
		Scene3_CallBackFunctions::SC3.Move(UP);
	}
	glutPostRedisplay();

}



CallbackFunc Scene3_CallBackFunctions::CreateCallBackFuctions(PARAMETERVOID) {


	CallbackFunc result;

	result.DrawCall = Scene3_CallBackFunctions::Draw;
	result.KeyboardInputCall = Scene3_CallBackFunctions::KeyboardInput;
	result.IdleCall = Scene3_CallBackFunctions::IdleCall;
	result.KeyboardOffCall = Scene3_CallBackFunctions::KeyboardOff;

	return result;
}

