#include "fw_graphics/vertex_f.h"

Fw::Graphics::Vertexf::Vertexf(const float x, const float y, const float r, const float g, const float b) {
    vertexPosition[0] = x;
    vertexPosition[1] = y;
    colorValue[0] = r;
    colorValue[1] = g;
    colorValue[2] = b;
}
