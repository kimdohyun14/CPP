#include <iostream>

/*
부동 소수점 = 자리 이동한다.

"기본값 + 스케일"
소수점이 스케일에 따라 자리를 옮긴다.
3.45E6 => 3.45에 1,000,000을 곱하는 뜻
6은 지수(exponent)
3.45는 가수(mantissa)
8.33E-4 => 8.33에 1/10,000을 곱하는 뜻

유효 숫자는 어떤 수에서 의미 있는 숫자를 뜻한다.
*/

int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // 고정 소수점 형식으로 출력

	float tub = 10.0 / 3.0;   // 유효 숫자 6개, 3.0 역시 소수이다.
	double mint = 10.0 / 3.0; // 유효 숫자 15개
	const float million = 1.0e6;
	
	// 일반적으로 cout은 뒤에 붙은 0을 출력하지 않는다.
	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	return 0;
}