#pragma once

#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ViewObject.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"

#include "Point.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace GraphicsEngine
{
    class Cube : public ViewObject
    {
    public:
        Cube(GLfloat, GLfloat, GLfloat []);
    };
}

