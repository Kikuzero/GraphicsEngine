#include "ViewObject.h"
#include <iostream>

namespace GraphicsEngine
{
    ViewObject::ViewObject()
    {
        //m_Texture = new Texture("res/tex.png");

        //std::vector<std::string> path = { "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };

        m_Shader = new Shader("ColoredShader.shader");

        //a = new Animation(m_Shader, path);
    	
        m_Color = new float[3]{1.0, 1.0, 1.0};

        m_Texture = nullptr;
        m_MVP = glm::mat4(1.0f);
        m_Position = glm::vec3(1.f, 1.f, 1.f);
        m_Scale = glm::vec3(1.f, 1.f, 1.f);
        m_VecRot = glm::vec3(0.f,0.f,1.f);
        m_Angle = 0;
        m_TextureCoords = nullptr;
    }

    ViewObject::ViewObject(std::string _texPath)
    {
        m_Texture = new Texture(_texPath);

        m_Shader = new Shader("TexturedShader.shader");

        m_Color = new float[3]{ 1.0, 1.0, 1.0 };

        m_MVP = glm::mat4(1.0f);
        m_Position = glm::vec3(1.f, 1.f, 1.f);
        m_Scale = glm::vec3(1.f, 1.f, 1.f);
        m_VecRot = glm::vec3(0.f, 0.f, 1.f);
        m_Angle = 0;
    }

    void ViewObject::setColor(float _c[])
    {
        delete m_Color;
        m_Color = _c;
    }
    
    void ViewObject::setShader(Shader &_shader)
    {
        m_Shader = &_shader;
        m_Shader->Unbind();
    }
    
    void ViewObject::setMVP(glm::mat4 _mat)
    {
        m_MVP = _mat;
    }
    
    void ViewObject::setScreenPosition(int _w, int _h)
    {
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, (float)_w, (float)_h, 0.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, m_Position);
        m_MVP = glm::scale(m_MVP, m_Scale);
        m_MVP = glm::rotate(m_MVP, glm::radians(m_Angle), m_VecRot);
    }
    
    void ViewObject::setRotation(float _angle, glm::vec3 _vec)
    {
        m_Angle = _angle;
        m_VecRot = _vec;
    }
    
    void ViewObject::setPosition(glm::vec3 _vec)
    {
        m_Position = _vec;
    }
    
    void ViewObject::setScale(glm::vec3 _vec)
    {
        m_Scale = _vec;
    }
	
    void ViewObject::zip()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    	
        m_VA = new VertexArray;
        //m_VB_c = new VertexBuffer(m_VertexBufferData, sizeof(float) * m_CountVert * (m_Dem + 2));
        m_VB_c = new VertexBuffer(createVertTexPos(), sizeof(float) * m_CountVert * (m_Dem + 2));
    	
        m_Layout_c = new VertexBufferLayout;
        m_Layout_c->Push(GL_FLOAT, m_Dem);
        m_Layout_c->Push(GL_FLOAT, 2);
        m_VA->AddBuffer(*m_VB_c, *m_Layout_c);

        m_IB = new IndexBuffer(m_Indeces, m_CountInd);


    }

    GLfloat* ViewObject::createVertTexPos()
    {
        const int countTexCoords = 2;
        if (m_TextureCoords == nullptr)
        {
            int _size = m_CountVert * countTexCoords;
            m_TextureCoords = new GLfloat[m_CountVert * countTexCoords]{ 0 };
        }
        const int size = m_CountVert * (m_Dem + countTexCoords);
	    auto* unitAr = new GLfloat[size]{0};
    	
        for(int i = 0; i < m_CountVert; i++)
        {
            for (int j = 0; j < m_Dem; j++)
            {
                unitAr[(m_Dem + countTexCoords) * i + j] = m_VertexBufferData[m_Dem * i + j];
            }
            for (int k = 0; k < countTexCoords; k++)
            {
                unitAr[(m_Dem + countTexCoords) * i + m_Dem + k] = m_TextureCoords[countTexCoords * i + k];
            }
        }

        return unitAr;
    	
    }

    void ViewObject::bind(int _x, int _y)
    {
        setScreenPosition(_x, _y);
    	
        zip();

        //setPosition(glm::vec3(100, 100, 0));
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", m_MVP);
    	if(m_Texture != nullptr)
    	{
            int id = m_Texture->GetID();
            m_Texture->Bind(id);
            m_Shader->SetUniform1i("u_Texture", static_cast<int>(id));
    	}
        else
        {
            m_Shader->SetUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], 1.0f);
        }
        //int id = m_Texture->GetID();
        //m_Texture->Bind(id);
        //m_Shader->SetUniform1i("u_Texture", 0);
        //m_Shader->SetUniform1i("u_Texture", static_cast<int>(id));
    }

    void ViewObject::draw()
    {
        renderer.Draw(*m_VA, *m_IB, *m_Shader);
        
        //m_Texture->Unbind();
        //m_Shader->Unbind();
    }

    ViewObject::~ViewObject()
    {
        delete m_VertexBufferData;
        delete m_Indeces;
        delete m_Color;
        delete m_VA;
        delete m_VB_c;
        delete m_VB_tc;
        delete m_IB;
        delete m_Layout_c;
        delete m_Layout_tc;
        delete m_Texture;
    }
}
