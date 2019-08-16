// 전위/후위 증감 연산자

// 전위 증감 연산자는 다음과 같이 구분한다.
// operator++()
// operator--()

// 후위 증감 연산자는 다음과 같이 구분한다.
// operator++(int)
// operator--(int)
// 여기서 인자는 의미없는 인자이다.

// 전위 증감 연산의 경우 값이 바뀐 자기 자신을 리턴,
// 후위 증감 연산의 경우 값이 바뀌지 전에 객체를 리턴해야 된다는 점이다.

#include <iostream>

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) { }

	Test& operator++() {
		x++;
		std::cout << "전위 증감 연산자" << std::endl;
		return *this;
	}

	// 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int를
	// 받지만 실제로는 아무것도 전달되지 않는다.
	Test operator++(int) {
		Test temp(*this); // 이전의 값을 저장했다가 리턴한다.
		x++;
		std::cout << "후위 증감 연산자" << std::endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};

void func(const Test& t) {
	std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
	Test t(3);

	func(++t);
	func(t++);
	std::cout << "x : " << t.get_x() << std::endl;
	return 0;
}

// 연산자 오버로딩 정리

// 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩하자.
// 이 상황에서 클래스 내부 객체에 접근하고 싶으면 friend를 활용하자.

// 두 개의 객체 사이의 이항 연산자 이지만, 한 객체만 값이 바뀐다던지 등의 동등하지 않은
// 이항 연산자는 멤버 함수로 오버로딩하자.
// operator+=는 이항연산자이지만 operator+=(const Complex&)가 좋다.

// 단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋다.
// operator++의 경우 멤버 함수로 오버로딩

// 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야한다.