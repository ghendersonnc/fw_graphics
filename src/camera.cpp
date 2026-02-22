#include "fw_graphics/camera.h"

#include <glm/gtc/matrix_transform.hpp>

uint16_t Fw::Graphics::Camera::_nextId = 0;

Fw::Graphics::Camera::Camera(const float left, const float right, const float bottom, const float top) {
    viewMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
    position = { 0.f, 0.f };
    id = _nextId;
    _nextId++;
}

Fw::Graphics::Camera::~Camera() {
    _nextId--;
}


