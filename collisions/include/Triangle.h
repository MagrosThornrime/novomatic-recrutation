#pragma once
#include <array>
#include <vector>
#include <string>
#include <Vec2.h>

struct triangle {
    std::array<vec2, 3> points;
	vec2 circleCenter{};
	float circleRadius{};
	const float _EPSILON = 0.00001f;

	std::string toString() const;
	void setCircle();
};