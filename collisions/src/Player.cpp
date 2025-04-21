#include <Player.h>
#include <cmath>
#include <numbers>

sf::Vector2f Player::_getPositionDifference(MoveDirection direction, float deltaTime){
    sf::Vector2f difference;
    switch(direction){
        case moveUp:
            difference = sf::Vector2f(0, -1);
            break;
        case moveDown:
            difference = sf::Vector2f(0, 1);
            break;
        case moveLeft:
            difference = sf::Vector2f(-1, 0);
            break;
        case moveRight:
            difference = sf::Vector2f(1, 0);
            break;
    }
    return difference * deltaTime * _moveVelocity;
}

float Player::_getRotationAngle(RotateDirection direction, float deltaTime){
    float rotationAngle = _rotationVelocity * deltaTime;
    return direction == rotateLeft ? rotationAngle : -rotationAngle;
}

void Player::move(MoveDirection direction, float deltaTime, float screenWidth, float screenHeight) {
    std::array<sf::Vector2f, 3> newVertices;
    _getVertices(newVertices);
    sf::Vector2f positionDifference = _getPositionDifference(direction, deltaTime);
    for(auto& point : newVertices){
        point += positionDifference;
    }
    _setVertices(newVertices, screenWidth, screenHeight);
	_calculateCenter(newVertices);
}

void Player::rotate(RotateDirection direction, float deltaTime, float screenWidth, float screenHeight) {
    std::array<sf::Vector2f, 3> newVertices;
    _getVertices(newVertices);
    float rotationAngle = _getRotationAngle(direction, deltaTime);
    float radians = rotationAngle * std::numbers::pi / 180.f;
    float cosine = std::cos(radians), sine = std::sin(radians);
    for(auto& point : newVertices){
		point -= _rotationCenter;
        point = sf::Vector2f(
            point.x * cosine - point.y * sine,
            point.x * sine + point.y * cosine
        );
		point += _rotationCenter;
    }
    _setVertices(newVertices, screenWidth, screenHeight);
}

void Player::_calculateCenter(const std::array<sf::Vector2f, 3>& triangleVertices) {
	std::array<std::array<float, 3>, 3> coefficients;
	std::array<float, 3> constants;

	// Prepare equation system
	for(int i=0; i<3; i++){
		sf::Vector2f vertex = triangleVertices[i];
		coefficients[i][0] = 2 * vertex.x;
		coefficients[i][1] = 2 * vertex.y;
		coefficients[i][2] = -1.0f;
		constants[i] = vertex.x * vertex.x + vertex.y * vertex.y;
	}

	// transform left matrix to an upper triangular matrix
	for(int i=0; i<3; i++){
        // divide all values of the first row by the first non-zero element
        if(std::abs(coefficients[i][i]) < _EPSILON){
            continue;
        }
        constants[i] /= coefficients[i][i];
        for(int j=2; j>=i; j--){
            coefficients[i][j] /= coefficients[i][i];
        }


        // subtract all next rows by a multiplication of the first row
        // till all their first non-zero elements are zeros
        for(int j=i+1; j<3; j++){
            constants[j] -= coefficients[j][i] * constants[i];
            for(int k=2; k>=i; k--){
                coefficients[j][k] -= coefficients[j][i] * coefficients[i][k];
            }
        }
	}

	// transform the left matrix to a diagonal matrix
    for(int i=2; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            constants[j] -= coefficients[j][i] * constants[i];
            coefficients[j][i] = 0.0f;
        }
    }

	_rotationCenter = sf::Vector2f(constants[0], constants[1]);
}

Player::Player(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight)
    : GameObject(triangleVertices, screenWidth, screenHeight) {
    _calculateCenter(triangleVertices);
};