#include <iostream>
using namespace std;
int main()
{
	int auks, bats, coots;

	// 두 값을 double형으로 더한 후, 그 합을 int형으로 변환하여 대입
	auks = 19.99 + 11.99;

	bats = (int)19.99 + (int)11.99;  // 구식 C 스타일
	coots = int(19.99) + int(11.99); // 신식 C++ 스타일
	cout << "바다오리 = " << auks << ", 박쥐 = " << bats;
	cout << ", 검둥오리 = " << coots << endl;

	char ch = 'Z';
	cout << "코드 " << ch << " 의 값은 ";
	cout << int(ch) << endl;
	cout << "코드 Z의 값은 ";
	cout << static_cast<int>(ch) << endl; // C++에서는 제한적인 4개의 데이터형 변환 연산자를 사용한다.

	// C++11 auto(초기화하는 값을 보고 변수형을 추론할 수 있다.)
	// 복잡한 변수명을 다룰 때 매우 유용하다. (너무 긴 변수타입)
	auto n = 100; // int
	auto x = 1.5; // double
	auto y = 1.3e12L; // long double
	return 0;
}