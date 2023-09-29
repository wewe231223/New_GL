#pragma once

typedef struct _POINT2I {
	int x;
	int y;
}Point2I;


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


inline Point2F Translate(int PixelX, int PixelY,float DisplayWidth,float DisplayHeight) {

	Point2F result{};
	 
	result.x = static_cast<float>(PixelX) / DisplayWidth * 2.0f - 1.0f;
	result.y = 1.0f - static_cast<float>(PixelY) / DisplayHeight * 2.0f;
	

	return result;
}

enum PropertiesType {
	Defined,
	Random
};