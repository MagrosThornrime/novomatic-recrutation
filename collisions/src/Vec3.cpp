#include <Vec3.h>

vec3 vec3::cross(const vec3& other) const{
    return {
        (y * other.z - z * other.y),
        (z * other.x - x * other.z),
        (x * other.y - y * other.x)
    };
}

vec2 vec3::to2D() const{
    return {x, y};
}

vec3 vec3::to3D(const vec2& vector){
    return {vector.x, vector.y, 0.0f};
}