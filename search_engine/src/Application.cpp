#include <Application.h>
#include <imgui-SFML.h>
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

void Application::_initEngine(Json::Value& root)
{
    Json::Value engineData = root["engine"];
    int maxMatches = engineData["max-matches"].asInt();
    int fontScale = engineData["font-scale"].asInt();
    float windowScale = engineData["window-scale"].asFloat();
    std::string searchText = engineData["search-text"].asString();
    std::string clearText = engineData["clear-text"].asString();
    _engine = std::make_shared<SearchEngine>(maxMatches, fontScale, windowScale, searchText, clearText);

}

Application::Application(const std::string& configFile){
    Json::Value root;
    _loadJsonFile(configFile, root);

    _initWindow(root);
    _initEngine(root);
    _window.create(sf::VideoMode(_windowWidth, _windowHeight), "szukajka.pl");

    _window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(_window))
    {
        throw std::runtime_error("Failed to initialize ImGui-SFML");
    }
}




void Application::run(){
    while(_window.isOpen()) {
        ImGui::SFML::Update(_window, _clock.restart());
        while(_window.pollEvent(_event)) {
            ImGui::SFML::ProcessEvent(_window, _event);
            if(_event.type == sf::Event::Closed) {
                _window.close();
            }
        }
        _engine->renderForm(_windowWidth, _windowHeight);
        _window.clear();
        ImGui::SFML::Render(_window);
        _window.display();
    }
}

Application::~Application()
{
    ImGui::SFML::Shutdown();
}
