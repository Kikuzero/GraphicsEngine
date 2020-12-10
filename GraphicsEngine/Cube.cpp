#include "Cube.h"

namespace GraphicsEngine
{
	Cube::Cube(GLfloat _x, GLfloat _y, GLfloat _vp[])
	{
		m_Type = T_Cube;

        m_Position = glm::vec3(_x, _y, 0);

        m_Dem = 3;

        m_VertexBufferData = _vp;
        m_CountVert = 8;
        m_CountInd = 36;

        m_Indeces = new unsigned int[m_CountInd] {
            0, 1, 3,
            1, 3, 2,
            4, 0, 7,
            0, 7, 3,
            4, 5, 7,
            5, 7, 6,
            5, 1, 6,
            1, 6, 2,
            0, 4, 5,
            5, 0, 1,
            3, 7, 6,
            6, 3, 2,
        };

        m_MVP = glm::translate(m_MVP, m_Position);

	}
}
