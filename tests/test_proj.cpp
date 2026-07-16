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
    char str2[MAX_LEN];
    string_copy(str2, str);
    ASSERT_STREQ("Abrakadabra", str2);
};
