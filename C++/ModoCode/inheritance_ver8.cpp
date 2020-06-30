#include <iostream>

class A
{
public:
	virtual void show() { std::cout << "Parent!" << std::endl; }
};

class B : public A
{
public:
	void show() override { std::cout << "Child!" << std::endl; }
};

// 기반 클래스의 포인터로 접근했다면, 사실 레퍼런스도 된다.
void test(A& a)
{
	a.show();
}

int main()
{
	A a;
	B b;
	test(a);
	test(b);

	return 0;
}