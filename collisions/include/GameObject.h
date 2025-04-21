#pragma once
#include <Triangle.h>
#include <SFML/Graphics.hpp>

class GameObject {
    triangle _triangle;
    sf::ConvexShape _shape;
    bool _hasCollision = false;

    static bool _isInsideBorders(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight);

protected:
    bool _setVertices(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight);
    void _getVertices(std::array<sf::Vector2f, 3>& triangleVertices) const;

public:
    GameObject(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight);
    void draw(sf::RenderWindow& window);
    static void checkCollision(GameObject& obj1, GameObject& obj2);
};