#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "���� ǥ���� x = 100�� ���� ";
	cout << (x = 100) << endl;
	cout << "���� x�� ���� " << x << endl;
	cout << "���� ǥ���� x < 3�� �������� ";
	cout << (x < 3) << endl;
	cout << "���� ǥ���� x > 3�� �������� ";
	cout << (x > 3) << endl;
	cout.setf(ios_base::boolalpha); // �ֽ� C++ ���
	cout << "���� ǥ���� x < 3�� �������� ";
	cout << (x < 3) << endl;
	cout << "���� ǥ���� x > 3�� �������� ";
	cout << (x > 3) << endl;
	return 0;
}