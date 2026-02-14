#include "fw_graphics/vertex_int8.h"

Fw::Graphics::Vertexi8::Vertexi8(const int8_t x, const int8_t y, const float r, const float g, const float b) {
    vertexPosition[0] = x;
    vertexPosition[1] = y;
    colorValue[0] = r;
    colorValue[1] = g;
    colorValue[2] = b;
}
