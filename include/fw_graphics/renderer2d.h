#pragma once
#include <unordered_map>

#include "fw_graphics/camera.h"
#include "fw_graphics/shader.h"
#include "fw_graphics/vertex_array.h"

namespace Fw::Graphics
{
    class Renderer2D
    {
    public:
        std::unordered_map<std::string, Camera> cameras;
        bool isWireFrame = false;
        
        Renderer2D() = default;
        void clear();
        void draw(int elementCount, VertexArray& vao, const Shader& shader);
        void wireframeToggle();
        void addOrthographicCamera(float left, float right, float bottom, float top);


    };
}