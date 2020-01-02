#include "gtest/gtest.h"
#include "mylib.h"

static const char *get_cpp_version()
{

    if (__cplusplus == 201703L)
        return "C++17";
    else if (__cplusplus == 201402L)
        return "C++14";
    else if (__cplusplus == 201103L)
        return "C++11";
    else if (__cplusplus == 199711L)
        return "C++98";
    else
        return "pre-standard C++";
}

static void print_cpp_version()
{
    std::cout << "C++ Version: " << get_cpp_version() << "\n";
}

TEST(MyLib, adhoc)
{
    print_cpp_version();
}

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
    EXPECT_EQ(MyLib::multiply(0, 1), 0);
    EXPECT_EQ(MyLib::multiply(1, 0), 0);
    EXPECT_EQ(MyLib::multiply(0, 1), 0);
    EXPECT_EQ(MyLib::multiply(1, 1), 1);
    EXPECT_EQ(MyLib::multiply(10, 10), 100);
}
