// 다중 상속(multiple inheritance)
// C++에서의 상속의 또 다른 특징인 다중 상속
// C++에서는 한 클래스가 다른 여러 개의 클래스들을 상속 받는 것을 허용한다.
// 이를 다중 상속이라고 한다.

// 다중 상속에서 한 가지 재미있는 점은 생성자들의 호출 순서이다.
#include <iostream>

class A {
public:
	int a;

	A() {
		std::cout << "A 생성자 호출" << std::endl;
	}
};

class B {
public:
	int b;

	B() {
		std::cout << "B 생성자 호출" << std::endl;
	}
};

// 생성자들의 호출 순서는
// 오직 상속하는 순서에만 좌우된다.
// class C : public B, public A  // B -> A -> C 
class C : public A, public B { // A -> B -> C
public:
	int c;

	C() : A(), B() {
		std::cout << "C 생성자 호출" << std::endl;
	}
};

int main() {
	C c;
	return 0;
}