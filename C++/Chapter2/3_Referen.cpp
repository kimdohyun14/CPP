#include <iostream>
using namespace std;

int main()
{
	int n1 = 1020;
	int& n2 = n1;

	n2 = 3047;
	cout << "VAL: " << n1 << endl;
	cout << "REF: " << n2 << endl;

	cout << "VAL: " << &n1 << endl;
	cout << "REF: " << &n2 << endl;
	return 0;
}