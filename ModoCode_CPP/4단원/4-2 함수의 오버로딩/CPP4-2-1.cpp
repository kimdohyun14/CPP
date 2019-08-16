//함수의 오버로딩, 생성자에 대해서 알아보자.

/* 함수 오버로딩 */
//함수의 이름이 같더라도 인자가 다르면 다른 함수
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}

//c++ 컴파일러에서는 함수를 오버로딩하는 과정은 다음과 같다.
//1. 자신과 타입이 정확히 일치하는 함수를 찾는다.
//2. 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해 찾는다.

/*
	char, unsigned char, short는 int로 변환된다.
	unsigned short는 int의 크기에 따라 int 혹은 unsigned int로 변환된다.
	float는 double로 변환된다.
	Enum은 int로 변환된다.

*/

//3. 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 찾는다.

/*
	float - > int  임의의 숫자타입은 다른 숫자 타입으로 변환된다.
	enum -> double enum도 임의의 숫자 타입으로 변환된다.
	0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환된다.
	포인터는 void 포인터로 변환된다.
*/

//4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다.

//위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 두 개 이상이 일치하면
//모호하다(ambiguous) 오류 발생
