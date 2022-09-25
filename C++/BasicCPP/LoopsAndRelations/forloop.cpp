#include <iostream>
using namespace std;

int main()
{
	cout << "카운트 다운 시작!: ";
	int limit;
	cin >> limit;
	int i;
	// for 루프의 각 부분
	// 1. 조건 검사에 사용할 카운터 값을 초기화 => 초기화(initialzation)
	// 2. 루프를 진행할 것인지 조건을 검사 => 조건 검사(test)
	// 3. 루프 몸체를 수행 => 루프 몸체는 조건 검사가 참일 때만 수행하게 된다.
	// 4. 카운터 값을 갱신 => 갱신(Update)
	for (i = limit; i; i--)
	{
		cout << "i = " << i << endl;
	}
	cout << "i = " << i << "이므로 루프를 종료\n";
	return 0;
}