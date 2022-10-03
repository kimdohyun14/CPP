#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	cout << "지연 시간을 초 단위로 입력 : ";
	float sec;
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC; // 지연 시간을 시스템 단위 클록 수로 변환한다.

	cout << "카운트 시작 \a\n";
	clock_t start = clock();
	while (clock() - start < delay); // 시간이 경과할 때까지 대기(busy waiting)
	cout << "종료\a\n";
	return 0;
}