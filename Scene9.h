#pragma once

#include <cmath>
#include "Object.h"
#include "RandomGenerater.h"


namespace std {
	class Polygon : public AdvanceObject::Object {

	private:
		std::vector<VertexElement> VertexArray{};
		RandomGenerater RG{};

		Point2F Center{};
		GLfloat Length{};

		GLenum RenderType = GL_TRIANGLE_FAN;

		int poly = 0;

	public:

		Polygon() = default;





		RETURNVOID Initialize(int poly, Point2F Center, GLfloat Length);

		virtual RETURNVOID Render() override final;









	};

}

class Scene9{


private:
	std::vector<std::Polygon> Polygons{};

public:

	Scene9() = default;

	RETURNVOID Init();

	RETURNVOID Render();




};


namespace Scene_CallBackFunctions {


	RETURNVOID Draw();
	RETURNVOID Reshape(int,int);




}


CallbackFunc ResisterScene9();