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

TEST(Tests, TooSmallN)
{
    try {
        calculate<StringConcatenate, StringValue>(-5, StringValue("a"), StringConcatenate());
    }
    catch( const std::invalid_argument& e )
    {
        EXPECT_STREQ( "n must be greater than zero", e.what() );
    }
    catch (...)
    {
        FAIL() << "Unexpected exception";
    }
}