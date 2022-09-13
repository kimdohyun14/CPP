#include <iostream>
using namespace std;

// 중요한 점은 피연산자 중 하나라도 부동 소수점수가 있다면 결과는 부동 소수점수이다.
// 부동 소수점형 상수는 기본적으로 double형이라는 사실을 기억하자.

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "정수 나눗셈: 9/5 = " << 9 / 5 << endl;
	cout << "부동 소수점수 나눗셈: 9.0/5.0 = " << 9.0 / 5.0 << endl;
	cout << "혼합 나눗셈: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double형 상수: 1e7/9.0 = " << 1e7 / 9.0 << endl;
	cout << "float형 상수: 1e7f/9.0f = " << 1e7f / 9.0f << endl << endl;

	cout << 9 / 5 << endl;      // int/int => int 나눗셈 수행
	cout << 9L / 5L << endl;    // long/long => long 나눗셈 수행
	cout << 9.0 / 5.0 << endl;  // double/double => double 나눗셈 수행
	cout << 9.0 / 5.0f << endl; // double/float => float 나눗셈 수행
	return 0;
}