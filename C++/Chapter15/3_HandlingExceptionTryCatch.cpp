#include <iostream>
using namespace std;

// C++에서는 예외처리 메커니즘을 제공한다.

int main()
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try
	{
		// 예외발생 예상지역

		if (num2 == 0) // 예외 처리가 발생한다면
			throw num2;

		cout << "나눗셈의 몫 : " << num1 / num2 << endl;
		cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	}
	catch (int expn)  // 처리할 예외의 종류 명시
	{
		// 예외 처리

		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	cout << "end of main" << endl;
	return 0;
}