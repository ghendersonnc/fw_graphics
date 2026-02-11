#include "fw_graphics/vertex.h"

Fw::Graphics::Vertex::Vertex(int8_t x, int8_t y, float r, float g, float b) {
    vertexPosition[0] = x;
    vertexPosition[1] = y;
    colorValue[0] = r;
    colorValue[1] = g;
    colorValue[2] = b;
}
