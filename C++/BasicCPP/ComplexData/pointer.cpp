#include <iostream>
using namespace std;
int main()
{
	int updates = 6;
	int* p_updates; // int* �� (���� ��������, int���� �����ϴ� ������)

	// �����ʹ� �ּҸ� �����Ѵ�!
	p_updates = &updates; // p_updates�� int���� �����Ѵ�.

	cout << "value : " << updates;
	cout << ", *p_value : " << *p_updates << endl;

	cout << "�ּ�: " << &updates;
	cout << ", " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "����� value = " << updates << endl;
	return 0;
}