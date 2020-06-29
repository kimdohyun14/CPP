#include <iostream>
#include <string>

class Base
{
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void incorrect() { std::cout << "기반 클래스" << std::endl; }
};

class Derived : public Base
{
	std::string s;

public:
	Derived() : Base(), s("파생") {}

	// 파생 클래스에서 기반 클래스의 가상 함수를 오버라이드 하는 경우, override 키워드를 통해서 명시적으로 가능
	void incorrect() override { std::cout << "파생 클래스" << std::endl; }
};

int main()
{
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << "== 실제 객체는 Base == " << std::endl;
	p_p->incorrect();

	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->incorrect();
	return 0;
}