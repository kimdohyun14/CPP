//레퍼런스를 리턴하는 함수
#include <iostream>

class A {
	int x;

public:
	A(int c) : x(c) { }

	//x의 레퍼런스를 리턴하게 되는 함수
	int& access_x() { return x; }
	//x의 값을 리턴하는 함수
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	//클래스 A는 int와 int의 레퍼런스를 리턴하는 두 개의 함수를 가지고 있다.
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
	return 0;
}