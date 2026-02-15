#pragma once
#include "fw_graphics/index_buffer.h"
#include "fw_graphics/shader.h"
#include "fw_graphics/vertex_array.h"

namespace Fw::Graphics
{
    class Renderer2D
    {
    public:
        Renderer2D() = default;
        void clear();
        void draw(const int elementCount, VertexArray& vao, IndexBuffer& ebo, const Shader& shader);

    };
}