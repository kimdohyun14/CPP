#include <iostream>

// ���� ����� ����

class A
{
public:
	int a;

	A() { std::cout << "A ������ ȣ��" << std::endl; }
};

class B
{
public:
	int b;

	B() { std::cout << "B ������ ȣ��" << std::endl; }
};

class C : public A, public B // ������ �ٲٸ�, �������� ȣ�� ������ �ٲ��.
{
public:
	int c;

	C() : A(), B() { std::cout << "C ������ ȣ��" << std::endl; }
};

int main()
{
	C c;
	return 0;
}
