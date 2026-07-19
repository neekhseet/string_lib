#include "../includes/string.h"
#include <gtest/gtest.h>


const char *str = "Abrakadabra";

TEST(ProjTest, Example) { EXPECT_EQ(10, 10); };

TEST(ProjTest, CalcStringLength)
{
    size_t res = string_len(str);
    ASSERT_EQ(11, res);
};

TEST(ProjTest, NullStringLength)
{
    size_t res = string_len(NULL);
    ASSERT_EQ(0, res);
};

TEST(ProjTest, StopWhenGreateThanMaxLen)
{
    size_t res = string_len(
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean mas"
    );
    ASSERT_EQ(100, res);
};


TEST(ProjTest, CopyString)
{
    char *str2 = NULL;
    string_copy(&str2, str);
    ASSERT_STREQ("Abrakadabra", str2);
    free(str2);
};

TEST(ProjTest, DynamicChangeMemorySizeOfString)
{
    char *str2 = NULL;
    string_copy(&str2, str);
    ASSERT_STREQ("Abrakadabra", str2);
    free(str2);
}

TEST(ProjTest, CompareStringsWhereSecondGreater)
{
    char *str2 = NULL;
    string_copy(&str2, "Abradabra");
    int res = string_comp(str2, str);

    ASSERT_LT(res, 0);
    free(str2);
}

TEST(ProjTest, CompareStringsWhereSecondLess)
{
    char *str2 = NULL;
    string_copy(&str2, "Zbrakadabra");
    int res = string_comp(str2, str);

    ASSERT_GT(res, 0);
    free(str2);
}

TEST(ProjTest, CompareStringsWhereSame)
{
    char *str2 = NULL;
    string_copy(&str2, "Abrakadabra");
    int res = string_comp(str2, str);

    ASSERT_EQ(res, 0);
    free(str2);
}

TEST(ProjTest, FindCharFromString)
{
    char ch = string_find_char(str, 'a');
    ASSERT_EQ(ch, 'a');
}

TEST(ProjTest, GetFindCharFromStringIndex)
{
    int indx = string_find_char_index(str, 'a');
    ASSERT_EQ(indx, 3);
}

TEST(ProjTest, FindAndGetSubstring)
{
    char *substring = string_substr(str, "kad");
    ASSERT_STREQ(substring, "kad");
}

TEST(ProjTest, TryToExtractEmptySubstring)
{
    char *substring = string_substr(str, "");
    ASSERT_EQ(substring, nullptr);
}

TEST(ProjTest, ConcatTwoStrings)
{
    char *str1 = nullptr;
    char *str2 = nullptr;

    string_copy(&str1, "Hello, ");
    string_copy(&str2, "world!");

    char *res = string_concat(str1, str2);
    
    EXPECT_STREQ(res, "Hello, world!");

    free(str1);
    free(str2);
    free(res); 
}