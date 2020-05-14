// virtual 키워드
#include <iostream>

class Base {
public:
	Base() {
		std::cout << "기반 클래스" << std::endl;
	}

	// 가상 함수(virtual function)
	virtual void what() {
		std::cout << "기반 클래스의 what()" << std::endl;
	}
};

class Derived : public Base {
public:
	Derived() : Base() {
		std::cout << "파생 클래스" << std::endl;
	}

	// 파생 클래스의 함수가 기반 클래스의 함수를 오버라이드 하기 위해서는
	// 두 함수의 꼴이 정확히 같아야 한다.
	void what() {
		std::cout << "파생 클래스의 what()" << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	// Base객체를 가리키는 포인터들
	// 따라서 p_p->what(), p_c->what()을 하면 Base 객체의 what()이 실행되야하나
	Base* p_c = &c;
	Base* p_p = &p;

	// 적절한 what 함수를 호출해준다.
	// 이유는 virtual 키워드 때문이다.
	// 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에
	// 정해지는 일을 가리켜서 동적 바인딩(dynamic binding)이라고 부른다.
	std::cout << " === 실제 객체는 Base ===" << std::endl;
	p_p->what();

	std::cout << "=== 실제 객체는 Derived ===" << std::endl;
	p_c->what();

	return 0;
}