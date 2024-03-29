#include "Circle.h"
namespace GraphicsEngine
{
    Circle::Circle(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _radius)
    {
        m_Type = T_Circle;

        m_Dem = 3;

        m_Radius = _radius;
    	
        unsigned int numberOfSides = 128;

        //CreateVertexBuffer(_x, _y, _radius, numberOfSides);
        //CreateIndexBuffer(numberOfSides);
        m_CountVert = numberOfSides + 1;
        GLint fNumVer = m_CountVert + 1;

        GLfloat doublePi = 2.0f * M_PI;

        auto circleVerticesX = new GLfloat[fNumVer];
        auto circleVerticesY = new GLfloat[fNumVer];
        auto circleVerticesZ = new GLfloat[fNumVer];

        circleVerticesX[0] = _x;
        circleVerticesY[0] = _y;
        circleVerticesZ[0] = 0;

        for (int i = 1; i < fNumVer - 1; i++)
        {
            circleVerticesX[i] = _x + (m_Radius * cos((i + 1) * doublePi / numberOfSides));
            circleVerticesY[i] = _y + (m_Radius * sin((i + 1) * doublePi / numberOfSides));
            circleVerticesZ[i] = 0;
        }

        m_VertexBufferData = new GLfloat[fNumVer * 3];

        for (int i = 0; i < fNumVer; i++)
        {
            m_VertexBufferData[i * m_Dem] = circleVerticesX[i];
            m_VertexBufferData[(i * m_Dem) + 1] = circleVerticesY[i];
            m_VertexBufferData[(i * m_Dem) + 2] = circleVerticesZ[i];
        }

        for (int i = 0; i < fNumVer * m_Dem; i++)
            std::cout << m_VertexBufferData[i] << "\n";
    	
        m_Indeces = new GLuint[numberOfSides * m_Dem]{ 0 };

        for (int i = 1; i < numberOfSides; i++)
        {
            m_Indeces[i * m_Dem - m_Dem] = 0;
            m_Indeces[i * m_Dem + 1 - m_Dem] = i;
            m_Indeces[i * m_Dem + 2 - m_Dem] = i + 1;
        }

        m_Indeces[(numberOfSides - 1) * m_Dem] = 0;
        m_Indeces[(numberOfSides - 1) * m_Dem + 1] = numberOfSides;
        m_Indeces[(numberOfSides - 1) * m_Dem + 2] = 1;

        m_CountInd = numberOfSides * m_Dem;
    	
        m_Position = glm::vec3(_x, _y, 0);

        m_MVP = glm::translate(m_MVP, m_Position);
    }

    void Circle::CreateVertexBuffer(GLfloat _x, GLfloat _y, GLfloat _radius, unsigned int _numberOfSides)
    {
        m_CountVert = _numberOfSides + 1;
        GLint fNumVer = m_CountVert + 1;

        GLfloat doublePi = 2.0f * M_PI;

        auto circleVerticesX = new GLfloat[fNumVer];
        auto circleVerticesY = new GLfloat[fNumVer];
        auto circleVerticesZ = new GLfloat[fNumVer];

        circleVerticesX[0] = _x;
        circleVerticesY[0] = _y;
        circleVerticesZ[0] = 0;

        for (int i = 1; i < fNumVer - 1; i++)
        {
            circleVerticesX[i] = _x + (_radius * cos((i + 1) * doublePi / _numberOfSides));
            circleVerticesY[i] = _y + (_radius * sin((i + 1) * doublePi / _numberOfSides));
            circleVerticesZ[i] = 0;
        }

        m_VertexBufferData = new GLfloat[fNumVer * 3];

        for (int i = 0; i < fNumVer; i++)
        {
            m_VertexBufferData[i * m_Dem] = circleVerticesX[i];
            m_VertexBufferData[(i * m_Dem) + 1] = circleVerticesY[i];
            m_VertexBufferData[(i * m_Dem) + 2] = circleVerticesZ[i];
        }

       
    }

    void Circle::CreateIndexBuffer(unsigned int _numberOfSides)
    {
        m_Indeces = new GLuint[_numberOfSides * m_Dem]{ 0 };

        for (int i = 1; i < _numberOfSides; i++)
        {
            m_Indeces[i * m_Dem - m_Dem] = 0;
            m_Indeces[i * m_Dem + 1 - m_Dem] = i;
            m_Indeces[i * m_Dem + 2 - m_Dem] = i + 1;
        }

        m_Indeces[(_numberOfSides - 1) * m_Dem] = 0;
        m_Indeces[(_numberOfSides - 1) * m_Dem + 1] = _numberOfSides;
        m_Indeces[(_numberOfSides - 1) * m_Dem + 2] = 1;

        m_CountInd = _numberOfSides * m_Dem;
    }
}
