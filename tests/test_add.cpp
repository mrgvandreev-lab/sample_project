#include <gtest/gtest.h>
#include "add.hpp"
TEST(Add,Simple)
{
    EXPECT_EQ(add(3, 5), 8);
}

TEST(Add,Zero)
{
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(7, 0), 7);
}

TEST(Add,Negative)
{
    EXPECT_EQ(add(-3, -5), -8);
    EXPECT_EQ(add(-3, 5), 2);
}
