#include "fw_graphics/renderer2d.h"
#include <glad/glad.h>



void Fw::Graphics::Renderer2D::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Fw::Graphics::Renderer2D::draw(const int elementCount, VertexArray& vao, const Shader& shader) {
    shader.use();
    vao.bind();
    glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, nullptr);
}
