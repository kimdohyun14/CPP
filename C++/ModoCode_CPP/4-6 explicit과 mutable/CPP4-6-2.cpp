// mutable 키워드
// const 함수 내부에서는 멤버 변수들의 값을 바꾸는 것이 불가능하다.
// 만약에 멤버 변수를 mutable 로 선언한다면, const함수에서도 값을 바꿀 수 있다.

#include <iostream>

class A {
	mutable int data_;

public:
	A(int data) : data_(data) { }
	void DoSomething(int x) const {
		data_ = x; //불가능!
	}

	void PrintData() const {
		std::cout << "data : " << data_ << std::endl;
	}
};

int main() {
	A a(10);
	a.DoSomething(3);
	a.PrintData();
	return 0;
}

// 멤버 함수를 const로 선언하는 의미는 
// 이 함수는 객체의 내부 상태에 영향을 주지 않습니다를 표현하는 방법
// 읽기 작업을 수행하는 함수들


// mutable을 쓰는 이유
// 읽기 작업을 수행하는 함수 중에서 const를 빼기에는 사용자의 입장에서
// 당연히 const로 정의되어야하는 함수이기 때문에,
// 읽기 작업을 수행하는 함수 안에서
// 캐시를 업데이트할 때 mutable로 선언해버리면 된다.