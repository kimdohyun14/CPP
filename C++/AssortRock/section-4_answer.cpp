#include <iostream>
using namespace std;

int main()
{
	// �������� 2�ܺ��� 9�ܱ��� ���
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}

	cout << endl;

	/*
	2�� 3�� 4��
	5��	6��	7��
	8��	9��	10��
	*/
	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i + 1 << " * " << j << " = " << (i + 1) * j << "\t";
			cout << i + 2 << " * " << j << " = " << (i + 2) * j << endl;
		}

		cout << endl;
	}


	/*
	*
	**
	***
	****
	*****
	*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	/*
	*****
	****
	***
	**
	*
	*/

	for (int i = 0; i < 5; ++i) // ����
	{
		for (int j = 0; j < 5 - i; ++j) // ����
		{
			cout << "*";
		}

		cout << endl;
	}

	/*
	   *
	  ***
	 *****
	*******
	*/

	// ���� : 3, 2, 1, 0
	// ��   : 1, 3, 5, 7
	for (int i = 0; i < 4; ++i)
	{
		// ������ ���
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";
		}

		// ���� ���
		for (int j = 0; j < i * 2 + 1; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}

	cout << endl;

	/*
		*
	   ***
	  *****
	 *******
	  *****
	   ***
	    *
	*/

	int iLine = 7;   // ������ ���� ���� : ���� ���Կ� ���� �ٸ� ���̾Ƹ�带 ����� ���ؼ�
	int iCount = 0;  // ���� �����Ѵ�.
	for (int i = 0; i < iLine; ++i)
	{
		// ���� : 3, 2, 1, 0, 1, 2, 3
		// ��   : 1, 3, 5, 7, 5, 3, 1

		iCount = i;

		// i ���� 7�� ���� 4, 5, 6�� �ش��
		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
			// 7 - 1 - 4 = 2  1��
			// 7 - 1 - 5 = 1  2��
			// 7 - 1 - 6 = 0  3��(������)
		}

		// i���� 0, 1, 2, 3�϶��� iCount�� i�� �״�� ����.
		// i���� 4, 5, 6�϶��� iCount�� 2, 1, 0�� �ȴ�.

		for (int j = 0; j < iLine / 2 - iCount; ++j)
		{
			cout << " ";
		}

		for (int j = 0; j < iCount * 2 + 1; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}


	return 0;
}