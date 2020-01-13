#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// 하나의 try 블록에 여러 개의 catch 블록을 사용할 수 있다.

int StoI(const char* str)
{
	int len = strlen(str);
	int num = 0;

	if (len != 0 && str[0] == '0')
		throw 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9') // 들어오는 파라미터가 배열이므로 이러한 접근이 가능하다.
			throw str[i];

		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}
	return num;
}

void show(char* str)
{
	cout << str << endl;
}

int main()
{
	char str1[100];
	char str2[100];

	while (1)
	{
		cout << "두 개의 숫자 입력: ";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "문자 " << ch << "가 입력되었습니다." << endl;
			cout << "재입력 진행합니다." << endl << endl;
		}
		catch (int expn)
		{
			if (expn == 0)
				cout << "0으로 시작하는 숫자는 입력불가." << endl;
			else
				cout << "비정상적 입력이 이루어졌습니다." << endl;

			cout << "재입력 진행합니다." << endl << endl;
		}
	}

	cout << "프로그램을 종료합니다." << endl;
	return 0;
}