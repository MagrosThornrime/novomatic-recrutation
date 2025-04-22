#pragma once
#include <array>

struct vec2 {
    float x, y;
};

vec2 operator-(const vec2& vector);
vec2 operator-(const vec2& vector1, const vec2& vector2);
float dot(const vec2& vector1, const vec2& vector2);
vec2 normalize(const vec2& vector);

struct triangle {
    std::array<vec2, 3> points;
};

bool isColliding(const triangle& triangle1, const triangle& triangle2);
vec2 supportFunction(const triangle& triangle, vec2 direction);
vec2 minkowskiPoint(const triangle& triangle1, const triangle& triangle2, vec2 direction);
bool createFirstSimplex(const triangle& triangle1, const triangle& triangle2, triangle& simplex);
bool pointPassedOrigin(vec2 direction, vec2 supportVertex);
vec2 directionPerpendicular(vec2 point1, vec2 point2);