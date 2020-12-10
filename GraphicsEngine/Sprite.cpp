#include "Sprite.h"

namespace GraphicsEngine
{
	Sprite::Sprite(std::string _texPath, float _x, float _y, float _pos[]) : Quadrangle(_texPath, _x, _y, _pos) {}
}
