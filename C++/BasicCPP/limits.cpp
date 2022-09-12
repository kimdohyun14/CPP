#include <iostream>
#include <climits> // 최대값들을 정의해놓은 헤더파일 (전처리)

// #define 은 C의 유물
// C++ 에서는 기호 상수를 더 좋아함. ex) const 키워드 사용

int main()
{
	using namespace std; // main 안에서만 유효
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof 연산자는 데이터형이나 변수의 크기를 알아낼 수 있다.
	// 데이터형 이름에는 sizeof 연산자에 괄호를 붙여야 하지만,
	// 변수 이름에 사용할 때에는 괄호 없이 사용이 가능하다.
	cout << "sizeof(int) " << sizeof(int) << endl;
	cout << "sizeof(short) " << sizeof(short) << endl;
	cout << "sizeof(long) " << sizeof(long) << endl;
	cout << "sizeof(long long) " << sizeof(long long) << endl;
	cout << "sizeof(n_llong) " << sizeof n_llong << endl;
	cout << endl;

	cout << "int max : " << n_int << endl;
	cout << "short max : " << n_short << endl;
	cout << "long max : " << n_long << endl;
	cout << "long long max : " << n_llong << endl;
	cout << "바이트 당 비트 수 : " << CHAR_BIT << endl;
	return 0;
}