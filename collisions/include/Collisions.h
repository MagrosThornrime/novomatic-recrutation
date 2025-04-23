#pragma once
#include <Triangle.h>

struct vec3 {
    float x, y, z;
};

vec3 cross(const vec3& vector1, const vec3& vector2);
vec2 to3D(const vec3& vector);
vec3 to2D(const vec2& vector);

bool isColliding(const triangle& triangle1, const triangle& triangle2);
vec2 supportFunction(const triangle& triangle, vec2 direction);
vec2 minkowskiPoint(const triangle& triangle1, const triangle& triangle2, vec2 direction);
bool createLine(std::vector<vec2>& simplex, const triangle& triangle1, const triangle& triangle2);
bool createTriangle(std::vector<vec2>& simplex, const triangle& triangle1, const triangle& triangle2);
bool pointPassedOrigin(vec2 direction, vec2 supportVertex);
vec2 perpendicularVector(vec2 vector1, vec2 vector2, vec2 vector3);

bool containsOrigin(std::vector<vec2>& simplex);