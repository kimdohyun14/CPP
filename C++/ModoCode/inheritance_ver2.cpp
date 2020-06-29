#include <iostream>
#include <string>

class Base
{
	std::string s;

public:
	Base() : s("���")
	{
		std::cout << "��� Ŭ����" << std::endl;
	}

	void what()
	{
		std::cout << s << std::endl;
	}
};

class Derived : public Base
{
	std::string s;

public:
	Derived() :Base(), s("�Ļ�")
	{
		std::cout << "�Ļ� Ŭ����" << std::endl;

		what();
	}

	void what() // ��ӹ��� ���� �������̵�(������)
	{
		std::cout << s << std::endl;
	}
};

int main()
{
	std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
	Base p;

	std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
	Derived c;

	return 0;
}

