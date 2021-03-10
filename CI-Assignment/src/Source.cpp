// Source.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";
}

class AssignmentSimUI {
public:
	AssignmentSimUI();
	~AssignmentSimUI();
	int addInt(int a, int b);
	int subInt(int a, int b);
	int multInt(int a, int b);
	float divInt(int a, int b);
	std::string boo;

	int interfaceInput(std::string mathFuc, int userInput);
	int interfaceInput(std::string mathFuc, char userInput);
	int interfaceInput(std::string mathFuc, std::string userInput);
private:

};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file