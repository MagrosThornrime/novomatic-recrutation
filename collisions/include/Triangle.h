#pragma once
#include <array>
#include <vector>
#include <string>

struct vec2 {
    float x, y;
};

vec2 operator-(const vec2& vector);
vec2 operator-(const vec2& vector1, const vec2& vector2);
bool operator==(const vec2& vector1, const vec2& vector2);
float dot(const vec2& vector1, const vec2& vector2);
vec2 normalize(const vec2& vector);
std::string toString(const vec2& vector);

struct triangle {
    std::array<vec2, 3> points;
};

std::string toString(const triangle& triangle);

