#include <iostream>
using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		cout << "First()" << endl;
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First()
	{
		cout << "~First()" << endl;
		delete[] strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2)
		:First(str1)
	{
		cout << "Second()" << endl;
		strTwo = new char[strlen(str2) + 1];
	}
	virtual ~Second()
	{
		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

int main()
{
	First* ptr = new Second("simple", "complex");
	delete ptr;
	return 0;
}