#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

// 파생된 클래스 
class Derived : public Base {
	std::string s;

public:
	Derived() : Base(), s("파생") {
		std::cout << "파생 클래스" << std::endl;

		// Base 에서 what() 을 물려 받았기 때문에
		// Derived 에서 당연히 쓸 수 있다.
		what();
	}

	// 오버라이딩(overriding)
	void what() { std::cout << s << std::endl; }
};

// 오버로딩(overloading)은 같은 이름의 함수를 인자를 달리 하여 정의하는 것

int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return 0;
}