#include "Animation.h"

#include <iostream>

#include "Quadrangle.h"

Animation::Animation(const std::vector<std::string>& _paths, float _x, float _y, float _pos[])
	:m_StupidCounter(0), m_Indexer(0)
{
	m_Paths = _paths;
	
	createTextures(_x, _y, _pos);
}

void Animation::bind(int _x, int _y)
{
	//textures.at(m_Indexer)->Bind(m_Indexer);
	//m_Shader->SetUniform1i("u_Texture", static_cast<int>(m_Indexer)); //TODO: Вот тут бинд спрайта! Не забыть!!!!
	animate(10);
	m_Sprites.at(m_Indexer)->bind(_x, _y);
}

void Animation::draw()
{
	m_Sprites.at(m_Indexer)->draw();
}

//void Animation::setScreenPosition(int _x, int _y)
//{
//	m_Sprites.at(m_Indexer)->setScreenPosition(_x, _y);
//}


void Animation::animate(int _time)
{
	if(m_StupidCounter < _time)
	{
		m_StupidCounter++;
	}
	else
	{
		m_StupidCounter = 0;
		m_Indexer++;
	}

	if (m_Indexer >= m_Sprites.size())
	{
		m_Indexer = 0;
	}
}

void Animation::createTextures(float _x, float _y, float _pos[])
{
	for(auto it = m_Paths.begin(); it != m_Paths.end(); ++it)
	{
		//textures.emplace_back(new Texture(*it));
		m_Sprites.emplace_back(new GraphicsEngine::Sprite(*it, _x, _y, _pos));
	}
}
