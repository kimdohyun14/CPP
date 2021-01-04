// structur.cpp -- 간단한 구조체
#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable quest = 
	{
		"Glorious Gloria",
		1.88,
		29.99
	}; // quest는 inflatable형의 구조체 변수이다.
	   // 지정된 값으로 초기화된다.

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "지금 판매하고 있는 모형풍선은\n" << quest.name;
	cout << "와 " << pal.name << "입니다.\n";
	cout << "두 제품을 $";
	cout << quest.price + pal.price << "에 드리겠습니다!\n";
	return 0;
}