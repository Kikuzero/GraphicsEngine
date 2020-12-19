#pragma once

#include <string>

#include "Renderer.h"


namespace GraphicsEngine
{
	class Texture
	{
	private:
		unsigned int m_RendererID;
		std::string m_FilePath;
		unsigned char* m_LocalBuffer;
		int m_Width, m_Height, m_BPP;

	public:
		Texture(std::string);
		~Texture();

		void Bind(unsigned int = 0) const;
		void Unbind() const;

		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }
		inline int GetBPP() { return m_BPP; }
		inline unsigned int GetID() { return m_RendererID; }
	};
}
