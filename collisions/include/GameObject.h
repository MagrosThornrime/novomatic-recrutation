#pragma once
#include <Triangle.h>
#include <SFML/Graphics.hpp>

class GameObject {
    triangle _triangle;
    sf::ConvexShape _shape;
    bool _hasCollision = false;

public:
    GameObject(const std::array<sf::Vector2f, 3>& triangleVertices);
    void setVertices(const std::array<sf::Vector2f, 3>& triangleVertices);
    void draw(sf::RenderWindow& window);
    static void checkCollision(GameObject& obj1, GameObject& obj2);
    void setHasCollision(bool value);
};