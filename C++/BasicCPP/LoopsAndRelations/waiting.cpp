#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	cout << "���� �ð��� �� ������ �Է� : ";
	float sec;
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC; // ���� �ð��� �ý��� ���� Ŭ�� ���� ��ȯ�Ѵ�.

	cout << "ī��Ʈ ���� \a\n";
	clock_t start = clock();
	while (clock() - start < delay); // �ð��� ����� ������ ���(busy waiting)
	cout << "����\a\n";
	return 0;
}