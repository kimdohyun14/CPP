// 다중 상속 시 주의할 점
#include <iostream>

class A {
public:
	int a;
};

class B {
public:
	int a;
};

class C : public B, public A {
public:
	int c;
};

int main() {
	C c;
	//c.a = 3;
	return 0;
}

// 중복되는 멤버 변수에 접근하면
// B의 a인지, A의 a인지 구분할 수 없다는 오류를 발생한다.

// 마찬가지로, 클래스 A와 B에 같은 이름의 함수가 있다면 오류가 발생
// 이유는 똑같이 어떤 함수를 호출해야 될 지 구분할 수 없으므로