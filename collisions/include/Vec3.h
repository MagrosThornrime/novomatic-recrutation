#pragma once
#include <Vec2.h>

struct vec3 {
    float x, y, z;

    vec3 cross(const vec3& other) const;
    static vec3 to3D(const vec2& vector);
    vec2 to2D() const;
};
