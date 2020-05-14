#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

// �Ļ��� Ŭ���� 
class Derived : public Base {
	std::string s;

public:
	Derived() : Base(), s("�Ļ�") {
		std::cout << "�Ļ� Ŭ����" << std::endl;

		// Base ���� what() �� ���� �޾ұ� ������
		// Derived ���� �翬�� �� �� �ִ�.
		what();
	}

	// �������̵�(overriding)
	void what() { std::cout << s << std::endl; }
};

// �����ε�(overloading)�� ���� �̸��� �Լ��� ���ڸ� �޸� �Ͽ� �����ϴ� ��

int main() {
	std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
	Base p;

	std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
	Derived c;

	return 0;
}