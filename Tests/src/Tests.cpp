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
    // possitive tests
    EXPECT_EQ(2, ass.addInt(1, 1));
    EXPECT_EQ(5, ass.addInt(1, 4));
    EXPECT_EQ(14, ass.addInt(10, 4));

    // negative tests
    EXPECT_NE(10, ass.addInt(5, 5));
    EXPECT_NE(599, ass.addInt(500,100));
}
//
//TEST_F(AssigmentTests, floatMath)
//{
//    EXPECT_EQ(2, ass.divFloat(4, 2));
//}

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