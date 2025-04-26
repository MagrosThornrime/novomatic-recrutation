#include <TrieNode.h>
#include <string>
#include <stdexcept>

bool TrieNode::contains(char character){
    return children.contains(character);
}

TrieNode* TrieNode::getChild(char character){
    if(!contains(character)){
        throw std::runtime_error("Trie node does not contain character '" + std::to_string(character) + "'");
    }
    return &children[character];
}

TrieNode* TrieNode::createChild(char character){
    if(contains(character)){
        throw std::runtime_error("Trie node already contains character '" + std::to_string(character) + "'");
    }
    children.try_emplace(character, character);
    return getChild(character);
}