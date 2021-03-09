

#include <gtest/gtest.h>
#include "src/CI-Assignment.h"
int main(int argc, char** argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
class AssigmentTests : public ::testing::Test
{
public:
    AssignmentMain ass;
    void SetUp()
    {
        ass = AssignmentMain();
    }
};

TEST_F(AssigmentTests, intMath)
{
    EXPECT_EQ(2, ass.addInt(1, 1));
    EXPECT_EQ(6, ass.subInt(10, 4));
}

TEST_F(AssigmentTests, floatMath)
{
    EXPECT_EQ(2, ass.divFloat(4, 2));
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
