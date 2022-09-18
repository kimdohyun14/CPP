#include <iostream>

// 번외로 union(공용체)
// 서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있는 데이터
// => 어느 한 시점에 어느 한 가지만 보관이 가능(그 전에 저장한 값을 소실됨)
// 여러 가지 데이터 형을 사용할 수 있지만 이들을 동시에 사용할 수 없을 때, 공용체를 사용하면 메모리 절약이 가능하다.

struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guests[2] =
	{
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99}
	};

	cout << guests[0].name << "와 " << guests[1].name << "의 부피를 합하면\n"
		 << guests[0].volume + guests[1].volume << " 세제곱피트\n";
	return 0;
}