#pragma once
#include <GameObject.h>

enum MoveDirection{
    moveUp, moveDown, moveLeft, moveRight
};

enum RotateDirection{
    rotateLeft, rotateRight
};

class Player : public GameObject {
    float _moveVelocity = 200.0f, _rotateVelocity = 30.0f;
    sf::Vector2f _getPositionDifference(MoveDirection direction, float deltaTime);
    float _getRotationAngle(RotateDirection direction, float deltaTime);
public:
    Player(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight)
        : GameObject(triangleVertices, screenWidth, screenHeight) {};
    void rotate(RotateDirection direction, float deltaTime, float screenWidth, float screenHeight);
    void move(MoveDirection direction, float deltaTime, float screenWidth, float screenHeight);
};