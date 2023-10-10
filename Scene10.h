#pragma once
#include "Scene3D.h"



class Scene10 : public Scene3D{
private:

public:
	Scene10() = default;
	RETURNVOID Init();
};

namespace Scene10_ {
	RETURNVOID Draw();
	RETURNVOID Reshape(int, int);
	CallbackFunc Run();
}


