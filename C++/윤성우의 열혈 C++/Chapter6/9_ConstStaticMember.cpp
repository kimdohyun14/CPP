#include <iostream>
using namespace std;

// const static ����� 
class CountryArea
{
public:
	const static int RUSSIA = 1707540; // ����� ���ÿ� �ʱ�ȭ ����
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "���þ� ����: " << CountryArea::RUSSIA << "km^2" << endl;
	cout << "�ɳ��� ����: " << CountryArea::CANADA << "km^2" << endl;
	cout << "�߱� ����: " << CountryArea::CHINA << "km^2" << endl;
	cout << "�ѱ� ����: " << CountryArea::SOUTH_KOREA << "km^2" << endl;
	return 0;
}