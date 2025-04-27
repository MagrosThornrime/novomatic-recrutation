#include <iostream>
#include <Trie.h>

int main()
{
    Trie trie;

    std::string prompt = "Kiedy jest nowy rok";
    const std::string word1 = "Kiedy jest nowy rok w Chinach?";
    trie.insertWord(word1);

    std::vector<std::string> matches;
    trie.longestMatches(prompt, 2, matches);

    trie.clear();
    matches.clear();

    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";
    trie.insertWord(word2);
    trie.longestMatches(prompt, 2, matches);
}