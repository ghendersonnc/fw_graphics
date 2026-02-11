#pragma once
#include "vertex_buffer.h"

#include <glad/glad.h>
namespace Fw::Graphics {
    class VertexArray
    {
    public:
        VertexArray();
        void linkAttributes(VertexBuffer& vbo, const unsigned int layout, const int numberOfComponents, const GLenum type, GLsizei stride, void* offset);
        void bind();
        void unbind();
        void destroy();
        void removeId();
    private:
        unsigned int _arrayId;
    };
}