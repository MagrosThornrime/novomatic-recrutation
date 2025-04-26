#include <Vec2.h>
#include <cmath>

vec2 vec2::operator-() const{
    return {-x, -y};
}

vec2 vec2::operator-(const vec2& other) const{
    return {x - other.x, y - other.y};
}

bool vec2::operator==(const vec2& other) const{
    return x == other.x && y == other.y;
}

float vec2::dot(const vec2& other) const{
    return x * other.x + y * other.y;
}

float vec2::norm() const{
    return sqrt(dot(*this));
}

vec2 vec2::normalize() const{
    float module = norm();
    return {x / module, y / module};
}

std::string vec2::toString() const{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
