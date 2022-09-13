#include <iostream>

/*
�ε� �Ҽ��� = �ڸ� �̵��Ѵ�.

"�⺻�� + ������"
�Ҽ����� �����Ͽ� ���� �ڸ��� �ű��.
3.45E6 => 3.45�� 1,000,000�� ���ϴ� ��
6�� ����(exponent)
3.45�� ����(mantissa)
8.33E-4 => 8.33�� 1/10,000�� ���ϴ� ��

��ȿ ���ڴ� � ������ �ǹ� �ִ� ���ڸ� ���Ѵ�.
*/

int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // ���� �Ҽ��� �������� ���

	float tub = 10.0 / 3.0;   // ��ȿ ���� 6��, 3.0 ���� �Ҽ��̴�.
	double mint = 10.0 / 3.0; // ��ȿ ���� 15��
	const float million = 1.0e6;
	
	// �Ϲ������� cout�� �ڿ� ���� 0�� ������� �ʴ´�.
	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	return 0;
}