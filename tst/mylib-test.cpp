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

// ---

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

// ---

// test fixture example

class FooTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    FooTest()
    {
        // You can do set-up work for each test here.
    }

    ~FooTest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
        std::cout << "SetUp" << std::endl;
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
        std::cout << "TearDown" << std::endl;
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
};

TEST_F(FooTest, MethodBarDoesAbc)
{
    EXPECT_EQ(0, 0);
    EXPECT_EQ(1, 1);
}

TEST_F(FooTest, MethodBarDoesXyz)
{
    EXPECT_EQ(0, 0);
    EXPECT_EQ(1, 1);
}