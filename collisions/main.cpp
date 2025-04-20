#include <SFML/Graphics.hpp>

int main() {
    // Create a window with 800x600 dimensions and a title
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test Window");

    // Create a red circle shape
    sf::CircleShape circle(100.f); // radius 100
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(300.f, 200.f); // center-ish

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window when requested
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen with black color
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
