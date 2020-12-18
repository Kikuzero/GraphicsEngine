#include "Quadrangle.h"

namespace GraphicsEngine
{
    Quadrangle::Quadrangle(float _x, float _y, float _vp[]) : ViewObject()
    {
        Init(_x, _y);
        m_VertexBufferData = _vp;
    }

    Quadrangle::Quadrangle(float _x, float _y, float _vp[], float _tp[]) : ViewObject()
    {
        Init(_x, _y);
        m_VertexBufferData = _vp;
        m_TextureCoords = _tp;
    }
	
    Quadrangle::Quadrangle(std::string _path, float _x, float _y, float _vp[]) : ViewObject(_path)
    {
        Init(_x, _y);
        m_VertexBufferData = _vp;
    }

    Quadrangle::Quadrangle(std::string _path, float _x, float _y, GLfloat _vp[], GLfloat _tp[]) : ViewObject(_path)
    {
        Init(_x, _y);
        m_VertexBufferData = _vp;
        m_TextureCoords = _tp;
    }

    Quadrangle::Quadrangle(float _x, float _y, float _w, float _h) : ViewObject()
    {
        Init(_x, _y);
        m_VertexBufferData = new float[(m_Dem + 2) * 4]{ 0 };
        //m_VertexBufferData = _vp;

    }

	void Quadrangle::Init(float _x, float _y)
    {
        m_Type = T_Quadrangle;

        m_Position = glm::vec3(_x, _y, 0);
    	
        m_Dem = 3;
        m_CountVert = 4;
        m_CountInd = 6;

        m_Indeces = new unsigned int[m_CountInd] {0, 1, 3,
            1, 3, 2};

        m_MVP = glm::translate(m_MVP, m_Position);
    }
}
