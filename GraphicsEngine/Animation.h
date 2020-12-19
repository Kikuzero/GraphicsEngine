#pragma once
#include <string>
#include <vector>

#include "IDrawable.h"
#include "Sprite.h"
#include "Texture.h"
#include "ViewObject.h"

namespace GraphicsEngine
{
	class Animation : public IDrawable
	{
	public:
		explicit Animation(const std::vector<std::string>&, float, float, float[], float[]);

		void bind(int, int) override;
		void animate(int);
		void draw() override;
		
		std::vector<std::string> GetPaths() { return m_Paths; }
	private:
		std::vector<std::string> m_Paths;
		//std::vector<Texture*> textures;
		std::vector<Sprite*> m_Sprites;

		int m_StupidCounter;
		unsigned int m_Indexer;

		//GraphicsEngine::Shader* m_Shader;

		void createTextures(float, float, float[], float[]);
	};
}
