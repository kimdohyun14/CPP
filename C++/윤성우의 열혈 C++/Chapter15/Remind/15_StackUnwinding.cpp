#include <iostream>
using namespace std;

void SimpleFuncOne();
void SimpleFuncTwo();
void SimpleFuncThree();

int main()
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << ": " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne()
{
	cout << "SimpleFuncOne()" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo()
{
	cout << "SimpleFuncTwo()" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree()
{
	cout << "SimpleFuncTree()" << endl;
	throw - 1;
}
