#pragma once
#include <cstdint>
namespace Fw::Graphics
{
    struct Vertexf
    {
        float colorValue[3];
        float vertexPosition[2];

        Vertexf(float x, float y, float r = 1.0f, float g = 1.0f, float b = 1.0f);
    };
}