#include "fw_graphics/vertex_buffer.h"


namespace Fw::Graphics
{
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &_bufferId);
    }

    VertexBuffer::VertexBuffer(const std::vector<float>& vertices, const GLsizeiptr size) {
        glGenBuffers(1, &_bufferId);
        glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);
    }
    

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    void VertexBuffer::destroy() const {
        glDeleteBuffers(1, &_bufferId);
    }

    void VertexBuffer::removeId() {
        _bufferId = 0;
    }
}
