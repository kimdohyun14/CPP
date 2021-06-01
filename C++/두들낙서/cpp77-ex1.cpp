// override : 우선하다.
#include <iostream>
using namespace std;

class Base {
public :
	int a = 10;
};

class Derived : public Base {
public :
	int a = 20;
};

int main() {
	Base b;
	Derived d;

	cout << b.a << endl;
	cout << d.a << endl;
	cout << d.Base::a << endl;
	cout << d.Derived::a << endl;
	return 0;
}
