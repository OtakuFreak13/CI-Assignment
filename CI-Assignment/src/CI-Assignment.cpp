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
	return a + b;
}

int AssignmentMath::addInt(char a, int b)
{
	return 0;
}

int AssignmentMath::addInt(int a, char b)
{
	return 0;
}

int AssignmentMath::addInt(char a, char b)
{
	return 0;
}

int AssignmentMath::subInt(int a, int b)
{
	return a - b;
}

int AssignmentMath::subInt(char a, int b)
{
	return 0;
}

int AssignmentMath::subInt(int a, char b)
{
	return 0;
}

int AssignmentMath::subInt(char a, char b)
{
	return 0;
}

int AssignmentMath::multInt(int a, int b)
{
	return a * b;
}

float AssignmentMath::divInt(int a, int b)
{
	return float(a) / float(b);
}
