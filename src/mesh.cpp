// ReSharper disable CppClangTidyPerformanceNoIntToPtr
#include <type_traits>

#include "fw_graphics/mesh.h"
#include "fw_graphics/vertex_f.h"
#include "fw_graphics/vertex_int8.h"

template <typename T>
void Fw::Graphics::Mesh::handleBuffersAndArrays(const std::vector<T>& vertices) {
    _vertexArray.bind();
    const long long vertexBufferSize = static_cast<long long>(sizeof(T)) * static_cast<GLsizeiptr>(vertices.size());
    const long long indexBufferSize = static_cast<long long>(sizeof(int)) * static_cast<GLsizeiptr>(_indices.size());
    _vertexBuffer.setData(vertices, vertexBufferSize);
    _indexBuffer.setData(_indices, indexBufferSize);

    const auto vertexPositionOffset = reinterpret_cast<void*>(offsetof(T, vertexPosition));
    const auto colorValueOffset = reinterpret_cast<void*>(offsetof(T, colorValue));

    if (std::is_same_v<T, Vertexi8>)
    {
        _vertexArray.linkAttributes(_vertexBuffer, 0, 2, GL_BYTE, sizeof(T), vertexPositionOffset);
    } else if (std::is_same_v<T, Vertexf>)
    {
        _vertexArray.linkAttributes(_vertexBuffer, 0, 2, GL_FLOAT, sizeof(T), vertexPositionOffset);
    }

    _vertexArray.linkAttributes(_vertexBuffer, 1, 3, GL_FLOAT, sizeof(T), colorValueOffset);
}

template void Fw::Graphics::Mesh::handleBuffersAndArrays(const std::vector<Vertexi8>& vertices);
template void Fw::Graphics::Mesh::handleBuffersAndArrays(const std::vector<Vertexf>& vertices);

template <typename T>
bool Fw::Graphics::Mesh::canDraw(std::vector<T>& vertices) {
    if (!_canDraw)
    {
        if (vertices.empty() || _indices.empty())
        {
            return false;
        }
        this->handleBuffersAndArrays(vertices);
        _canDraw = true;
        return false;
    }

    return _canDraw;
}
template bool Fw::Graphics::Mesh::canDraw(std::vector<Vertexi8>& vertices);
template bool Fw::Graphics::Mesh::canDraw(std::vector<Vertexf>& vertices);
void Fw::Graphics::Mesh::draw() const {
    glDrawElements(GL_TRIANGLES, _elementCount, GL_UNSIGNED_INT, nullptr);
}
