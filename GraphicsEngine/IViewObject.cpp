#include "IViewObject.h"
#include <iostream>

namespace GraphicsEngine
{
    IViewObject::IViewObject()
    {
        m_Shader = new Shader("Basic.shader");

        m_Color = new float[3]{ 1.0, 1.0, 1.0 };

        m_MVP = glm::mat4(1.0f);
        m_Position = glm::vec3(1.f, 1.f, 1.f);
        m_Scale = glm::vec3(1.f, 1.f, 1.f);
        m_VecRot = glm::vec3(0.f, 0.f, 1.f);
        m_Angle = 0;
    }

    void IViewObject::setColor(float _c[])
    {
        delete m_Color;
        m_Color = _c;
    }

    void IViewObject::setShader(Shader& _shader)
    {
        m_Shader = &_shader;
        m_Shader->Unbind();
    }

    void IViewObject::setMVP(glm::mat4 _mat)
    {
        m_MVP = _mat;
    }

    void IViewObject::setScreenPosition(int _w, int _h)
    {
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, (float)_w, (float)_h, 0.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, m_Position);
        m_MVP = glm::scale(m_MVP, m_Scale);
        m_MVP = glm::rotate(m_MVP, glm::radians(m_Angle), m_VecRot);
    }

    void IViewObject::setRotation(float _angle, glm::vec3 _vec)
    {
        m_Angle = _angle;
        m_VecRot = _vec;
    }

    void IViewObject::setPosition(glm::vec3 _vec)
    {
        m_Position = _vec;
    }

    void IViewObject::setScale(glm::vec3 _vec)
    {
        m_Scale = _vec;
    }

    IViewObject::~IViewObject()
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
    }
}
