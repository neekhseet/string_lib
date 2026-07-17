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
