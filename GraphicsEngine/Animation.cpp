#include "Animation.h"

#include <iostream>

#include "Quadrangle.h"

namespace GraphicsEngine
{
	Animation::Animation(const std::vector<std::string>& _paths, float _x, float _y, float _pos[], float _texPos[])
		:m_StupidCounter(0), m_Indexer(0)
	{
		m_Paths = _paths;

		createTextures(_x, _y, _pos, _texPos);
	}

	void Animation::bind(int _x, int _y)
	{
		animate(10);
		m_Sprites.at(m_Indexer)->bind(_x, _y);
	}

	void Animation::draw()
	{
		m_Sprites.at(m_Indexer)->draw();
	}


	void Animation::animate(int _time)
	{
		if (m_StupidCounter < _time)
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

	void Animation::createTextures(float _x, float _y, float _pos[], float _texPos[])
	{
		for (auto it = m_Paths.begin(); it != m_Paths.end(); ++it)
		{
			m_Sprites.emplace_back(new GraphicsEngine::Sprite(*it, _x, _y, _pos, _texPos));
		}
	}
}