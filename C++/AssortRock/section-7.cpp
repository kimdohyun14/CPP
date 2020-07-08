#include <iostream>
#include <time.h>

// console input output 헤더파일
// 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.
#include <conio.h> // 코니온
using namespace std;

int main()
{
	/* 숫자 퍼즐 게임 프로그램 */
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다.
	// 공백을 의미하는 값으로 특수한 값을 사용한다.
	// INT_MAX는 의미 정의되어있는 값으로
	// int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 저장할 변수를 만들어준다.
	// (별을 일일이 찾아주는 것이 아니라, 별의 위치를 기억하고 있으면 편하다.)
	int iStarIndex = 24;

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls"); // 화면을 지우고

		// 세로
		for (int i = 0; i < 5; ++i)
		{
			// 가로
			for (int j = 0; j < 5; ++j)
			{
				// i가 0일 때 j는 0 ~ 4까지 반복한다. 0 * 5 + (0 ~ 4)
				// 인덱스는 0, 1, 2, 3, 4

				// i가 1일 때 j는 0 ~ 4까지 반복한다. 1 * 5 + (0 ~ 4)
				// 인덱스는 5, 6, 7, 8, 9

				// 1차원 배열이지만, 마치 2차원 배열처럼 보여준다.
				// 줄번호 * 가로개수 + 칸번호 => 2D 평면에서 무언가를 할 때 많이 사용된다.
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		// true로 주어서 먼저 모두 맞췄다 라고 가정해둔다.
		bool bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
		// 이 부분을 테스트할려면 Shuffle을 안하면 테스트할 수 있다.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << "(w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료) : ";
		// _getch() 함수는 문자 1개를 입력받는 함수이다.
		// 이 함수는 Enter를 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료된다.
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// 가장 윗줄일 때는 w를 눌러도 위로 올라가서는 안된다.
			// 즉, 가장 윗줄이 아닐때만 해당 키를 눌렀을 때 동작하게 만들면 된다.
			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				--iStarIndex;
			}
			break;
		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				++iStarIndex;
			}
			break;
		}
	}

	cout << endl << "게임을 종료합니다." << endl;
	return 0;
}