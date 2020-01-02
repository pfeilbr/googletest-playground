#include "gtest/gtest.h"
#include "mylib.h"

TEST(MyLib, add)
{
    EXPECT_EQ(MyLib::add(0, 0), 0);
    EXPECT_EQ(MyLib::add(1, 1), 2);
    EXPECT_EQ(MyLib::add(10, 10), 20);
    EXPECT_EQ(MyLib::add(50, 1), 51);
    EXPECT_EQ(MyLib::add(2, 3), 5);
}

TEST(MyLib, multiply)
{
    EXPECT_EQ(MyLib::multiply(0, 0), 0);
    EXPECT_EQ(MyLib::multiply(1, 1), 1);
    EXPECT_EQ(MyLib::multiply(10, 10), 100);
}
