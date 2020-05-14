#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;

	// 문제점 : 제수(나누는 수)가 0이면, 나누는 연산이 불가하다.
	// 이는 예외처리가 필요하다.
	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	return 0;
}