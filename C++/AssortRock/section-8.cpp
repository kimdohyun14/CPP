#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

/*
숙제 : 숫자빙고게임을 만들어보자.
1 ~ 25까지의 숫자가 있고 이 숫자를 골고루 섞어서 5 x 5로 출력한다.
플레이어는 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
0을 입력하면 게임을 종료한다.

숫자를 입력받았으면 숫자목록중 입력받은 숫자를 찾아서 * 로 만들어준다.
숫자를 * 로 만든 후에 빙고 줄 수를 체크한다. 5 x 5 이기 때문에
가로 5줄 세로 5줄 대각선 2줄이 나올 수 있다.
빙고줄이 몇 줄인지 체크해서 화면에 보여준다.

줄 완성한게 5줄 이상일 경우 게임을 종료한다.
*/

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	bool bCheckStar[25] = {};

	// 1 ~ 25까지의 숫자를 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 이 숫자들을 골고루 섞어준다. Shuffle
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iInput;
	int iBingoCount = 0;

	while (true)
	{
		system("cls");

		// 현재 빙고판을 보여준다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (bCheckStar[i * 5 + j] == true)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		cout << "1 ~ 25 숫자 중에서 없애고 싶은 숫자를 입력하세요(0은 종료) : ";
		cin >> iInput;

		// 예외 처리
		if (iInput == 0) break;
		if (iInput < 1 || iInput > 25)
		{
			cout << "범위를 벗어난 숫자를 입력했습니다." << endl << endl;
			continue;
		}

		// 입력한 숫자를 찾아서 * 로 만들어준다.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				bCheckStar[i] = true;
				break;
			}
		}

		/*
		빙고가 됬는지 확인하기.
		가로 5줄 : 시작 부분의 인덱스가 0, 5, 10, 15, 20
		세로 5줄 : 시작 부분의 인덱스가 0, 1, 2, 3, 4
		대각선 2줄 : 0, 6, 12, 18, 24 / 4, 8, 12, 16, 20
		
		체크할 때는 모두 * 이여야만 빙고로 카운트 해준다.
		*/

		bool bCheck = true; // 빙고가 되었는지 체크해주는 변수
		iBingoCount = 0;    // 총 몇 번 빙고가 성립됬는지

		// 가로 빙고 체크
		for (int i = 0; i < 25; i += 5)
		{
			bCheck = true; // 일단 빙고가  체크한다.

			for (int j = 0; j < 5; ++j)
			{
				// 하나라도 별이 없다면
				if (bCheckStar[i + j] == false) 
				{
					// 빙고 실패
					bCheck = false;
					break;
				}
			}

			// 빙고인지 체크해서, 빙고가 맞다면 빙고 횟수 증가
			if (bCheck == true)
				++iBingoCount;
		}

		// 세로 빙고 체크
		for (int i = 0; i < 5; ++i)
		{
			bCheck = true;

			for (int j = 0; j < 25; j += 5)
			{
				if (bCheckStar[i + j] == false)
				{
					bCheck = false;
					break;
				}
			}

			if (bCheck == true)
				++iBingoCount;
		}

		// 대각선 체크 : 0, 6, 12, 18, 24
		bCheck = true;
		for (int i = 0; i < 25; i += 6)
		{
			if (bCheckStar[i] == false)
			{
				bCheck = false;
				break;
			}
		}

		if(bCheck == true)
			++iBingoCount;

		// 대각선 체크 : 4, 8, 12, 16, 20
		bCheck = true;
		for (int i = 4; i < 24; i += 4)
		{
			if (bCheckStar[i] == false)
			{
				bCheck = false;
				break;
			}
		}

		if (bCheck == true)
			++iBingoCount;


		// 빙고가 된 줄이 5줄 이상이라면 게임을 종료한다.
		if (iBingoCount >= 5)
		{
			cout << "5줄 이상 Bingo 되었습니다!!" << endl;
			break;
		}
	}

	cout << "게임을 종료합니다." << endl;
	return 0;
}
