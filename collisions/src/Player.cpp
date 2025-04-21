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
    float rotationAngle = _rotateVelocity * deltaTime;
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
}

void Player::rotate(RotateDirection direction, float deltaTime, float screenWidth, float screenHeight) {
    std::array<sf::Vector2f, 3> newVertices;
    _getVertices(newVertices);
    float rotationAngle = _getRotationAngle(direction, deltaTime);
    float radians = rotationAngle * std::numbers::pi / 180.f;
    float cosine = std::cos(radians), sine = std::sin(radians);
    for(auto& point : newVertices){
        point = sf::Vector2f(
            point.x * cosine - point.y * sine,
            point.x * sine + point.y * cosine
        );
    }
    _setVertices(newVertices, screenWidth, screenHeight);
}