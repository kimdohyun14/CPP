#include <iostream>
using namespace std;

struct antar
{
	int year;
};

int main()
{
	antar s01, s02, s03;
	s01.year = 1998;
	antar* pa = &s02;
	pa->year = 1999;
	antar trio[3];
	trio[0].year = 2003;
	cout << trio->year << endl;

	const antar* arp[3] = { &s01, &s02, &s03 };
	cout << arp[1]->year << endl;

	const antar** ppa = arp; // 배열에 대한 포인터 생성
	// arp는 배열의 이름이므로, 그 첫 번째 원소의 주소를 의미한다.
	auto ppb = arp; // C++11 자동 형태 추측

	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
	return 0;
}