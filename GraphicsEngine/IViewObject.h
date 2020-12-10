#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Texture.h"
#include "Shader.h"
#include "Renderer.h"
#include "Point.h"

#include "Types.h"

namespace GraphicsEngine {
	class IViewObject {
    public:
        IViewObject();
        virtual ~IViewObject();

        void setColor(float[]);

        void setShader(Shader&);

        void setMVP(glm::mat4);

        void setScreenPosition(int, int);

        void setRotation(float, glm::vec3);

        void setPosition(glm::vec3);

        void setScale(glm::vec3);

        void setTexCoords(GLfloat*);

        virtual void draw() = 0;

    protected:
        Types m_Type;
        glm::vec3 m_Position;
        glm::vec3 m_Scale;
        glm::vec3 m_VecRot;
        float m_Angle;

        unsigned int m_Dem;
        unsigned int m_CountVert;
        unsigned int m_CountInd;

        GLfloat* m_VertexBufferData;
        GLfloat* m_TextureCoords;
        unsigned int* m_Indeces;

        Renderer renderer;
        VertexArray* m_VA;
        VertexBuffer* m_VB_c;
        VertexBuffer* m_VB_tc;
        IndexBuffer* m_IB;
        VertexBufferLayout* m_Layout_c;
        VertexBufferLayout* m_Layout_tc;

        Shader* m_Shader;
        float* m_Color;

        glm::mat4 m_MVP;

        virtual void zip() = 0;
    };
}
