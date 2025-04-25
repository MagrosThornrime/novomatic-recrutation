#pragma once
#include <array>
#include <vector>
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

struct triangle {
    std::array<vec2, 3> points;
	vec2 circleCenter{};
	float circleRadius{};
	const float _EPSILON = 0.00001f;

	std::string toString() const;
	void setCircle();
};