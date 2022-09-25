#include <iostream>
using namespace std;

int main()
{
	cout << "정수를 하나 입력: ";
	int by;
	cin >> by;
	cout << "갱신 크기는 " << by << endl;
	// 굳이 1씩 증가할 필요가 없다.
	// 원하는 스탭만큼 건너뛸 수 있다.
	for (int i = 0; i < 100; i += by)
	{
		cout << i << endl;
	}
	return 0;
}