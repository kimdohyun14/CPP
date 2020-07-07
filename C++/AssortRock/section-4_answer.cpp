#include <iostream>
using namespace std;

int main()
{
	// 구구단을 2단부터 9단까지 출력
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}

	cout << endl;

	/*
	2단 3단 4단
	5단	6단	7단
	8단	9단	10단
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

	for (int i = 0; i < 5; ++i) // 세로
	{
		for (int j = 0; j < 5 - i; ++j) // 가로
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

	// 공백 : 3, 2, 1, 0
	// 별   : 1, 3, 5, 7
	for (int i = 0; i < 4; ++i)
	{
		// 공백을 출력
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";
		}

		// 별을 출력
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

	int iLine = 7;   // 변수로 만든 이유 : 값의 변함에 따라 다른 다이아몬드를 만들기 위해서
	int iCount = 0;  // 식을 구성한다.
	for (int i = 0; i < iLine; ++i)
	{
		// 공백 : 3, 2, 1, 0, 1, 2, 3
		// 별   : 1, 3, 5, 7, 5, 3, 1

		iCount = i;

		// i 값이 7줄 기준 4, 5, 6만 해당됨
		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
			// 7 - 1 - 4 = 2  1개
			// 7 - 1 - 5 = 1  2개
			// 7 - 1 - 6 = 0  3개(공백이)
		}

		// i값이 0, 1, 2, 3일때는 iCount에 i가 그대로 들어간다.
		// i값이 4, 5, 6일때는 iCount는 2, 1, 0이 된다.

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