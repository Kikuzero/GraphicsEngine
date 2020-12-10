#include "StickRenderer.h"

namespace GraphicsEngine
{
    void StickRenderer::Draw(const VertexArray& _va, const IndexBuffer& _ib, const Shader& _shader) const
    {
        _va.Bind();
        _ib.Bind();
        glDrawElements(GL_LINES, _ib.GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}