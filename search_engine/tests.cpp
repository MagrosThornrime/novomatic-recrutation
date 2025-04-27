#include <gtest/gtest.h>
#include <algorithm>
#include <Trie.h>


TEST(Tests, ExampleFromExercise){
    Trie trie;

    const std::string word1 = "Kiedy jest nowy rok w Chinach?";
    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";
    trie.insertWord(word1);
    trie.insertWord(word2);

    std::vector<std::string> matches;
    const std::string prompt = "Kiedy jest nowy rok";
    trie.longestMatches(prompt, 2, matches);
    ASSERT_EQ(matches.size(), 2);
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word1) != matches.end());
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word2) != matches.end());
}

TEST(Tests, DifferentCases){
    Trie trie;

    const std::string word1 = "Kiedy jest nowy rok w chinach?";
    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";
    trie.insertWord(word1);
    trie.insertWord(word2);

    std::vector<std::string> matches;
    const std::string prompt = "Kiedy jest nowy rok w C";
    trie.longestMatches(prompt, 1, matches);
    ASSERT_EQ(matches.size(), 1);
    ASSERT_EQ(matches[0], word1);
}

