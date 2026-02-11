#include "fw_graphics/vertex_array.h"

#include <cassert>

namespace Fw::Graphics
{
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &_arrayId);
    }

    void VertexArray::linkAttributes(VertexBuffer& vbo, const unsigned int layout, const int numberOfComponents, const GLenum type, const GLsizei stride, void* offset) {
        vbo.bind();
        assert(numberOfComponents <= 4 && numberOfComponents >= 1);

        glVertexAttribPointer(layout, numberOfComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        vbo.unbind();
    }

    void VertexArray::bind() {
        glBindVertexArray(_arrayId);
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
    }

    void VertexArray::destroy() {
        glDeleteVertexArrays(1, &_arrayId);
    }

    void VertexArray::removeId() {
        _arrayId = 0;
    }
}
