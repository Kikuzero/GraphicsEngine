#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "IDrawable.h"
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
    class ViewObject : public IDrawable
	{
    public:
        ViewObject();
        ViewObject(std::string);
        ~ViewObject();

        void setColor(float[]);

        void setShader(Shader &);

        void setMVP(glm::mat4);

        void setScreenPosition(int, int);

        void setRotation(float, glm::vec3);

        inline float GetRotation() { return m_Angle; }
    	
        void setPosition(glm::vec3);

        inline glm::vec3 GetPosition() { return m_Position; }
    	
        void setScale(glm::vec3);

        inline Types GetType() { return m_Type; }
    	
        void bind(int, int) override;
    	
    	void draw() override;

    protected:
        Types m_Type;
        glm::vec3 m_Position;
        glm::vec3 m_Scale;
        glm::vec3 m_VecRot;
        float m_Angle;
    	
        unsigned int m_Dem;
        unsigned int m_CountVert;
        unsigned int m_CountInd;

        GLfloat *m_VertexBufferData;
        GLfloat* m_TextureCoords;
    	unsigned int *m_Indeces;

        Renderer renderer; //TODO: Переименовать
        VertexArray *m_VA;
        VertexBuffer *m_VB_c;
        VertexBuffer *m_VB_tc;
        IndexBuffer *m_IB;
        VertexBufferLayout *m_Layout_c;
        VertexBufferLayout *m_Layout_tc; //TODO: удалить ненужное

        Texture* m_Texture;

        Shader *m_Shader;
        float *m_Color;

        glm::mat4 m_MVP;
    	
        void zip();
        GLfloat* createVertTexPos();
    };
}
