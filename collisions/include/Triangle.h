#pragma once
#include <array>

struct vec2 {
    float x, y;
};

struct triangle {
    std::array<vec2, 3> points;
};

bool isColliding(const triangle& triangle1, const triangle& triangle2);