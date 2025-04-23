#include <Application.h>
#include <sstream>
#include <fstream>

void Application::_loadJsonFile(const std::string& path, Json::Value& root){
    std::ifstream file;
    std::stringstream stringStream;

    try {
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(path.c_str());
        stringStream << file.rdbuf();
        file.close();
    }
    catch(std::ifstream::failure& e) {
        std::string errorText = e.what();
        throw std::runtime_error(errorText);
    }
    stringStream >> root;
}

void Application::_initWindow(Json::Value& root){
    Json::Value windowData = root["window"];
    _windowWidth = windowData["width"].asUInt();
    _windowHeight = windowData["height"].asUInt();
}

void Application::_initPlayer(Json::Value& root){
    Json::Value playerData = root["player_vertices"];
    std::array<sf::Vector2f, 3> vertices;
    for(int i = 0; i < 3; i++){
        vertices[i].x = playerData[i]["x"].asFloat();
        vertices[i].y = playerData[i]["y"].asFloat();
    }
    _player = std::make_shared<Player>(vertices, _windowWidth, _windowHeight);
}

void Application::_initGameObject(Json::Value& root){
    Json::Value gameObjectData = root["object_vertices"];
    std::array<sf::Vector2f, 3> vertices;
    for(int i = 0; i < 3; i++){
        vertices[i].x = gameObjectData[i]["x"].asFloat();
        vertices[i].y = gameObjectData[i]["y"].asFloat();
    }
    _gameObject = std::make_shared<GameObject>(vertices, _windowWidth, _windowHeight);
}

Application::Application(const std::string& configFile){
    Json::Value root;
    _loadJsonFile(configFile, root);

    _initWindow(root);
    _window.create(sf::VideoMode(_windowWidth, _windowHeight), "Collisions visualizer");

    _initPlayer(root);
    _initGameObject(root);
}

void Application::_updateMovement(float deltaTime){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        _player->move(moveLeft, deltaTime, _windowWidth, _windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        _player->move(moveRight, deltaTime, _windowWidth, _windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        _player->move(moveUp, deltaTime, _windowWidth, _windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        _player->move(moveDown, deltaTime, _windowWidth, _windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        _player->rotate(rotateRight, deltaTime, _windowWidth, _windowHeight);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        _player->rotate(rotateLeft, deltaTime, _windowWidth, _windowHeight);
    }
}

void Application::run(){
    while (_window.isOpen()) {
        float deltaTime = _clock.getElapsedTime().asSeconds();
        _clock.restart();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                _window.close();
            }
        }

        _updateMovement(deltaTime);

		GameObject* playerPtr = std::dynamic_pointer_cast<GameObject>(_player).get();
		GameObject* gameObjectPtr = _gameObject.get();
		GameObject::checkCollision(*playerPtr, *gameObjectPtr);
        _window.clear();

        _player->draw(_window);
        _gameObject->draw(_window);

        _window.display();
    }
}