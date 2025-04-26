#include <Collisions.h>
#include <limits>
#include <bits/stdc++.h>
#include <Vec3.h>


vec2 supportFunction(const triangle& triangle, vec2 direction) {

	float supportProduct = std::numeric_limits<float>::lowest();
	vec2 supportVertex;

	for (int i = 0; i < 3; i++) {
		const vec2 vertex = triangle.points[i];
		const float product = vertex.dot(direction);
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
	return supportVertex.dot(direction) > 0;
}

vec2 perpendicularVector(vec2 vector1, vec2 vector2, vec2 vector3){
	vec3 perpendicular = vec3::to3D(vector1).cross(vec3::to3D(vector2));
	perpendicular = perpendicular.cross(vec3::to3D(vector3));
	return perpendicular.to2D();
}

bool createLine(std::vector<vec2>& simplex, const triangle& triangle1, const triangle& triangle2){
	vec2 direction = -simplex.back();
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

	vec2 lineVector2 = simplex[0] - simplex[2];
	vec2 lineVector1 = simplex[1] - simplex[2];
	vec2 perpendicular1 = perpendicularVector(lineVector2, lineVector1, lineVector1);
	vec2 towardsOrigin = -simplex[2];

	if(perpendicular1.dot(towardsOrigin) > 0){
		simplex.erase(remove(simplex.begin(), simplex.end(), simplex[0]), simplex.end());
		return false;
	}
	vec2 perpendicular2 = perpendicularVector(lineVector1, lineVector2, lineVector2);
	if(perpendicular2.dot(towardsOrigin) > 0){
		simplex.erase(remove(simplex.begin(), simplex.end(), simplex[1]), simplex.end());
		return false;
	}

	return true;
}

bool isCirclesColliding(const triangle& triangle1, const triangle& triangle2){
	float distance = (triangle1.circleCenter - triangle2.circleCenter).norm();
	return distance < triangle1.circleRadius + triangle2.circleRadius;
}

bool isColliding(const triangle& triangle1, const triangle& triangle2) {

	if(!isCirclesColliding(triangle1, triangle2)){
		return false;
	}

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