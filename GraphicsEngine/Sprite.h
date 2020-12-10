#pragma once
#include "Quadrangle.h"
#include "ViewObject.h"

namespace GraphicsEngine
{
	class Sprite : public Quadrangle
	{
	public:
		Sprite(std::string, float, float, float[]);
	};
}


