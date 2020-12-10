//#include "AnimatedViewObject.h"
//
//#include <iostream>
//
//namespace GraphicsEngine
//{
//    AnimatedViewObject::AnimatedViewObject()
//    {
//        m_Paths = new std::vector<std::string>{ "res/anim/01.gif","res/anim/02.gif", "res/anim/03.gif", "res/anim/04.gif", "res/anim/06.gif", "res/anim/07.gif" };
//
//        m_Animation = new Animation(m_Shader, *m_Paths);
//    }
//
//    void AnimatedViewObject::zip()
//    {
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//        m_VA = new VertexArray;
//        m_VB_c = new VertexBuffer(m_VertexBufferData, sizeof(float) * m_CountVert * (m_Dem + 2));
//
//        m_Layout_c = new VertexBufferLayout;
//        m_Layout_c->Push(GL_FLOAT, m_Dem);
//        m_Layout_c->Push(GL_FLOAT, 2);
//        m_VA->AddBuffer(*m_VB_c, *m_Layout_c);
//
//        m_IB = new IndexBuffer(m_Indeces, m_CountInd);
//
//        m_Animation->bind();
//    }
//
//    void AnimatedViewObject::draw()
//    {
//        zip();
//
//        m_Shader->Bind();
//        m_Shader->SetUniformMat4f("u_MVP", m_MVP);
//
//        m_Animation->animate(5);
//
//        renderer.Draw(*m_VA, *m_IB, *m_Shader);
//    }
//
//    AnimatedViewObject::~AnimatedViewObject()
//    {
//        delete m_Animation;
//        delete m_Paths;
//    }
//}
