#pragma once
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode> children;
    char value{};
    bool isWordEnd{};

    TrieNode() = default;
    explicit TrieNode(char character) : value(character) {}
    bool contains(char character);
    TrieNode* getChild(char character);
    TrieNode* createChild(char character);
};