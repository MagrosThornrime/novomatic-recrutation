#include <gtest/gtest.h>
#include <algorithm>
#include <Trie.h>


TEST(Tests, BasicTest){
    const std::string word1 = "Kiedy jest nowy rok w Chinach?";
    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";

    const std::string prompt = "Kiedy jest nowy rok";

    Trie trie;
    trie.insertWord(word1);
    trie.insertWord(word2);
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 2, matches);

    ASSERT_EQ(matches.size(), 2);
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word1) != matches.end());
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word2) != matches.end());
}

TEST(Tests, LetterCases){
    const std::string word1 = "Chiny";
    const std::string prompt = "chiny";

    Trie trie;
    trie.insertWord(word1);
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 1, matches);

    ASSERT_EQ(matches.size(), 1);
    ASSERT_EQ(matches[0], word1);
}

TEST(Tests, WordShorterThanAll){
    const std::string word1 = "adaam";
    const std::string word2 = "adaaś";
    const std::string word3 = "ada";
    const std::string word4 = "apcr";

    const std::string prompt = "ad";

    Trie trie;
    trie.insertWord(word1);
    trie.insertWord(word2);
    trie.insertWord(word3);
    trie.insertWord(word4);
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 3, matches);

    ASSERT_EQ(matches.size(), 3);
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word1) != matches.end());
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word2) != matches.end());
    ASSERT_TRUE(std::find(matches.begin(), matches.end(), word3) != matches.end());
}

TEST(Tests, NoMatchFound){
    const std::string word1 = "Kiedy jest nowy rok w chinach?";

    const std::string prompt = "Bajo jajo";

    Trie trie;
    trie.insertWord(word1);
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 1, matches);

    ASSERT_EQ(matches.size(), 0);
}

TEST(Tests, ClearTrie){
    const std::string word1 = "Kiedy jest nowy rok w Chinach?";
    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";

    std::string prompt = "Kiedy jest nowy rok";

    Trie trie;
    trie.insertWord(word1);
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 2, matches);

    ASSERT_EQ(matches.size(), 1);
    ASSERT_EQ(matches[0], word1);

    trie.clear();
    matches.clear();
    trie.insertWord(word2);
    trie.longestMatches(prompt, 2, matches);

    ASSERT_EQ(matches.size(), 1);
    ASSERT_EQ(matches[0], word2);
}

TEST(Tests, EmptyTrie)
{
    std::string prompt = "Kiedy jest nowy rok";

    Trie trie;
    std::vector<std::string> matches;
    trie.longestMatches(prompt, 2, matches);

    ASSERT_EQ(matches.size(), 0);
}

TEST(Tests, WrongMaxMatchesNumber)
{
    const std::string word1 = "Kiedy jest nowy rok w Chinach?";
    const std::string word2 = "Kiedy jest nowy rok w Tajlandii?";

    const std::string prompt = "Kiedy jest nowy rok";

    Trie trie;
    trie.insertWord(word1);
    trie.insertWord(word2);
    std::vector<std::string> matches;
    std::string exceptionText;

    EXPECT_THROW({
        try
        {
            trie.longestMatches(prompt, -5, matches);
        }
        catch( const std::invalid_argument& e )
        {
            EXPECT_STREQ( "maxMatches must be greater than 0", e.what() );
            throw;
        }
    }, std::invalid_argument );
}