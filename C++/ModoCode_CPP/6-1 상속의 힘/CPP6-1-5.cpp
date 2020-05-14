#include <iostream>
#include <string>

// 3가지 접근 지시자

// private : 자신만의 비밀번호 (가족이나 그 외의 사람은 모른다)
// protected : 집 현관문 비밀번호 ( 가족들은 알지만 그 외의 사람들은 접근불가)
// public : 집 주소 (가족 뿐만이 아니라 다른 사람들도 알 수 있다)

class Base {
protected:
	std::string parent_string;

public:
	Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base {
	std::string child_string;

public:
	Derived() : child_string("파생"), Base() {
		std::cout << "파생 클래스" << std::endl;

		parent_string = "바꾸기";
	}

	void what() { std::cout << child_string << std::endl; }
	void change_print() { std::cout << parent_string << std::endl; }
};

int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	c.change_print();

	return 0;
}


// class Derived : public Base

// public 형태로 상속하였다면
// public, private, protected는 그대로 상속받게 된다.

// protected 형태로 상속하였다면
// public -> protectec 로, 나머지는 그대로 유지된다.

// private 형태로 상속하였다면
// 모든 접근 지시자들이 private로 되며, 접근할 수 없다.