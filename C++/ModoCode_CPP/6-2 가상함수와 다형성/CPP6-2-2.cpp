// virtual Ű����
#include <iostream>

class Base {
public:
	Base() {
		std::cout << "��� Ŭ����" << std::endl;
	}

	// ���� �Լ�(virtual function)
	virtual void what() {
		std::cout << "��� Ŭ������ what()" << std::endl;
	}
};

class Derived : public Base {
public:
	Derived() : Base() {
		std::cout << "�Ļ� Ŭ����" << std::endl;
	}

	// �Ļ� Ŭ������ �Լ��� ��� Ŭ������ �Լ��� �������̵� �ϱ� ���ؼ���
	// �� �Լ��� ���� ��Ȯ�� ���ƾ� �Ѵ�.
	void what() {
		std::cout << "�Ļ� Ŭ������ what()" << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	// Base��ü�� ����Ű�� �����͵�
	// ���� p_p->what(), p_c->what()�� �ϸ� Base ��ü�� what()�� ����Ǿ��ϳ�
	Base* p_c = &c;
	Base* p_p = &p;

	// ������ what �Լ��� ȣ�����ش�.
	// ������ virtual Ű���� �����̴�.
	// ������ �ÿ� � �Լ��� ����� �� �������� �ʰ� ��Ÿ�� �ÿ�
	// �������� ���� �����Ѽ� ���� ���ε�(dynamic binding)�̶�� �θ���.
	std::cout << " === ���� ��ü�� Base ===" << std::endl;
	p_p->what();

	std::cout << "=== ���� ��ü�� Derived ===" << std::endl;
	p_c->what();

	return 0;
}