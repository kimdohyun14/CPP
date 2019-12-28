#include <iostream>
int Adder(int num1 = 1, int num2 = 2);

int main()
{
	std::cout << Adder() << std::endl;
	std::cout << Adder(4) << std::endl;
	std::cout << Adder(10, 10) << std::endl;
	return 0;
}

int Adder(int num1, int num2)
{
	return num1 + num2;
}