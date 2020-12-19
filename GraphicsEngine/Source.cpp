#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//#include "Animation.h"
#include "Circle.h"
#include "Quadrangle.h"
#include "Viewer.h"

//#include "Quadrangle.h"
//#include "Circle.h"
//#include "Point.h"


int main()
{
	//float pos[] = {
	//	 400.f,  400.f, 0.0f,     1.0f, 0.0f,
	//	 400.f,  200.f, 0.0f,     1.0f, 1.0f,
	//	 200.f,  200.f, 0.0f,     0.0f, 1.0f,
	//	 200.f,  400.f, 0.0f,     0.0f, 0.0f
	//};

	//float pos[] = {
	// 400.f,  400.f, 0.0f,     
	// 400.f,  200.f, 0.0f,     
	// 200.f,  200.f, 0.0f,     
	// 200.f,  400.f, 0.0f,   
	//};

	//float texPos[] = {
	//	1.f, 0.f,
	//	1.f, 1.f,
	//	0.f, 1.f,
	//	0.f, 0.f,
	//};
	
	// std::vector<std::string> path = { "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };
	
	//GraphicsEngine::Viewer v(640, 480);
	////auto* c = new GraphicsEngine::Circle(10, 10, 0, 40);
	////auto* c = new GraphicsEngine::Quadrangle(0, 0, pos);
	////v.AddObjectToPool(c);
	////v.AddObjectToPool(new GraphicsEngine::Animation(path, 0, 0, pos, texPos));

	//const auto x = 0, y = 0, z = 0, radius = 5;
	//GraphicsEngine::Circle(x, y, z, radius);
	
	//while (true)
	//{
	//	v.Clear();
	//	v.Draw();
	//}

	const auto testWidth = 640;
	const auto testHeight = 480;
	GraphicsEngine::Viewer v(testWidth, testHeight);

	GLfloat* q_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
	const auto x = 0, y = 0;
	auto* quad = new GraphicsEngine::Quadrangle(x, y, q_Positions);
	std::cout << (quad->GetType() != GraphicsEngine::T_Quadrangle) << "\n";

	//std::string path = "../GraphicsEngine/res/tex.jpg";
	//auto* vo = new GraphicsEngine::ViewObject(path);
	
	return 0;
}