#include <iostream>
using namespace std;
int main()
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 5;

	int yamcosts[3] = { 20, 30, 80 };
	cout << sizeof yams << endl;
	cout << sizeof yams[0] << endl;

	// �κ��� �迭 �ʱ�ȭ
	// �����Ϸ��� ������ ���ҵ��� ��� 0���� �ʱ�ȭ
	float hotelTips[5] = { 5.0, 2.5 };
	cout << hotelTips[2] << endl;

	// �迭�� ��� ���Ҹ� 0���� �����ϰ� ���� ��
	long totals[500] = { 0 };
	cout << totals[488] << endl;

	// �迭�� ù��° ���Ҹ� 1, �������� ��� 0���� �ʱ�ȭ
	long others[500] = { 1 };
	cout << others[412] << endl;

	// �����Ϸ��� �迭 ������ ������ �����ϵ��� �����ϴ� ���� ���� �ʴ�.
	// => ���α׷��Ӱ� ������ ������ �����Ϸ��� ������ ������ �ٸ� �� �����Ƿ�
	// �ٸ� ���ڿ����� char�� �迭�� ������ �����ϰ� ����� �� �ִ�.
	char things[] = { 'a', 'b', 'c', 'z', '\0'};
	cout << "things �� ���ڿ� ���� : " << sizeof things / sizeof (char) << endl;
	cout << things << endl;

	return 0;
}