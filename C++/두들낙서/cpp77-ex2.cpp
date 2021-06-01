#include <iostream>
using namespace std;

//남자
class Base {
public:
	void Print() {
		cout << "From Base!!" << endl;
	}
};

//총각
class Derived : public Base {
public:
	void Print() {
		cout << "From Derived!!" << endl;
	}
};

class Derived2 : public Base {
public:

};

int main() {
	//정적 바인딩 : 컴파일 시간에 결정됨
	//cpp은 기본 바인딩은 정적 바인딩, 타입을 따라 간다.
	//java는 기본 바인딩이 동적 바인딩, final을 붙이면 정적 바인딩이 된다.
	Base *b = new Derived();
	b->Print();
	delete b;

	b = new Derived2();
	b->Print();
	delete b;

	return 0;
}