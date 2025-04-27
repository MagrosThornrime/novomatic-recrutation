#pragma once
#include <SFML/Graphics.hpp>
#include <json/json.h>
#include <SearchEngine.h>

class Application
{
    unsigned int _windowWidth, _windowHeight;
    int _fontScale;

    sf::RenderWindow _window;
    sf::Clock _clock;
    sf::Event _event;
    std::shared_ptr<SearchEngine> _engine;

    void _loadJsonFile(const std::string& path, Json::Value& root);
    void _initWindow(Json::Value& root);
    void _initEngine(Json::Value& root);

public:
    explicit Application(const std::string& configFile);
    void run();
    ~Application();
};
