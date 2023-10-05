#pragma once
#include <cmath>
#include <vector>
#include "GLH.h"

typedef struct _POINT2I {
	int x;
	int y;
}Point2I;

typedef struct _POINT3I {
	int x;
	int y;
	int z;
}Point3I;


typedef struct _POINT2f {
	float x;
	float y;
}Point2F;


typedef struct _POINT3F {
	float x;
	float y;
	float z;
}Point3F;

typedef Point2F PIVOT;
typedef Point2F Vector2F;
typedef Point2I Vector2I;



typedef struct _SIZE2I{
	int Width;
	int Height;
}SizeI;


typedef struct _SIZE2F {
	float Width;
	float Height;
}SizeF;

typedef struct COLOR4F {
	float r;
	float g;
	float b;
	float a;

}Color4f;

typedef struct _COLOR3F {
	float r;
	float g;
	float b;
}Color3f;




typedef struct _VERTEXPACKAGE {
	Point3F VertexPosition{};
	Color3f VertexColor{};
}VertexElement;



typedef struct _VERTEXBUFFEROBJECT {
	GLuint Position;
	GLuint Color;

}VertexBufferObject;


typedef	unsigned int VertexArrayObject;





inline Point3F WindowCoord_to_GLCoord___REGACY(int PixelX, int PixelY) {

	Point3F result{0.f,};
	 
	result.x = static_cast<float>(PixelX) / GET_WINDOW_WIDTHF * 2.0f - 1.0f;
	result.y = 1.0f - static_cast<float>(PixelY) / GET_WINDOW_HEIGHTF * 2.0f;
	

	return result;
}


inline Point3F WindowCoord_to_GLCoord(int pixelX, int PixelY) {


	
	GLfloat x = static_cast<float>(pixelX) - GET_WINDOW_WIDTHF / 2;
	GLfloat y = GET_WINDOW_HEIGHTF / 2 - static_cast<float>(PixelY);

	return Point3F{ x,y,0.f };
}




inline Point3F Translate(Point2F Pixel) {
	
	return Point3F{
		Pixel.x / (GET_WINDOW_WIDTHF / 2.f),
		Pixel.y / (GET_WINDOW_HEIGHTF / 2.f),
		0.f
	};



}


inline bool Is_Point_in_Polygon(std::vector<Point2F> polygon, Point2F point) {
	int N = (int)polygon.size();
	int counter = 0;
	Point2F p1 = polygon[0];
	for (int i = 1; i <= N; ++i) {
		Point2F p2 = polygon[i % N];
		if (point.y > std::min(p1.y, p2.y) && point.y <= std::max(p1.y, p2.y) && point.x <= std::max(p1.x, p2.x) && p1.y != p2.y) {
			double xinters = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
			if (p1.x == p2.x || point.x <= xinters)
				counter++;
		}
		p1 = p2;
	}
	return counter % 2 != 0;
}



inline bool Polygon_Collider_by_Circle(Point2F Center1,Point2F Center2,GLfloat Radius1,GLfloat Radius2) {

	if (std::powf(Center1.x - Center2.x,2.f) + std::pow(Center1.y - Center2.y,2.f) <= std::powf(Radius1 + Radius2,2.f)) {
		return true;
	}
	return false;




}


enum PropertiesType {
	Defined,
	Random
};

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};


