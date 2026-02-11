#pragma once
#include <vector>

#include "fw_graphics/vertex_array.h"
#include "fw_graphics/vertex_buffer.h"
#include "fw_graphics/index_buffer.h"
#include "fw_graphics/shader.h"
#include "fw_graphics/vertex.h"

namespace Fw::Graphics::Meshes
{
    class Mesh
    {
    public:
        Mesh() = default;
        virtual ~Mesh() = default;
        virtual void drawElements(Shader& shader) = 0;
    protected:
        VertexArray _vertexArray;
        VertexBuffer _vertexBuffer;
        IndexBuffer _indexBuffer;
        std::vector<Vertex> _vertices;
        std::vector<int> _indices;
        int _elementCount = 0;

        bool _canDraw = false;
    };
}
