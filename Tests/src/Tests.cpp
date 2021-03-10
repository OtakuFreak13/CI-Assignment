#include <gtest/gtest.h>
#include "src/CI-Assignment.h"
#include "src/CI-Assignment.cpp"
// link to test tutorial: https://google.github.io/googletest/advanced.html

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
        // no teardown necessary
    }
};

TEST_F(MathTests, intAddition)
{
    // happy path tests
    EXPECT_EQ(2, ass.addInt(1, 1));
    EXPECT_EQ(5, ass.addInt(1, 4));
    EXPECT_EQ(6, ass.addInt(10, -4));
    // let singel digit chars be acceptable input for addInt()
    EXPECT_EQ(9, ass.addInt('3', 6));

    // negative tests
    // handle overflow
    EXPECT_THROW(ass.addInt(5, INT_MAX), std::overflow_error);
    // handle char input thet is not a number for addInt
    EXPECT_THROW(ass.addInt('p', 10), std::range_error);
}

TEST_F(MathTests, intSubtraction)
{
    // happy path tests
    EXPECT_EQ(0, ass.subInt(1, 1));
    EXPECT_EQ(-7, ass.subInt(1, 8));
    EXPECT_EQ(22, ass.subInt(14, -8));
    // let singel digit chars be acceptable input for subInt()
    EXPECT_EQ(-1, ass.subInt('2', 3));


    // negative tests
    // handle underflow
    EXPECT_THROW(ass.subInt(INT_MIN, 3), std::underflow_error);
    // handle char input thet is not a number for subInt()
    EXPECT_THROW(ass.subInt('b', 9), std::range_error);
}

TEST_F(MathTests, intMult)
{
    // happy path tests
    EXPECT_EQ(1, ass.multInt(1, 1));
    EXPECT_EQ(5, ass.multInt(1, 5));
    // check that negative * positive = negative
    EXPECT_EQ(-16, ass.multInt(2, -8));

    // negative tests
    // check that negative * negative =/= negative
    EXPECT_NE(-30, ass.multInt(-3, -10));
    // handle overflow
    EXPECT_THROW(ass.multInt(9999, 10000000), std::range_error);
}

TEST_F(MathTests, intDiv)
{
    // happy path tests
    EXPECT_FLOAT_EQ(2, ass.divInt(4, 2));
    EXPECT_FLOAT_EQ(3.5f, ass.divInt(7, 2));
    EXPECT_FLOAT_EQ(100, ass.divInt(500, 5));
    // check that positive / negative = negative
    EXPECT_NE(7, ass.divInt(21, -3));
    // check Zero divided by non zero number
    EXPECT_FLOAT_EQ(0, ass.divInt(0, 500));

    // negative tests
    // check that negative / negative =/= negative
    EXPECT_NE(-7, ass.divInt(-14, -2));
    // handle deivision by Zero
    EXPECT_THROW(ass.divInt(5, 0), std::range_error);
}

TEST_F(MathTests, integratedTests)
{
    // happy path tests
    EXPECT_EQ(24, ass.addInt(ass.subInt(5, 2), ass.multInt(3, 7)));
    // check that negative * positive = negative with integrated tests
    EXPECT_EQ(-28, ass.multInt(ass.addInt(5, 2), ass.subInt(3, 7)));
    // check that negative * positive = negative with integrated tests
    EXPECT_EQ(-750, ass.multInt(ass.divInt(45, 3), ass.multInt(5, -10)));
    // math simplifies down to -750 / -75 = 10
    // so checks that negative * negative = positive with integrated tests
    EXPECT_EQ(10, 
        ass.divInt(
            ass.multInt(
                ass.divInt(45, 3), ass.multInt(5, -10)), 
            ass.addInt(
                ass.multInt(7, -10), -5)));

    // negative tests
    // check div by Zero with integrated tests
    EXPECT_THROW(ass.divInt(ass.multInt(5, 2), ass.addInt(-3, 3)), std::range_error);
}
//          ----
//      Math Tests end
//          ----


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// link to test tutorial: https://google.github.io/googletest/advanced.html
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