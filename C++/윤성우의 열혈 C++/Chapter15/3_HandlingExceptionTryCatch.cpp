#include <iostream>
using namespace std;

// C++������ ����ó�� ��Ŀ������ �����Ѵ�.

int main()
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;

	try
	{
		// ���ܹ߻� ��������

		if (num2 == 0) // ���� ó���� �߻��Ѵٸ�
			throw num2;

		cout << "�������� �� : " << num1 / num2 << endl;
		cout << "�������� ������ : " << num1 % num2 << endl;
	}
	catch (int expn)  // ó���� ������ ���� ���
	{
		// ���� ó��

		cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}
	cout << "end of main" << endl;
	return 0;
}