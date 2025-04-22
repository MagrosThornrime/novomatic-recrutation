#include <Triangle.h>
#include <limits>
#include <cmath>

vec2 operator-(const vec2& vector){
	return {-vector.x, -vector.y};
}

vec2 operator-(const vec2& first, const vec2& second){
	return {first.x - second.x, first.y - second.y};
}

float dot(const vec2& vector1, const vec2& vector2){
	return vertex.x * direction.x + vertex.y * direction.y;
}

vec2 normalize(const vec2& vector){
	float module = sqrt(dot(vector, vector));
	return {vector.x / module, vector.y / module};
}

vec2 supportFunction(const triangle& triangle, vec2 direction) {

	float supportProduct = std::limits<float>::min();
	vec2 supportVertex;

	for (int i = 0; i < 3; i++) {
		const vec2& vertex = triangle.vertices[i];
		product = dot(vertex, direction);
		if (product > supportProduct) {
			supportProduct = product;
			supportVertex = vertex;
		}
	}
	return supportVertex;
}

vec2 minkowskiPoint(const triangle& triangle1, const triangle& triangle2, vec2 direction) {
	vec2 minkowski1 = supportFunction(triangle1, direction);
	vec2 minkowski2 = supportFunction(triangle2, -direction);
	return minkowski1 - minkowski2;
}

bool pointPassedOrigin(vec2 direction, vec2 supportVertex){
	return dot(supportVertex, direction) > 0;
}

vec2 directionPerpendicular(vec2 point1, vec2 point2){
	vec2 edge = point2 - point1;
	vec2 candidate1 = normalize({edge.y, -edge.x});
	vec2 candidate2 = normalize({-edge.y, edge.x});
	float product1 = dot(-point1, candidate1);
	float product2 = dot(-point1, candidate2);
	return product1 > product2 ? candidate1 : candidate2;
}

bool createFirstSimplex(const triangle& triangle1, const triangle& triangle2, triangle& simplex){
	vec2 direction = {1, 0};
	currentTriangle.points[0] = minkowskiPoint(triangle1, triangle2, direction);
	direction = normalize(-currentTriangle.points[0]);
	currentTriangle.points[1] = minkowskiPoint(triangle2, triangle1, direction);
	if(!pointPassedOrigin(direction, currentTriangle.points[1])){
		return false;
	}
	direction = directionPerpendicular(currentTriangle.points[0], currentTriangle.points[1]);
	currentTriangle.points[3] = minkowskiPoint(triangle1, triangle2, direction);
	return true;
}

bool isColliding(const triangle& triangle1, const triangle& triangle2) {
	triangle currentTriangle;
	if(!createFirstSimplex(triangle1, triangle2, currentTriangle)){
		return false;
	}

	while(!containsOrigin(currentTriangle)){
		direction =
	}

    return false;
}