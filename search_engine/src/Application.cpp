#include <Application.h>
#include <imgui.h>
#include <imgui-SFML.h>
#include <sstream>
#include <fstream>
#include <iostream>

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
    _fontScale = windowData["font-scale"].asInt();
}

void Application::_initTrie(Json::Value& root)
{
    Json::Value trieData = root["trie"];
    _maxMatches = trieData["matches"].asInt();
}

Application::Application(const std::string& configFile){
    Json::Value root;
    _loadJsonFile(configFile, root);

    _initWindow(root);
    _initTrie(root);
    _window.create(sf::VideoMode(_windowWidth, _windowHeight), "szukajka.pl");

    _window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(_window))
    {
        throw std::runtime_error("Failed to initialize ImGui-SFML");
    }

}

void Application::_renderSearchForm()
{
    static char prompt[64] = "";
    static bool searched = false;
    static bool cleared = false;

    ImGui::Begin("Searchie");
    ImGui::SetWindowFontScale(_fontScale);
    ImGui::SetWindowSize({static_cast<float>(_windowWidth) / 1.15f, static_cast<float>(_windowHeight) / 1.15f});
    while(_window.pollEvent(_event)) {
        ImGui::SFML::ProcessEvent(_window, _event);

        if(_event.type == sf::Event::Closed) {
            _window.close();
        }
    }

    if (ImGui::InputText("##", prompt, IM_ARRAYSIZE(prompt))) {
        searched = false;
        cleared = false;
        _matches.clear();
        _trie.longestMatches(std::string(prompt), _maxMatches, _matches);
    }
    for (auto& match : _matches)
    {
        ImGui::Text("%s", match.c_str());
    }

    if (ImGui::Button("Search")) {
        searched = true;
        _trie.insertWord(std::string(prompt));
    }
    if (ImGui::Button("Clean history"))
    {
        cleared = true;
        _trie.clear();
    }
    if (searched)
    {
        std::string text = "Currently the browser doesn't support real searching.\n";
        text += "But don't worry! Your prompt was added to the history!";
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", text.c_str());
    }
    if (cleared)
    {
        std::string text = "Your history was cleared.";
        ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", text.c_str());
    }
    ImGui::End();
}


void Application::run(){
    while(_window.isOpen()) {
        ImGui::SFML::Update(_window, _clock.restart());
        _renderSearchForm();
        _window.clear();
        ImGui::SFML::Render(_window);
        _window.display();
    }
}

Application::~Application()
{
    ImGui::SFML::Shutdown();
}
