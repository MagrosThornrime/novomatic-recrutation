#include <Collisions.h>
#include <limits>
#include <bits/stdc++.h>

vec3 cross(const vec3& first, const vec3& second){
	return {
		(first.y * second.z - first.z * second.y),
		(first.z * second.x - first.x * second.z),
		(first.x * second.y - first.y * second.x)
	};
}

vec2 to2D(const vec3& vector){
	return {vector.x, vector.y};
}

vec3 to3D(const vec2& vector){
	return {vector.x, vector.y, 0.0f};
}

vec2 supportFunction(const triangle& triangle, vec2 direction) {

	float supportProduct = std::numeric_limits<float>::lowest();
	vec2 supportVertex;

	for (int i = 0; i < 3; i++) {
		const vec2 vertex = triangle.points[i];
		const float product = dot(vertex, direction);
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

vec2 perpendicularVector(vec2 vector1, vec2 vector2, vec2 vector3){
	vec3 perpendicular = cross(to3D(vector1), to3D(vector2));
	perpendicular = cross(perpendicular, to3D(vector3));
	return normalize(to2D(perpendicular));
}

bool createLine(std::vector<vec2>& simplex, const triangle& triangle1, const triangle& triangle2){
	vec2 direction = normalize(-simplex.back());
	simplex.push_back(minkowskiPoint(triangle1, triangle2, direction));
	return pointPassedOrigin(direction, simplex.back());
}

bool createTriangle(std::vector<vec2>& simplex, const triangle& triangle1, const triangle& triangle2){
	const vec2 lineVector = simplex[1] - simplex[0];
	const vec2 towardsOrigin = -simplex[0];
	const vec2 direction = perpendicularVector(lineVector, towardsOrigin, lineVector);
	simplex.push_back(minkowskiPoint(triangle1, triangle2, direction));
	return pointPassedOrigin(direction, simplex.back());
}

bool containsOrigin(std::vector<vec2>& simplex){

	vec2 lineVector2 = normalize(simplex[0] - simplex[2]);
	vec2 lineVector1 = normalize(simplex[1] - simplex[2]);
	vec2 perpendicular1 = perpendicularVector(lineVector2, lineVector1, lineVector1);
	vec2 towardsOrigin = normalize(-simplex[2]);

	if(dot(perpendicular1, towardsOrigin) > 0){
		simplex.erase(remove(simplex.begin(), simplex.end(), simplex[0]), simplex.end());
		return false;
	}
	vec2 perpendicular2 = perpendicularVector(lineVector1, lineVector2, lineVector2);
	if(dot(perpendicular2, towardsOrigin) > 0){
		simplex.erase(remove(simplex.begin(), simplex.end(), simplex[1]), simplex.end());
		return false;
	}

	return true;
}

bool isColliding(const triangle& triangle1, const triangle& triangle2) {
	std::vector<vec2> simplex;
	vec2 direction = {1, 0};
	simplex.push_back(minkowskiPoint(triangle1, triangle2, direction));

	if(!createLine(simplex, triangle1, triangle2)){
		return false;
	}
	if(!createTriangle(simplex, triangle1, triangle2)){
		return false;
	}
	while(!containsOrigin(simplex)){
		if (!createTriangle(simplex, triangle1, triangle2)){
			return false;
		}
	}
	return true;
}