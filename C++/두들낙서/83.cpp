// 상속에서의 형변환 - 다운캐스팅
// static_cast
// 논리적으로 변환 가능한 타입을 변환한다.
// 컴파일 타임에 형변환에 대한 타입 오류를 잡아준다.
// double -> int / int -> double
// 다운캐스팅 / 업캐스팅
// 컴파일 시간에 완료됨 (정적)

#include <iostream>
using namespace std;

class Base {
public:
	int a = 1;
};

class Drv1 : public Base {
public:
	float b = 3.14;

	void f() {
		cout << "Drv1::f()" << endl;
		cout << b << endl;
	}
};

class Drv2 : public Base {
public:
	int c = 3;

	void f() {
		cout << "Drv2::f()" << endl;
		cout << c << endl;
	}
};

int main() {
	Base* b = new Drv1;
	int* a = new int(5);
	// 말이 안되는 형변환은 막아준다.
	//Drv1* d1 = static_cast<Drv1*>(a);
	Drv1* d1 = static_cast<Drv1*>(b);
	d1->f();

	// 문제점 : 컴파일러에서는 오류가 안보인다.
	// 실제적으로 b는 Drv1을 가리키고 있는데,
	// 여기서는 b를 Drv2로 다운캐스팅하고 있음.
	// 즉 d2가 b가 가리키는 곳을 가리키고 있음
	// Drv2 != Drv1
	Drv2* d2 = static_cast<Drv2*>(b);
	d2->f();

	delete b;
}