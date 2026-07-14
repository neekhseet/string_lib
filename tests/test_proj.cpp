#include "../includes/string.h"
#include <gtest/gtest.h>

const char *str = "Abrakadabra";

TEST(ProjTest, Example) { EXPECT_EQ(10, 10); };

TEST(ProjTest, CalcStringLength)
{
    size_t res = string_len(&str);
    ASSERT_EQ(11, res);
}