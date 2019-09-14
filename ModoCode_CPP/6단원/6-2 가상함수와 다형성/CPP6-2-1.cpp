// ����(virtual) �Լ��� ������
// is-a �� has-a ����
// �������̵�(overriding)
// virtual Ű����� �����Լ�(virtual function)
// ������(polymorphism)

// ��� ��� ����� is-a �����̴�.
// Ŭ������ �Ļ��� �� �� �� �� Ư��ȭ(��üȭ specialize)�ȴٴ� ���̴�.
// �ݴ�� ��� Ŭ������ �Ž��� �ö󰡸� �Ϲ�ȭ(generalize)�ȴٰ� �Ѵ�.

// ��� Ŭ�������� ���踦 is-a ����θ� ǥ���� �� ����.
// � Ŭ������ ���̿����� has-a ���谡 �����Ѵ�.
// ���� ��� �ڵ����� ������ ������ �ִ�. (has-a) �����̴�.

// �ٽ� ���� �������̵� �� ĳ������ �����

#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("���") {
		std::cout << "��� Ŭ����" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("�Ļ�"), Base() {
		std::cout << "�Ļ� Ŭ����" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;
	Base* p_c = &c;
	// Derived is a Base�̹Ƿ�
	// �Ļ� Ŭ�������� ��� Ŭ������ ĳ���� �ϴ� ���� �� ĳ�����̶�� �Ѵ�.
	// ���⼭ p_c�� ������ Base ��ü�� ����Ű�� �������̹Ƿ�
	// p_c���� what�� �����ϸ� Base�� what�� �����Ѵ�.

	// �ݴ�� �ٿ� ĳ������ �ȵȴ�.
	// p_c�� Derived ��ü�� ����Ű�� �������̹Ƿ� ��ü�� Derived��� ����������
	// Base������ Derived�� what�� �Լ��� ���ǵǾ� ���� �ʱ� �����̴�.
	p_c->what();

	return 0;

}

// dynamic_cast
// ĳ���ÿ� ���� ������ �̿��� �����ϱ� ���ؼ�, C++������ ��� ���迡 �ִ�
// �� �����͵� ���� ĳ������ ���ִ� dynamic_cast��� ���� �����Ѵ�.
// ������� static_cast�� ���� �����ϴ�.

// Derived* p_c = dynamic_cast<Derived*>(p_p);

// �� ĳ������ �ſ� �����Ӱ� ����� �� �ִٴ� ��.