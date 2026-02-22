#pragma once
#include <utility>
#include <glm/glm.hpp>

namespace Fw::Graphics
{
    class Camera
    {
    public:
        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;
        std::pair<float, float> position;
        uint16_t id;
        Camera(float left, float right, float bottom, float top);
        ~Camera();
    private:
        static uint16_t _nextId;
    };
}