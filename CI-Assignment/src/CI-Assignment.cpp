#include "CI-Assignment.h"
#include <climits>
#include <iostream>
#include <string>

AssignmentMath::AssignmentMath()
{
}

AssignmentMath::~AssignmentMath()
{
}

int AssignmentMath::addInt(int a, int b)
{
	if (b > 0 && a > INT_MAX - b)
	{
		throw std::overflow_error("Error: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	else if(b < 0 && a < INT_MIN - b)
	{
		throw std::underflow_error("Error: Underflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	return a + b;
}

int AssignmentMath::addInt(char a, int b)
{
	if (a >= 48 && a <= 57)
	{
		return addInt(int(a - 48), b);
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::addInt(int a, char b)
{
	if (b >= 48 && b <= 57)
	{
		return addInt(int(b - 48), a);
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::addInt(char a, char b)
{
	if (a >= 48 && a <= 57 && b >= 48 && b <= 57)
	{
		return addInt(int(a - 48), int(b - 48));
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::subInt(int a, int b)
{
	if (b > 0 && a < INT_MAX + b)
	{
		throw std::underflow_error("Error: Underflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	else if (b < 0 && a > INT_MIN + b)
	{
		throw std::overflow_error("Error: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	return a - b;
}

int AssignmentMath::subInt(char a, int b)
{
	if (a >= 48 && a <= 57)
	{
		return subInt(int(a - 48), b);
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::subInt(int a, char b)
{
	if (b >= 48 && b <= 57)
	{
		return subInt(int(b - 48), a);
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::subInt(char a, char b)
{
	if (a >= 48 && a <= 57 && b >= 48 && b <= 57)
	{
		return subInt(int(a - 48), int(b - 48));
	}
	else
	{
		throw std::range_error("Error: Wrong input! Please input 'int' or 'char' whole integer numbers but NOT 'char' letters!\n");
	}
}

int AssignmentMath::multInt(int a, int b)
{
	// If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
	if ((a == -1) && (b == INT_MIN) || (b == -1) && (a == INT_MIN)) /* `a * x` (or `a / x`) can overflow */
	{
		std::string str1 = "Error Mult1: Potential overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n";
		std::string str2 = "If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX \n";
		std::string strSum = str1 + str2;
		throw std::overflow_error(strSum);
	}
	// Overflow if a and b are of the same sign e.g. both negative or both positive
	else if ((a > 0 && b > 0 && a > (INT_MAX / b)) || (a < 0 && b < 0 && a > (INT_MAX / b)))
	{
		throw std::overflow_error("Error Mult2: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	// overflow if one of a or b is negative while the other positive
	else if ((a > 0 && b < 0 || a < 0 && b > 0)&& a > (INT_MAX / -b))
	{
		throw std::overflow_error("Error Mult3: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	// underflow if a and b are of the same sign e.g. both negative or both positive
	else if ((a > 0 && b > 0 && a < (INT_MIN / b)) || (a < 0 && b < 0 && a < (INT_MIN / b)))
	{
		throw std::underflow_error("Error Mult4: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	// undeflow if one of a or b is negative while the other positive
	else if ((a > 0 && b < 0 || a < 0 && b > 0) && a < (INT_MIN / -b))
	{
		throw std::underflow_error("Error Mult5: Overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n");
	}
	return a * b;
}

float AssignmentMath::divInt(int a, int b)
{
	// If one number is -1 and another is INT_MIN, dividing them we get abs(INT_MIN) which is 1 higher than INT_MAX
	if ((a == -1) && (b == INT_MIN) || (b == -1) && (a == INT_MIN)) /* `a * x` (or `a / x`) can overflow */
	{
		std::string str1 = "Error Div1: Potential overflow! Please avoid the use of values near 'INT_MAX' or 'INT_MIN'!\n";
		std::string str2 = "If one number is -1 and another is INT_MIN, dividing them we get abs(INT_MIN) which is 1 higher than INT_MAX \n";
		std::string strSum = str1 + str2;
		throw std::overflow_error(strSum);
	}
	if (b == 0)
	{
		throw std::range_error("Error: Divided by ZERO! Division by ZERO is undefined. Please do not put '0' as second integer of divInt()!");
	}
	return float(a) / float(b);
}
