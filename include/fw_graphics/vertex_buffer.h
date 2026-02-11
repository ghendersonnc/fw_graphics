#pragma once
#include <vector>
#include <glad/glad.h>

namespace Fw::Graphics {

    class VertexBuffer
    {
    public:
        VertexBuffer();
        VertexBuffer(const std::vector<float>& vertices, GLsizeiptr size);

        template <class T>
        void setData(const std::vector<T>& vertices, const GLsizeiptr size) const {
            glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
            glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);
        }

        void bind() const;
        void unbind() const;
        void destroy() const;
        void removeId();

    private:
        GLuint _bufferId;
    };
}