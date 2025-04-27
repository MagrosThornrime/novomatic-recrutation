#include <gtest/gtest.h>
#include <StringValue.hpp>
#include <StringConcatenate.hpp>
#include <Calculate.hpp>

#include <string>
#include <sstream>

TEST(Tests, BigString)
{
    std::string result = calculate<StringConcatenate, StringValue>(1000, StringValue("a"), StringConcatenate());
    std::string expected = "";
    for (int i = 0; i < 1000; i++)
    {
        expected += "a";
    }
    ASSERT_EQ(result, expected);
}

TEST(Tests, SmallString)
{
    std::string result = calculate<StringConcatenate, StringValue>(1, StringValue("a"), StringConcatenate());
    ASSERT_EQ(result, "a");
}