#pragma once

#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <iostream>

#include "IndexBuffer.h"
#include "IRenderer.h"
#include "VertexArray.h"
#include "Shader.h"

namespace GraphicsEngine
{
    class StickRenderer : public IRenderer
    {
    public:
        void Draw(const VertexArray&, const IndexBuffer&, const Shader&) const override;
    };
}