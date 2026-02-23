#include "fw_graphics/renderer2d.h"

#include <iostream>
#include <glad/glad.h>



void Fw::Graphics::Renderer2D::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rendererInfo = getRendererInfo();
}

void Fw::Graphics::Renderer2D::draw(const int elementCount, VertexArray& vao, const Shader& shader) {
    shader.use();
    vao.bind();
    glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, nullptr);
}

void Fw::Graphics::Renderer2D::wireframeToggle() {
    if (isWireFrame)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        isWireFrame = false;
    } else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        isWireFrame = true;
    }
}

void Fw::Graphics::Renderer2D::addOrthographicCamera(float left, float right, float bottom, float top) {
    cameras.try_emplace("main", left, right, bottom, top);
}

std::string Fw::Graphics::Renderer2D::getRendererInfo() {
    std::string deviceInformation;
    deviceInformation.append(reinterpret_cast<const char*>(glGetString(GL_RENDERER))).push_back('\n');
    deviceInformation.append("OpenGL ").append(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    return deviceInformation;
}
