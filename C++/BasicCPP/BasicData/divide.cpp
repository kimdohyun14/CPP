#include <iostream>
using namespace std;

// �߿��� ���� �ǿ����� �� �ϳ��� �ε� �Ҽ������� �ִٸ� ����� �ε� �Ҽ������̴�.
// �ε� �Ҽ����� ����� �⺻������ double���̶�� ����� �������.

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "���� ������: 9/5 = " << 9 / 5 << endl;
	cout << "�ε� �Ҽ����� ������: 9.0/5.0 = " << 9.0 / 5.0 << endl;
	cout << "ȥ�� ������: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double�� ���: 1e7/9.0 = " << 1e7 / 9.0 << endl;
	cout << "float�� ���: 1e7f/9.0f = " << 1e7f / 9.0f << endl << endl;

	cout << 9 / 5 << endl;      // int/int => int ������ ����
	cout << 9L / 5L << endl;    // long/long => long ������ ����
	cout << 9.0 / 5.0 << endl;  // double/double => double ������ ����
	cout << 9.0 / 5.0f << endl; // double/float => float ������ ����
	return 0;
}