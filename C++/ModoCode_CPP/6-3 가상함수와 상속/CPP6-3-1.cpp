// 가상함수와 상속에 관련한 내용들

// virtual 소멸자(가상 소멸자)
// 가상 함수 테이블 (virtual function table)
// 다중 상속
// 가상 상속

// virtual 소멸자
// 클래스의 상속을 사용함으로써 중요하게 처리해야 되는 부분이
// 상속 시에, 소멸자를 가상함수로 만들어야 한다.
#include <iostream>

class Parent {
public:
	Parent() {
		std::cout << "Parent 생성자 호출" << std::endl;
	}
	virtual ~Parent() {
		std::cout << "Parent 소멸자 호출" << std::endl;
	}
};

class Child : public Parent {
public:
	Child() {
		std::cout << "Child 생성자 호출" << std::endl;
	}
	~Child() {
		std::cout << "Child 소멸자 호출" << std::endl;
	}
};

int main() {
	// 정상
	std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
	{ Child c; }
	
	// Child의 소멸자가 호출되지 않는다.
	// 소멸자가 호출되지 않는다면 여러가지 문제가 생길 수 있다.
	// 만약에 Child 객체에서 메모리를 동적으로 할당하고 소멸자에서 해제하는데,
	// 소멸자가 호출 안됬다면 메모리 누수(memory leak)가 생긴다.

	// 해결법 단순히 Parent의 소멸자를 virtual로 만들어버리면 된다.
	// 이는 Child 소멸자를 호출하면서 Child 소멸자가 알아서 Parent 소멸자를 호출하므로
	// Parent 소멸자를 먼저 호출하게 되면, Parent는 Child가 있는지 없는지 모르므로,
	// Child 소멸자를 호출해줄 수 없다. 그래서 문제가 생긴다.
	// 그래서 Base 클래스들은 반드시 소멸자를 virtual로 만들어주어야 나중에 문제가 발생하지 않는다.
	std::cout << "--- Parent 포인터로 Child 가리켰을 때" << std::endl;
	{
		Parent* p = new Child();
		delete p;
	}
}
