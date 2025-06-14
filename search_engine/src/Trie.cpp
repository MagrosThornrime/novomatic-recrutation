#include <stack>
#include <stdexcept>
#include <ranges>
#include <Trie.h>
#include <cctype>

TrieNode* Trie::_getBestNode(TrieNode* current, const std::string& word, int characters){
	if(characters >= word.size()){
		return nullptr;
	}
    char character = word[characters];
    if (current->contains(character))
    {
        return current->getChild(character);
    }
    char other = tolower(character) == character ? toupper(character) : tolower(character);
	if(current->contains(other)){
	    return current->getChild(other);
	}
	return nullptr;
}

TrieNode* Trie::_getNextNode(TrieNode* current, const std::string& word, int characters,
							std::set<TrieNode*>& visited){
	TrieNode* bestNode = _getBestNode(current, word, characters);
	if(bestNode != nullptr && !visited.contains(bestNode)){
		visited.insert(bestNode);
		return bestNode;
	}
    for(auto& node : std::views::values(current->children)){
        if(!visited.contains(&node)){
            visited.insert(&node);
            return &node;
        }
    }
    return nullptr;
}

void Trie::insertWord(const std::string& word){
    TrieNode* current = &_root;
    for (char character : word){
        if(!current->contains(character)){
            current = current->createChild(character);
        }
        else{
            current = current->getChild(character);
        }
    }
    current->isWordEnd = true;
}

bool Trie::_wrongStart(const TrieNode* node, const std::string& givenWord)
{
    if (node == nullptr)
    {
        return true;
    }
    return node->value != tolower(givenWord[0]) && node->value != toupper(givenWord[0]);
}


void Trie::longestMatches(const std::string& givenWord, int maxMatches, std::vector<std::string>& matches){

    if(maxMatches <= 0) {
        throw std::invalid_argument("maxMatches must be greater than 0");
    }

    std::set<TrieNode*> visitedNodes;
    std::stack<TrieNode*> dfsStack;
    dfsStack.push(&_root);

    std::string foundWord;
    while(!dfsStack.empty()){
        TrieNode* currentNode = dfsStack.top();
        TrieNode* nextNode = _getNextNode(currentNode, givenWord, foundWord.size(), visitedNodes);
        if (dfsStack.size() == 1 && _wrongStart(nextNode, givenWord))
        {
            return;
        }
        if(nextNode == nullptr){
            if (currentNode->isWordEnd)
            {
                matches.push_back(foundWord);
                if(matches.size() == maxMatches){
                    return;
                }
            }
            dfsStack.pop();
            foundWord.pop_back();
        }
        else{
            dfsStack.push(nextNode);
            foundWord.push_back(nextNode->value);
        }
    }
}

void Trie::clear(){
    _root.children.clear();
}