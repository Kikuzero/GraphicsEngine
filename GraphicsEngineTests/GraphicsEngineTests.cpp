#include "pch.h"
#include "CppUnitTest.h"
#include "../GraphicsEngine/Viewer.h"
#include "../GraphicsEngine/ViewObject.h"
#include "../GraphicsEngine/Texture.h"
#include "../GraphicsEngine/Animation.h"
#include "../GraphicsEngine/Shader.h"
#include "../GraphicsEngine/Circle.h"
#include "../GraphicsEngine/Quadrangle.h"
#include "../GraphicsEngine/Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphicsEngineTests
{
	TEST_CLASS(GraphicsEngineTests)
	{
	public:
		
		TEST_METHOD(SceneCreationTest)
		{
			const auto testWidth = 640;
			const auto testHeight = 480;
			auto *v = new GraphicsEngine::Viewer(testWidth, testHeight);
			Assert::IsTrue(v != nullptr, L"Viewer is not created");
			Assert::AreEqual(v->GetWidth(), testWidth, L"Bad width");
			Assert::AreEqual(v->GetHeight(), testHeight, L"Bad height");
		}

		TEST_METHOD(PremitivesCreationTest)
		{
			GLfloat* t_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			GLfloat* q_Positions = new GLfloat[]{ .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f,   .0f,.0f,.0f, };
			
			const auto x = 0, y = 0, z = 0, radius = 5;
			//auto* circle = new GraphicsEngine::Circle(x, y, z, radius);
			//Assert::IsTrue(circle != nullptr, L"Circle is not created");
			auto* triangle = new GraphicsEngine::Triangle(x, y, t_Positions);
			Assert::IsTrue(triangle != nullptr, L"Triangle is not created");

			auto* quad = new GraphicsEngine::Quadrangle(x, y, q_Positions);
			Assert::IsTrue(quad != nullptr, L"Quadrangle is not created");

		}
		
		TEST_METHOD(TextureAdditionTest)
		{
			
		}

		TEST_METHOD(ShaderAdditionTest)
		{
			
		}

		TEST_METHOD(AnimationTest)
		{
			
		}
	};
}
