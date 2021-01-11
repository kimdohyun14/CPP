// strctptr.cpp -- 구조체 매개변수를 지시하는 포인터를 사용하는 함수
#include <iostream>
#include <cmath>

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

void rect_to_polar(const rect* pxy, polar* pda);
void show_polar(const polar* pda);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하십시오: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace); // 주소를 전달한다
		show_polar(&pplace);             // 주소를 전달한다
		cout << "x값과 y값을 입력하십시오(끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

void show_polar(const polar* pda)
{
	using namespace std;
	const double Rad_to_deq = 57.29577951;

	cout << "거리 = " << pda->distance;
	cout << ", 각도 = " << pda->angle * Rad_to_deq;
	cout << "도\n";
}

void rect_to_polar(const rect* pxy, polar* pda)
{
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}