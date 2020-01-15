#include <iostream>
using namespace std;

void ShowString(char* str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
	cout << n1 + n2 << endl;
}

// const_cast : const의 성향을 삭제
// 포인터와 참조자의 const 성향을 제거하는 형 변환이다.

// 함수의 인자전달 시 const 선언으로 인한 형의 불일치가 발생해서 인자의 전달이 불가능한 경우에 사용

int main()
{
	const char* name = "Kim Do Hyun";
	ShowString(const_cast<char*>(name)); // const char* -> char* 로 형 변환하여 함수의 인자전달을 한다.

	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2)); // const int& -> int&로 형 변환
	return 0;
}