#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Animation.h"
#include "Viewer.h"

#include "Quadrangle.h"
#include "Circle.h"
#include "Point.h"


int main()
{
	//float pos[] = {
	//	 400.f,  400.f, 0.0f,     1.0f, 0.0f,
	//	 400.f,  200.f, 0.0f,     1.0f, 1.0f,
	//	 200.f,  200.f, 0.0f,     0.0f, 1.0f,
	//	 200.f,  400.f, 0.0f,     0.0f, 0.0f
	//};

	float pos[] = {
	 400.f,  400.f, 0.0f,     
	 400.f,  200.f, 0.0f,     
	 200.f,  200.f, 0.0f,     
	 200.f,  400.f, 0.0f,   
	};

	float texPos[] = {
		1.f, 0.f,
		1.f, 1.f,
		0.f, 1.f,
		0.f, 0.f,
	};
	
	std::vector<std::string> path = { "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };
	
	GraphicsEngine::Viewer v(1000, 1000);
	auto* c = new GraphicsEngine::Circle(10, 10, 0, 40);
	//auto* c = new GraphicsEngine::Quadrangle(0, 0, pos);
	v.AddObjectToPool(c);
	//v.AddObjectToPool(new GraphicsEngine::Animation(path, 0, 0, pos, texPos));

	while (true)
	{
		v.Clear();
		v.Draw();
	}

	return 0;
}