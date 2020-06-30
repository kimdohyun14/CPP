#include <iostream>

// 다중 상속의 예시

class A
{
public:
	int a;

	A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B
{
public:
	int b;

	B() { std::cout << "B 생성자 호출" << std::endl; }
};

class C : public A, public B // 순서를 바꾸면, 생성자의 호출 순서도 바뀐다.
{
public:
	int c;

	C() : A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};

int main()
{
	C c;
	return 0;
}
