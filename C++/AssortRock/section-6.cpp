#include <iostream>
#include <time.h>
using namespace std;

/*
숙제 : 야구게임 만들기
1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
3개의 숫자는 * * * 의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출 때까지 계속해서 3개씩 숫자를 입력한다.
만약 맞춰야할 숫자가 7 3 8 일 경우
사용자는 3개의 숫자를 계속 입력한다.

예시)

입력 : 1 2 4 를 입력했을 경우, 1 2 4 는 맞춰야할 숫자중 아무것도 없으므로
out을 출력한다.

입력 : 7 5 9 를 입력했을 경우, 7은 맞춰야할 숫자중 있고 위치도 같으므로
strike이다. 5 9는 없으므로 출력은 1strike 0ball을 출력한다.

입력 : 7 8 6 를 입력했을 경우, 1strike, 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게
입력하면 게임이 종료된다. 만약 입력받은 숫자 3개중 한개라도 0이 있을 경우 게임을 종료한다.
*/

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = { 1,2,3,4,5,6,7,8,9 };
	bool bVisited[9] = {}; // 중복 체크
	int iAnswer[3] = {};   // 정답 배열
	int iUser[3] = {};     // 유저의 답
	

	// 1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다.
	int idx1, idx2 = 0, iCount = 0;
	while (true)
	{
		idx1 = rand() % 9; // 0 ~ 8
		if (bVisited[idx1] == false)
		{
			bVisited[idx1] = true;
			++iCount;
			iAnswer[idx2++] = iNumber[idx1];
		}

		if (iCount == 3)
			break;
	}

	cout << "이번의 정답은 다음과 같습니다." << endl;
	cout << iAnswer[0] << ' ' << iAnswer[1] << ' ' << iAnswer[2] << endl << endl;

	int iStrike = 0, iBall = 0, iGame_Count = 0;

	cout << "숫자 야구 프로그램을 시작합니다!!!" << endl;
	while (true)
	{
		++iGame_Count;
		iStrike = 0, iBall = 0;

		cout << "숫자 3개를 입력하세요[ex 1 2 3(중복 허용X), 만약에 0을 입력시 exit] : ";
		cin >> iUser[0] >> iUser[1] >> iUser[2];

		if (iUser[0] == 0) break;
		if (iUser[1] == 0) break;
		if (iUser[2] == 0) break;

		// 중복을 확인한다.
		if (iUser[0] == iUser[1]) continue;
		if (iUser[0] == iUser[2]) continue;
		if (iUser[1] == iUser[2]) continue;

		/*
		정답과 유저의 답을 비교해보자.
		자리도 같고, 숫자도 같다면? strike
		자리는 다르나, 숫자가 같은 것이 있다면 ball

		정답이려면, strike가 3개나와야 정답이다.
		*/

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				// 숫자도 같고, 자리도 같다면?
				if (iAnswer[i] == iUser[j] && i == j)
				{
					++iStrike;
					break;
				}
				
				// 숫자는 같으나, 자리가 다르면?
				else if (iAnswer[i] == iUser[j])
				{
					++iBall;
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "정답입니다!! 총 " << iGame_Count << "번 만에 푸셨습니다." << endl;
			break;
		}

		else
		{
			cout << "아쉽게도 정답이 아닙니다." << endl;
			cout << "strike : " << iStrike << endl;
			cout << "ball : " << iBall << endl;
		}

		cout << endl;
	}

	cout << "숫자 야구 프로그램을 종료합니다." << endl;
	return 0;
}