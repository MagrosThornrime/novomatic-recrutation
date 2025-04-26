#pragma once
#include <string>

struct vec2 {
    float x, y;

    vec2 operator-() const;
    vec2 operator-(const vec2& other) const;
    bool operator==(const vec2& other) const;
    float dot(const vec2& other) const;
    float norm() const;
    vec2 normalize() const;
    std::string toString() const;
};