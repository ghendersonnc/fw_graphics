#include "fw_graphics/index_buffer.h"

Fw::Graphics::IndexBuffer::IndexBuffer() {
    glGenBuffers(1, &_bufferId);
}

Fw::Graphics::IndexBuffer::IndexBuffer(const std::vector<int>& indices, GLsizeiptr size) {
    glGenBuffers(1, &_bufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
}

void Fw::Graphics::IndexBuffer::setData(const std::vector<int>& indices, GLsizeiptr size) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
}

void Fw::Graphics::IndexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
}

void Fw::Graphics::IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Fw::Graphics::IndexBuffer::destroy() {
    glDeleteBuffers(1, &_bufferId);
}

void Fw::Graphics::IndexBuffer::removeId() {
    _bufferId = 0;
}
