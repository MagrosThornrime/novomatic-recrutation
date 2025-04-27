#pragma once
#include <SFML/Graphics.hpp>
#include <json/json.h>

#include <Trie.h>

class Application
{
    unsigned int _windowWidth, _windowHeight;

    sf::RenderWindow _window;
    sf::Clock _clock;
    sf::Event _event;
    Trie _trie;
    int _maxMatches;
    std::vector<std::string> _matches;

    void _renderSearchForm();
    void _loadJsonFile(const std::string& path, Json::Value& root);
    void _initWindow(Json::Value& root);
    void _initTrie(Json::Value& root);

public:
    explicit Application(const std::string& configFile);
    void run();
};
