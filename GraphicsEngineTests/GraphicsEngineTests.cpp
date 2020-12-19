#include "pch.h"
#include "CppUnitTest.h"
#include "../GraphicsEngine/ViewObject.h"
#include "../GraphicsEngine/Texture.h"
#include "../GraphicsEngine/Animation.h"
#include "../GraphicsEngine/Shader.h"
#include "../GraphicsEngine/Circle.h"
#include "../GraphicsEngine/Quadrangle.h"
#include "../GraphicsEngine/Triangle.h"
#include "../GraphicsEngine/Animation.h"
#include "../GraphicsEngine/Quadrangle.h"
#include "../GraphicsEngine/Triangle.h"
#include "../GraphicsEngine/Viewer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphicsEngineTests
{
	TEST_CLASS(SceneTests)
	{
		TEST_METHOD(SceneCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);
			//Assert::IsTrue(v != nullptr, L"Viewer is not created");
			Assert::AreEqual(v.GetWidth(), testWidth, L"Bad width");
			Assert::AreEqual(v.GetHeight(), testHeight, L"Bad height");
		}
	};

	TEST_CLASS(CircleTests)
	{
		TEST_METHOD(CircleCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			const auto x = 0, y = 0, z = 0, radius = 5;
			auto* circle = new GraphicsEngine::Circle(x, y, z, radius);
			Assert::IsTrue(circle != nullptr, L"Circle is not created");
			Assert::IsTrue(circle->GetType() == GraphicsEngine::T_Circle, L"Not circle was created");
			Assert::AreEqual(circle->GetRadius(), radius, L"Radius problem");
			Assert::AreEqual(circle->GetRotation(), .0f, L"Bad rotation");
			Assert::IsTrue(circle->GetPosition() == glm::vec3(x, y,0), L"Bad position");
		}

		TEST_METHOD(CircleAdditionToSceneTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			const auto x = 0, y = 0, z = 0, radius = 5;
			auto* circle = new GraphicsEngine::Circle(x, y, z, radius);
			Assert::IsTrue(v.GetPool()->empty(), L"Pool is not empty");
			v.AddObjectToPool(circle);
			Assert::IsTrue(v.GetPool()->size() == 1, L"Object was not added to pool");
		}
	};

	TEST_CLASS(QuadrangleTests)
	{
		TEST_METHOD(QuadrangleCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			GLfloat* q_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			const auto x = 0, y = 0;
			auto* quad = new GraphicsEngine::Quadrangle(x, y, q_Positions);
			Assert::IsTrue(quad != nullptr, L"Quadrangle is not created");
			Assert::IsTrue(quad->GetType() == GraphicsEngine::T_Quadrangle, L"Not quadrangle was created");
			Assert::AreEqual(quad->GetRotation(), .0f, L"Bad rotation");
			Assert::IsTrue(quad->GetPosition() == glm::vec3(x, y, 0), L"Bad position");
		}

		TEST_METHOD(QuadrangleAdditionToSceneTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			GLfloat* q_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			const auto x = 0, y = 0;
			auto* quad = new GraphicsEngine::Quadrangle(x, y, q_Positions);
			Assert::IsTrue(v.GetPool()->empty(), L"Pool is not empty");
			v.AddObjectToPool(quad);
			Assert::IsTrue(v.GetPool()->size() == 1, L"Object was not added to pool");
		}
	};

	TEST_CLASS(TriangleTests)
	{
		TEST_METHOD(TriangleCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			GLfloat* t_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			const auto x = 0, y = 0;
			auto* triangle = new GraphicsEngine::Triangle(x, y, t_Positions);
			Assert::IsTrue(triangle != nullptr, L"Triangle is not created");
			Assert::IsTrue(triangle->GetType() == GraphicsEngine::T_Triangle, L"Not triangle was created");
			Assert::AreEqual(triangle->GetRotation(), .0f, L"Bad rotation");
			Assert::IsTrue(triangle->GetPosition() == glm::vec3(x, y, 0), L"Bad position");
		}

		TEST_METHOD(TriangleAdditionToSceneTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			GLfloat* t_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			const auto x = 0, y = 0;
			auto* triangle = new GraphicsEngine::Triangle(x, y, t_Positions);
			Assert::IsTrue(v.GetPool()->empty(), L"Pool is not empty");
			v.AddObjectToPool(triangle);
			Assert::IsTrue(v.GetPool()->size() == 1, L"Object was not added to pool");
		}
	};

	TEST_CLASS(TextureTests)
	{
		TEST_METHOD(TextureCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			std::string path = "./res/tex.jpg";
			auto* tex = new GraphicsEngine::Texture(path);
			Assert::IsTrue(tex != nullptr, L"texture was not created");
		}

		TEST_METHOD(TextureAdditionTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			std::string path = "./res/tex.jpg";
			auto* vo = new GraphicsEngine::ViewObject(path);
			Assert::IsTrue(vo != nullptr, L"Object with texture was not created");
		}

	};
	
	TEST_CLASS(ShaderTests)
	{
		TEST_METHOD(ShaderCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			std::string path = "./ColoredShader.shader";
			auto* sh = new GraphicsEngine::Shader(path);
			Assert::IsTrue(sh != nullptr, L"Shader was not created");
		}

		TEST_METHOD(ColorShaderAdditionTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			auto* vo = new GraphicsEngine::ViewObject();
			Assert::IsTrue(vo != nullptr, L"Object with texture was not created");
		}

		TEST_METHOD(TextureShaderAdditionTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			std::string path = "./res/tex.jpg";
			auto* vo = new GraphicsEngine::ViewObject(path);
			Assert::IsTrue(vo != nullptr, L"Object with texture was not created");
		}
	};

	TEST_CLASS(AnimationTest)
	{
	public:
		TEST_METHOD(AnimationCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			GraphicsEngine::Viewer v(testWidth, testHeight);

			std::vector<std::string> path = { "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };
			GLfloat* q_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			float texPos[] = {
				1.f, 0.f,
				1.f, 1.f,
				0.f, 1.f,
				0.f, 0.f,
			};
			const auto x = 0, y = 0;
			
			auto* an = new GraphicsEngine::Animation(path, x, y, q_Positions, texPos);
			Assert::IsTrue(an != nullptr, L"Animation object was not created");
			auto vecPath = an->GetPaths();
			for (int i = 0; i < path.size(); i++)
			{
				Assert::IsTrue(path[i] == vecPath[i], L"Paths are not equal!");
			}
		}
	};
}
