#include <gtest/gtest.h>
#include "src/CI-Assignment.h"
#include "src/CI-Assignment.cpp"

//          ----
//       Math Tests
//          ----
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
        
    }
};

TEST_F(MathTests, intAddition)
{
    // happy path tests
    EXPECT_EQ(2, ass.addInt(1, 1));
    EXPECT_EQ(5, ass.addInt(1, 4));
    EXPECT_EQ(6, ass.addInt(10, -4));
    EXPECT_EQ(9, ass.addInt('3', 6));

    // negative tests
    EXPECT_THROW(ass.addInt(5, INT_MAX), std::overflow_error);
    // in ascii s = 115, so 115 + 5 = 120. We dont want that as output.
    EXPECT_THROW(ass.addInt('p', 10), std::range_error);
}

TEST_F(MathTests, intSubtraction)
{
    // happy path tests
    EXPECT_EQ(0, ass.subInt(1, 1));
    EXPECT_EQ(-7, ass.subInt(1, 8));
    EXPECT_EQ(22, ass.subInt(14, -8));
    EXPECT_EQ(-1, ass.subInt('2', 3));


    // negative tests
    // not using std::overflow since it does not print out my error messages
    EXPECT_THROW(ass.subInt(INT_MIN, 3), std::underflow_error);
    // in ascii e = 101, so 101 + 2 = 103. We dont want that as output.
    EXPECT_NE(103, ass.subInt('e', 2));
    EXPECT_THROW(ass.subInt('b', 9), std::range_error);
}

TEST_F(MathTests, intMult)
{
    // happy path tests
    EXPECT_EQ(1, ass.multInt(1, 1));
    EXPECT_EQ(5, ass.multInt(1, 5));
    EXPECT_EQ(-16, ass.multInt(2, -8));

    // negative tests
    EXPECT_NE(10, ass.multInt(5, 5));
    EXPECT_NE(120000, ass.multInt(60, 200));
    EXPECT_NE(-30, ass.multInt(-3, -10));
}

TEST_F(MathTests, intDiv)
{
    // happy path tests
    EXPECT_FLOAT_EQ(2, ass.divInt(4, 2));
    EXPECT_FLOAT_EQ(3.5f, ass.divInt(7, 2));
    EXPECT_FLOAT_EQ(100, ass.divInt(500, 5));
    EXPECT_FLOAT_EQ(0, ass.divInt(0, 500));

    // negative tests
    EXPECT_NE(7, ass.divInt(7, 2));
    EXPECT_NE(2, ass.divInt(7, 2));
    EXPECT_NE(1, ass.divInt(5, 0));
    EXPECT_NE(5, ass.divInt(5, 0));
}

TEST_F(MathTests, integratedTests)
{
    // happy path tests
    EXPECT_EQ(24, ass.addInt(ass.subInt(5, 2), ass.multInt(3, 7)));
    EXPECT_EQ(-28, ass.multInt(ass.addInt(5, 2), ass.subInt(3, 7)));
    EXPECT_EQ(-750, ass.multInt(ass.divInt(45, 3), ass.multInt(5, -10)));
    EXPECT_EQ(10, 
        ass.divInt(
            ass.multInt(
                ass.divInt(45, 3), ass.multInt(5, -10)), 
            ass.addInt(
                ass.multInt(7, -10), -5)));

    // negative tests
    EXPECT_NE(0, ass.divInt(ass.multInt(5, 2), ass.addInt(-3, 3)));
}
//          ----
//      Math Tests end
//          ----






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


// Collection of google test commands for me to remember and later use
/*
    ASSERT_EXIT(statement, predicate, expected_message)
    EXPECT_EXIT(statement, predicate, expected_message)
    ex:
    EXPECT_EXIT(ass.addInt('s', 4), ::testing::ExitedWithCode(-1), "Error: Wrong input! Please input 'int' and not 'char' values.");
    
    ASSERT_DEATH(statement, expected_message)
    EXPECT_DEATH(statement, expected_message)
    ex:
    EXPECT_DEATH(ass.addInt('s', 4), "Error: Wrong input! Please input 'int' and not 'char' values.");


*/