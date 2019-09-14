// 가상(virtual) 함수와 다형성
// is-a 와 has-a 관계
// 오버라이딩(overriding)
// virtual 키워드와 가상함수(virtual function)
// 다형성(polymorphism)

// 모든 상속 관계는 is-a 관계이다.
// 클래스가 파생될 수 록 좀 더 특수화(구체화 specialize)된다는 점이다.
// 반대로 기반 클래스로 거슬러 올라가면 일반화(generalize)된다고 한다.

// 모든 클래스들의 관계를 is-a 관계로만 표현할 수 없다.
// 어떤 클래스들 사이에서는 has-a 관계가 성립한다.
// 예를 들어 자동차는 엔진을 가지고 있다. (has-a) 관계이다.

// 다시 보는 오버라이딩 및 캐스팅의 관계는

#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() {
		std::cout << "파생 클래스" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

int main() {
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_c = &c;
	// Derived is a Base이므로
	// 파생 클래스에서 기반 클래스로 캐스팅 하는 것을 업 캐스팅이라고 한다.
	// 여기서 p_c는 엄연한 Base 객체를 가리키는 포인터이므로
	// p_c에서 what를 실행하면 Base의 what을 실행한다.

	// 반대로 다운 캐스팅은 안된다.
	// p_c는 Derived 객체를 가리키는 포인터이므로 객체가 Derived라고 생각하지만
	// Base에서는 Derived의 what의 함수가 정의되어 있지 않기 때문이다.
	p_c->what();

	return 0;

}

// dynamic_cast
// 캐스팅에 따른 오류를 미연에 방지하기 위해서, C++에서는 상속 관계에 있는
// 두 포인터들 간에 캐스팅을 해주는 dynamic_cast라는 것을 지원한다.
// 사용방법은 static_cast와 거의 동일하다.

// Derived* p_c = dynamic_cast<Derived*>(p_p);

// 업 캐스팅은 매우 자유롭게 수행될 수 있다는 점.