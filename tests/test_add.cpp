#include <gtest/gtest.h>
#include "add.hpp"
TEST(Add,Simple)
{
    EXPECT_EQ(add(3, 5), 8);
}