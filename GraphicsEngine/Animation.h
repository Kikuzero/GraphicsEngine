#pragma once
#include <string>
#include <vector>



#include "IDrawable.h"
#include "Sprite.h"
#include "Texture.h"
#include "ViewObject.h"

class Animation : public IDrawable
{
public:
	explicit Animation(const std::vector<std::string>&, float, float, float[]);

	void bind(int, int) override;
	void animate(int);
	void draw() override;
	
private:
	std::vector<std::string> m_Paths;
	//std::vector<Texture*> textures;
	std::vector<GraphicsEngine::Sprite*> m_Sprites;

	int m_StupidCounter;
	unsigned int m_Indexer;
	
	//GraphicsEngine::Shader* m_Shader;
	
	void createTextures(float, float, float[]);
};

