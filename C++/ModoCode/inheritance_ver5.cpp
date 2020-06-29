#include <iostream>

// virtual 키워드의 힘

// 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 일을 동적 바인딩이라고 함.

class Base
{
public:
	Base() { std::cout << "기반 클래스" << std::endl; }

	// 가상 함수 (virtual 키워드가 붙은 함수를 말함)
	virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

	void what() { std::cout << "파생 클래스의 what()" << std::endl; }
};

int main()
{
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << "== 실제 객체는 Base == " << std::endl;
	p_p->what();

	std::cout << "== 실제 객체는 Derived == " << std::endl;
	p_c->what(); // Base의 what 함수인지, Derived의 what 함수인지는 런타임시에 결정된다. (동적 바인딩)
	return 0;
}