#include <iostream>
using namespace std;

// 배열의 원소 개수를 const 값으로 정의하는 것은 좋은 습관이다.
// 배열의 선언이나 for 루프와 같은 곳에서 배열 크기가 필요할 때 사용할 수 있다.
const int ArSize = 16;
int main()
{
	long long factorials[ArSize];
	factorials[1] = factorials[0] = 1LL; // 1!=1, 0!=1

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	// 계승은 매우 빠르게 증가한다.
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

	return 0;
}