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

	const antar** ppa = arp; // �迭�� ���� ������ ����
	// arp�� �迭�� �̸��̹Ƿ�, �� ù ��° ������ �ּҸ� �ǹ��Ѵ�.
	auto ppb = arp; // C++11 �ڵ� ���� ����

	cout << (*ppa)->year << endl;
	cout << (*(ppb + 1))->year << endl;
	return 0;
}