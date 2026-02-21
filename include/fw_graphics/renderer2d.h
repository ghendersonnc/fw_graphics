#pragma once
#include "fw_graphics/index_buffer.h"
#include "fw_graphics/shader.h"
#include "fw_graphics/vertex_array.h"

namespace Fw::Graphics
{
    class Renderer2D
    {
    public:
        bool isWireFrame = false;
        
        Renderer2D() = default;
        void clear();
        void draw(const int elementCount, VertexArray& vao, const Shader& shader);
        void wireframeToggle();


    };
}