#include <Triangle.h>
#include <sstream>
#include <cmath>

vec2 operator-(const vec2& vector){
	return {-vector.x, -vector.y};
}

vec2 operator-(const vec2& first, const vec2& second){
	return {first.x - second.x, first.y - second.y};
}

bool operator==(const vec2& first, const vec2& second){
	return first.x == second.x && first.y == second.y;
}

float dot(const vec2& vector1, const vec2& vector2){
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

vec2 normalize(const vec2& vector){
	float module = sqrt(dot(vector, vector));
	return {vector.x / module, vector.y / module};
}


std::string toString(const vec2& vector){
	return "(" + std::to_string(vector.x) + ", " + std::to_string(vector.y) + ")";
}

std::string toString(const triangle& triangle){
	std::stringstream ss;
	for(int i = 0; i < 3; i++){
		ss << toString(triangle.points[i]) << " ";
	}
	return ss.str();
}