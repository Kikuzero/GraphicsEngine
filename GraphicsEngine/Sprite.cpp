#include "Sprite.h"

namespace GraphicsEngine
{
	Sprite::Sprite(std::string _texPath, float _x, float _y, float _pos[], float _texPos[]) : Quadrangle(_texPath, _x, _y, _pos, _texPos) {}
}
