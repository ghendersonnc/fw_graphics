#pragma once
#include <vector>

#include <glm/glm.hpp>

#include "fw_graphics/vertex_array.h"
#include "fw_graphics/vertex_buffer.h"
#include "fw_graphics/index_buffer.h"
#include "fw_graphics/shader.h"
#include "fw_graphics/renderer2d.h"

namespace Fw::Graphics
{
    class Mesh
    {
    public:
        Mesh() = default;
        Mesh(const Mesh&) = default;
        virtual ~Mesh() = default;
        virtual void drawElements(Shader& shader, Graphics::Renderer2D& renderer) = 0;
    protected:
        glm::mat4 _projectionMatrix;
        VertexArray _vertexArray;
        VertexBuffer _vertexBuffer;

        std::vector<int> _indices;
        int _elementCount = 0;
        IndexBuffer _indexBuffer;

        template<typename T>
        bool canDraw(std::vector<T>& vertices);

        template<typename T>
        void handleBuffersAndArrays(const std::vector<T>& vertices);

        void emptyIndexVector();
    private:
        bool _canDraw = false;
    };
}
