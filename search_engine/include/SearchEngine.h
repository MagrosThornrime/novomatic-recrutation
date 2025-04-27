#pragma once
#include <Trie.h>
#include <SFML/Graphics.hpp>

class SearchEngine
{
    Trie _trie;
    int _maxMatches, _fontScale;
    float _windowScale;
    std::string _searchText, _clearText;
    std::vector<std::string> _matches;

    char _prompt[64] = "";
    bool _searched = false;
    bool _cleared = false;

    void _renderInputText();
    void _renderMatches();
    void _renderSearchButton();
    void _renderClearButton();
    void _renderSearchedText();
    void _renderClearedText();

    public:
    SearchEngine(int maxMatches, int fontScale, float windowScale,
        const std::string& searchText, const std::string& clearText) :
        _maxMatches(maxMatches), _fontScale(fontScale), _windowScale(windowScale),
        _searchText(searchText), _clearText(clearText) {}

    void renderForm(unsigned int windowWidth, unsigned int windowHeight);

};