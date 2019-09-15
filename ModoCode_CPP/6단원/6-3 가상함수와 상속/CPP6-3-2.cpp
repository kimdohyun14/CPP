// 레퍼런스도 된다.

// 여태까지 기반 클래스에서 파생 클래스의 함수에 접근할 때
// 항상 기반 클래스의 포인터를 통해서 접근했지만,
// 사실 기반 클래스의 레퍼런스여도 문제 없이 작동한다.
#include <iostream>

class A {
public:
	virtual void show() {
		std::cout << "Parent !" << std::endl;
	}
};

class B : public A {
public:
	void show() override {
		std::cout << "Child !" << std::endl;
	}
};

// test 함수에서는 A 클래스의 레퍼런스를 받게 되어 있지만,
// 정상 작동한다.
// B 클래스가 A 클래스를 상속받고 있기 때문에
// 따라서 test 함수에서 show()를 호출하였을 때 인자로 b를 전달했다면,
// 비록 전달된 인자가 A의 객체라고 표현되어 있지만 show 함수가 virtual으로
// 정의되어 있기 때문에 알아서 B의 show 함수를 찾아내서 호출하게 된다.
void test(A& a) {
	a.show();
}

int main() {
	A a;
	B b;
	test(a);
	test(b);

	return 0;
}