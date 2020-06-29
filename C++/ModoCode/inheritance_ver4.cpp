#include <iostream>
#include <string>

// �� ĳ���ð� �ٿ� ĳ������ ����

class Base
{
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

class Derived : public Base
{
	std::string s;

public:
	Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

int main()
{
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;
	Base* p_c = &c;
	/*
	p_c �� Base ��ü�� ����Ű�� �������̴�.
	p_c �� what�� �����Ѵٸ� p_c �� �翬�� Base �� what�� �����ϰ� �ȴ�.
	*/
	p_c->what();

	//Derived* p_p = &p;
	/*
	�ٿ� ĳ������ �ȵǴ� ����
	Derived �� what �Լ��� �����Ϸ��� ������, �̴� ���ǵǾ� ���� �ʱ� ������ �Ұ����ϴ�.
	�ٿ� ĳ������ �������� �ʴ� �κ��̴�.
	*/
	
	return 0;
}