#include <iostream>
using namespace std;

int main()
{
	cout << "������ �ϳ� �Է�: ";
	int by;
	cin >> by;
	cout << "���� ũ��� " << by << endl;
	// ���� 1�� ������ �ʿ䰡 ����.
	// ���ϴ� ���Ǹ�ŭ �ǳʶ� �� �ִ�.
	for (int i = 0; i < 100; i += by)
	{
		cout << i << endl;
	}
	return 0;
}