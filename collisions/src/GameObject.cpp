#include <GameObject.h>
#include <Collisions.h>
#include <iostream>
#include <cmath>

GameObject::GameObject(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight){
    _shape.setPointCount(3);
    if(!_setVertices(triangleVertices, screenWidth, screenHeight)){
        throw std::invalid_argument("GameObject vertices are outside the borders");
    }
}

bool GameObject::_setVertices(const std::array<sf::Vector2f, 3>& triangleVertices, float screenWidth, float screenHeight){
    if(!_isInsideBorders(triangleVertices, screenWidth, screenHeight)){
        return false;
    }
    for(int i = 0; i < 3; i++){
        vec2& point = _triangle.points[i];
        point.x = triangleVertices[i].x;
        point.y = triangleVertices[i].y;
        _shape.setPoint(i, triangleVertices[i]);
    }
	_triangle.setCircle();
    return true;
}

void GameObject::draw(sf::RenderWindow& window){
    sf::Color color = _hasCollision ? sf::Color::Green : sf::Color::Blue;
    _shape.setFillColor(color);
    window.draw(_shape);
}

void GameObject::checkCollision(GameObject& obj1, GameObject& obj2){
    if(isColliding(obj1._triangle, obj2._triangle)){
        obj1._hasCollision = true;
        obj2._hasCollision = true;
        return;
    }
    obj1._hasCollision = false;
    obj2._hasCollision = false;
}


void GameObject::_getVertices(std::array<sf::Vector2f, 3>& triangleVertices) const{
    for(int i = 0; i < 3; i++){
        const vec2& point = _triangle.points[i];
        triangleVertices[i].x = point.x;
        triangleVertices[i].y = point.y;
    }
}

bool GameObject::_isInsideBorders(const std::array<sf::Vector2f, 3>& triangleVertices,
                                float screenWidth, float screenHeight){
    for(int i = 0; i < 3; i++){
        float x = triangleVertices[i].x;
        float y = triangleVertices[i].y;
        if(x < 0 || x > screenWidth || y < 0 || y > screenHeight){
            return false;
        }
    }
    return true;
}