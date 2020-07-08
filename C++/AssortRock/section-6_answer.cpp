#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};
	
	// 1 ~ 9 까지 숫자를 설정한다.
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 설정된 숫자를 섞어준다. (Shuffle 단순 알고리즘)
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << iNumber[0] << ' ' << iNumber[1] << ' ' << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGameCount = 1;

	while (true)
	{
		cout << iGameCount << " 회" << endl;
		cout << "1 ~ 9 사이의 숫자중 숫자 3개를 입력하세요(0 : 종료) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		// 예외처리 (사용자는 이상한 방법으로 접근하는 것을 사전에 미리 막는다.)
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0) break;

		else if (iInput[0] < 0 || iInput[0] > 9 ||
			iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			continue;
		}

		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] ||
			iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입력하였습니다." << endl;
			continue;
		}

		// 매번 Strike와 Ball의 수가 달라지기 때문에 0으로 초기화하고 다시 계산한다.
		iStrike = iBall = 0;

		// i의 for문은 맞춰야 할 숫자의 인덱스를 구한다.
		for (int i = 0; i < 3; ++i)
		{
			// j의 for문은 입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; ++j)
			{
				// 맞춰야 할 숫자와 입력한 수가 같다면?
				if (iNumber[i] == iInput[j])
				{
					// 자리도 같다면?
					if (i == j)
						++iStrike;
					else
						++iBall;

					/*
					같은 수가 있다면, 이 뒤로는 더이상 같은 수가 없으므로 다음 맞춰야할 숫자로
					바로 비교하면 된다. 그래서 break문으로 j의 for문을 빠져나가게 하고
					다음 맞춰야 할 숫자와 다시 비교하게 된다.
					*/

					break; // j의 for문을 빠져나간다.
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
		{
			cout << "Out" << endl;
		}

		else
			cout << iStrike << " strike " << iBall << " ball" << endl;

		++iGameCount;
	}

	return 0;
}