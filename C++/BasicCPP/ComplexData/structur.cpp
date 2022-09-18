#include <iostream>
using namespace std;

// 구조체 : 모든 정보를 하나의 단위로 묶을 수 있는 데이터 형식
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	// C 스타일에서는 struct를 요구하지만, C++ 스타일에서는 요구하지 않는다.
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99
	};

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "지금 판매하고 있는 모형풍선은\n" << guest.name << "와 "
		<< pal.name << "입니다.\n";
	cout << "두 제품을 $" << guest.price + pal.price << "에 드리겠습니다!\n";
	return 0;
}