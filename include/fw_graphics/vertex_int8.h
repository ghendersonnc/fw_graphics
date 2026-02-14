#pragma once
#include <cstdint>
namespace Fw::Graphics
{
    struct Vertexi8
    {
        float colorValue[3];
        int8_t vertexPosition[2];

        Vertexi8(int8_t x, int8_t y, float r = 1.0f, float g = 1.0f, float b = 1.0f);
    };
}