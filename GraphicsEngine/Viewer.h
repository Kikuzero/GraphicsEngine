#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <vector>

#include "ViewObject.h"

#include "Point.h"

#include "Types.h"

namespace GraphicsEngine
{
    class Viewer
    {
    public:
        Viewer(int, int);
        ~Viewer();

        bool IsWindowClose();

        void Clear();
        void Draw();

        void AddObjectToPool(IDrawable*);
        //void AddObjectToPool(ViewObject*);

    private:
        GLFWwindow *window;

        std::vector<IDrawable *> *m_ObjectsVect;
        //std::vector<ViewObject *> *m_ObjectsVect;

        int m_Width;
        int m_Height;

        int InitOG();
    };
}
