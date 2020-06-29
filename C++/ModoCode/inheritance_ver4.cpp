#include <iostream>
#include <string>

// 업 캐스팅과 다운 캐스팅의 예시

class Base
{
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

class Derived : public Base
{
	std::string s;

public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

int main()
{
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_c = &c;
	/*
	p_c 는 Base 객체를 가리키는 포인터이다.
	p_c 의 what을 실행한다면 p_c 는 당연히 Base 의 what을 실행하게 된다.
	*/
	p_c->what();

	//Derived* p_p = &p;
	/*
	다운 캐스팅이 안되는 이유
	Derived 의 what 함수를 실행하려고 하지만, 이는 정의되어 있지 않기 때문에 불가능하다.
	다운 캐스팅은 권장하지 않는 부분이다.
	*/
	
	return 0;
}