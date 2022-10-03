#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "1부터 10까지의 수 중에서 ";
	cout << "내가 좋아하는 수를 한번 맞추어 보세요. \n";
	do
	{
		cin >> n;
	} while (n != 7); // 먼저 몸체를 실행하고, 나중에 조건을 검사한다.
	cout << "맞았습니다.\n";
	return 0;
}