#include <Player.h>
#include <SFML/Window/Keyboard.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;

void updateMovement(Player &player, float deltaTime, float windowWidth, float windowHeight) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player.move(moveLeft, deltaTime, windowWidth, windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player.move(moveRight, deltaTime, windowWidth, windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player.move(moveUp, deltaTime, windowWidth, windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player.move(moveDown, deltaTime, windowWidth, windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        player.rotate(rotateLeft, deltaTime, windowWidth, windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        player.rotate(rotateRight, deltaTime, windowWidth, windowHeight);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Collision visualizer");

    std::array<sf::Vector2f, 3> vertices = {sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 500.0f), sf::Vector2f(600.0f, 100.0f)};

    Player player(vertices, WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::Clock clock;

    while (window.isOpen()) {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        updateMovement(player, deltaTime, WINDOW_WIDTH, WINDOW_HEIGHT);
        window.clear();

        player.draw(window);

        window.display();
    }

    return 0;
}
