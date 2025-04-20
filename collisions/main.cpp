#include <GameObject.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collision visualizer");

    std::array<sf::Vector2f, 3> vertices = {sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 500.0f), sf::Vector2f(600.0f, 100.0f)};

    GameObject gameObject(vertices);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        gameObject.draw(window);

        window.display();
    }

    return 0;
}
