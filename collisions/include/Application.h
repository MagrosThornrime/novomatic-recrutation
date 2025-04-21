#pragma once
#include <json/json.h>
#include <Player.h>
#include <SFML/Window/Keyboard.hpp>

class Application{
    unsigned int _windowWidth, _windowHeight;
    std::shared_ptr<Player> _player;
    std::shared_ptr<GameObject> _gameObject;

    sf::RenderWindow _window;
    sf::Clock _clock;

    void _initWindow(Json::Value& root);
    void _initPlayer(Json::Value& root);
    void _initGameObject(Json::Value& root);
    void _updateMovement(float deltaTime);
    void _loadJsonFile(const std::string& path, Json::Value& root);

    public:
    explicit Application(const std::string& configFile);
    void run();
};