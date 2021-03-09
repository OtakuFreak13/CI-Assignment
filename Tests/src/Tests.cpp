#include <gtest/gtest.h>
#include "src/CI-Assignment.h"
#include "src/CI-Assignment.cpp"


class MathTests : public ::testing::Test
{
protected:
    MathTests()
    {

    }
    ~MathTests()
    {

    }
    AssignmentMath ass;
    void SetUp() override
    {
        ass = AssignmentMath();
    }
    void TearDown() override
    {
        //delete ass;
    }
};

TEST_F(MathTests, intAddition)
{
    // positive tests
    EXPECT_EQ(2, ass.addInt(1, 1));
    EXPECT_EQ(5, ass.addInt(1, 4));
    EXPECT_EQ(14, ass.addInt(10, 4));

    // negative tests
    EXPECT_NE(5, ass.addInt(5, 5));
    EXPECT_NE(599, ass.addInt(500,100));
}

TEST_F(MathTests, intDiv)
{
    // positive tests
    EXPECT_EQ(2, ass.divInt(4, 2));
    EXPECT_EQ(14, ass.divInt(42, 3));
    EXPECT_EQ(100, ass.divInt(500, 5));
    EXPECT_EQ(0, ass.divInt(500, 0));

    // negative tests
    EXPECT_NE(4, ass.divInt(4, 2));
    EXPECT_NE(2, ass.divInt(4, 2));
    EXPECT_NE(1, ass.divInt(5, 0));
    EXPECT_NE(5, ass.divInt(5, 0));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}