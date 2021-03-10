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
	return a * b;
}

float AssignmentMath::divInt(int a, int b)
{
	return float(a) / float(b);
}
