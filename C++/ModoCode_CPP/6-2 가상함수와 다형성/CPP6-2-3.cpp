//override 키워드
#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}

	virtual void incorrect() {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() {
		std::cout << "파생 클래스" << std::endl;
	}

	void incorrect() override {
		std::cout << s << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << "== 실제 객체는 Base ==" << std::endl;
	p_p->incorrect();

	std::cout << "== 실제 객체는 Derived ==" << std::endl;
	p_c->incorrect();
	return 0;
}