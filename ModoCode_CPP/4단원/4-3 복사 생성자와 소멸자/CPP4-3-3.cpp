//소멸자 호출 확인하기
#include <cstring>
#include <iostream>

class Test {
	char c;

public:
	Test(char _c) {
		c = _c;
		std::cout << "생성자 호출" << c << std::endl;
	}
	~Test() {
		std::cout << "소멸자 호출" << c << std::endl;
	}
};

//지역 객체이기 때문에 simple_function이 종료됨과 동시에
//b 역시 소멸되게 된다. -> b의 소멸자가 호출됨
void simple_function() {
	Test b('b');
}

int main() {
	Test a('a');
	simple_function();
	return 0;
}

//main함수의 지역 객체였던 a가 소멸되면서 a의 소멸자가 호출된다.
//결과 a - b - b - a
//스레드 사이에서 lock 된 것을 푸는 역할도 수행한다.
//소멸자도 디폴트 소멸자가 있다.
//소멸자가 필요 없는 클래스라면 굳이 소멸자를 따로 써줄 필요가 없다.