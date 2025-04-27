#pragma once
#include <string>
#include <vector>
#include <set>
#include <TrieNode.h>

class Trie {
    TrieNode _root = TrieNode('\0');

	TrieNode* _getBestNode(TrieNode* current, const std::string& word, int characters);
    TrieNode* _getNextNode(TrieNode* current, const std::string& word, int characters, std::set<TrieNode*>& visited);
    bool _wrongStart(const TrieNode* node, const std::string& givenWord);

public:
    void insertWord(const std::string& word);
    void longestMatches(const std::string& word, int maxMatches, std::vector<std::string>& matches);
    void clear();
};