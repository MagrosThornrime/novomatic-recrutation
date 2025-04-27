#include <SearchEngine.h>
#include <imgui.h>
#include <iostream>

void SearchEngine::_renderInputText()
{
    if (ImGui::InputText("##", _prompt, IM_ARRAYSIZE(_prompt))) {
        _searched = false;
        _cleared = false;
        _matches.clear();
        _trie.longestMatches(std::string(_prompt), _maxMatches, _matches);
    }
}

void SearchEngine::_renderMatches()
{
    for (auto& match : _matches)
    {
        ImGui::Text("%s", match.c_str());
    }
}

void SearchEngine::_renderSearchButton()
{
    if (ImGui::Button("Search")) {
        _searched = true;
        _trie.insertWord(std::string(_prompt));
        _prompt[0] = '\0';
    }
}

void SearchEngine::_renderClearButton()
{
    if (ImGui::Button("Clear history"))
    {
        _cleared = true;
        _trie.clear();
        _matches.clear();
    }
}

void SearchEngine::_renderSearchedText()
{
    if (_searched)
    {
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", _searchText.c_str());
    }
}

void SearchEngine::_renderClearedText()
{
    if (_cleared)
    {
        ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", _clearText.c_str());
    }
}


void SearchEngine::renderForm(unsigned int windowWidth, unsigned int windowHeight)
{
    ImGui::Begin("Searchie");
    ImGui::SetWindowFontScale(_fontScale);
    ImVec2 size = {static_cast<float>(windowWidth) / _windowScale, static_cast<float>(windowHeight) / _windowScale};
    ImGui::SetWindowSize(size);

    _renderInputText();
    _renderMatches();
    _renderSearchButton();
    _renderClearButton();
    _renderClearedText();

    ImGui::End();
}