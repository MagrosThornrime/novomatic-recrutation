#include <GameObject.h>

GameObject::GameObject(const std::array<sf::Vector2f, 3>& triangleVertices){
    _shape.setPointCount(3);
    setVertices(triangleVertices);
}

void GameObject::setVertices(const std::array<sf::Vector2f, 3>& triangleVertices){
    for(int i = 0; i < 3; i++){
        vec2& point = _triangle.points[i];
        point.x = triangleVertices[i].x;
        point.y = triangleVertices[i].y;
        _shape.setPoint(i, triangleVertices[i]);
    }
}

void GameObject::draw(sf::RenderWindow& window){
    sf::Color color = _hasCollision ? sf::Color::Green : sf::Color::Blue;
    _shape.setFillColor(color);
    window.draw(_shape);
}

void GameObject::checkCollision(GameObject& obj1, GameObject& obj2){
    if(isColliding(obj1._triangle, obj2._triangle)){
        obj1.setHasCollision(true);
        obj2.setHasCollision(true);
        return;
    }
    obj1.setHasCollision(false);
    obj2.setHasCollision(false);
}

void GameObject::setHasCollision(bool value){
    _hasCollision = value;
}