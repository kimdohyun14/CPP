// ���� ���(multiple inheritance)
// C++������ ����� �� �ٸ� Ư¡�� ���� ���
// C++������ �� Ŭ������ �ٸ� ���� ���� Ŭ�������� ��� �޴� ���� ����Ѵ�.
// �̸� ���� ����̶�� �Ѵ�.

// ���� ��ӿ��� �� ���� ����ִ� ���� �����ڵ��� ȣ�� �����̴�.
#include <iostream>

class A {
public:
	int a;

	A() {
		std::cout << "A ������ ȣ��" << std::endl;
	}
};

class B {
public:
	int b;

	B() {
		std::cout << "B ������ ȣ��" << std::endl;
	}
};

// �����ڵ��� ȣ�� ������
// ���� ����ϴ� �������� �¿�ȴ�.
// class C : public B, public A  // B -> A -> C 
class C : public A, public B { // A -> B -> C
public:
	int c;

	C() : A(), B() {
		std::cout << "C ������ ȣ��" << std::endl;
	}
};

int main() {
	C c;
	return 0;
}