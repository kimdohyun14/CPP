#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	/*
	배열 : 여러개의 변수를 한 번에 생성해줄 수 있는 기능이다.
	형태 : 변수타입 배열명[개수]; 의 형태로 선언할 수 있다.
	배열의 특징 : 배열은 연속된 메모리 블럭에 공간이 할당된다.
	배열은 인덱스를 이용해서 원하는 부분에 접근하여 값을 저장할 수 있다.
	인덱스는 0부터 개수-1 까지이다.
	즉, 10개라면 0 ~ 9까지의 총 10개의 인덱스를 가지게 된다.
	*/

	// 배열 뿐만 아니라 일반 변수들도 선언을 하고 값을 초기화하지 않을 경우
	// 쓰레기값이 들어가게 된다.

	// 여러가지의 초기화 방법
	//int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// 0 ~ 4까지는 1,2,3,4,5의 값이 들어가게 되고 나머지는 모두 0으로 초기화된다.
	//int iArray[10] = { 1,2,3,4,5 };

	// 비어있는 중괄호를 대입해줄 경우 모든 인덱스를 0으로 초기화한다.
	int iArray[10] = {};
	iArray[1] = 1234;

	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}

	/*
	배열 개수를 2개 지정하면 2차원배열이 된다. 3개를 지정하면 3차원배열이 된다.
	2차원 배열의 개수는 앞의 수 * 뒤의 수
	*/
	// 부분 초기화 가능
	int iArray2[10][10] = { {1,2,3}, {4,5,6} };

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << iArray2[i][j] << ' ';
		}

		cout << endl;
	}

	system("cls");

	srand((unsigned int)time(0));

	// Lotto Program
	int iLotto[45] = {};

	// 1 ~ 45까지의 숫자를 차례대로 넣어준다. (중복없이)
	for (int i = 0; i < 45; ++i)
	{
		iLotto[i] = i + 1;
	}

	// Swap 알고리즘
	/*
	int iNum1 = 1, iNum2 = 2, iNum3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;
	*/

	//Shuffle
	int iTemp, idx1, idx2;
	// 100번 정도 골고루 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 45; // 0 ~ 44까지 랜덤된 위치를 받아온다.
		idx2 = rand() % 45;

		// 두 개의 카드를 스왑한다.
		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	// 로또 번호 출력해보자.
	cout << "로또 번호 : ";
	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << " ";
	}

	cout << "보너스번호 : " << iLotto[6] << endl;
	return 0;
}