#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

/*
0 : ��
1 : ��
2 : ������
3 : ������
4 : ��ź
5 : �Ŀ�������
6 : ���б� ������
7 : ���� ������
8 : ��Ȧ
*/

struct _tagPoint
{
	int x;
	int y;
};

// typedef : Ÿ���� �������ϴ� ����̴�.
typedef _tagPoint  POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallPush;
	bool bPushOnOff;
	bool bTransparency;
	int  iBombPower;
}PLAYER, *PPLAYER;

void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos,
	PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayer->tPos = *pStartPos;

	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111100000000");
	strcpy_s(Maze[2],  "00100010000111111100");
	strcpy_s(Maze[3],  "01100010000000000100");
	strcpy_s(Maze[4],  "01000011110001111100");
	strcpy_s(Maze[5],  "01000000001111000000");
	strcpy_s(Maze[6],  "01100000001000000000");
	strcpy_s(Maze[7],  "00100000001111111000");
	strcpy_s(Maze[8],  "00001110000000001000");
	strcpy_s(Maze[9],  "01111011111111111000");
	strcpy_s(Maze[10], "01000000000000000000");
	strcpy_s(Maze[11], "01111100111111100000");
	strcpy_s(Maze[12], "00000111100000111110");
	strcpy_s(Maze[13], "01111100000000000010");
	strcpy_s(Maze[14], "01000000001111111110");
	strcpy_s(Maze[15], "01111110011000000000");
	strcpy_s(Maze[16], "00000010010000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");
}

void Output(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (Maze[i][j] == '4')
				cout << "��";

			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "��";

			else if (Maze[i][j] == '0')
				cout << "��";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "��";

			else if (Maze[i][j] == '3')
				cout << "��";

			else if (Maze[i][j] == '5')
				cout << "��";

			else if (Maze[i][j] == '6')
				cout << "��";

			else if (Maze[i][j] == '7')
				cout << "��";
		}

		cout << endl;
	}

	cout << "��ź�Ŀ� : " << pPlayer->iBombPower << endl;
	cout << "����� : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";

	else
		cout << "OFF\t";

	cout << "���б� : ";
	if (pPlayer->bWallPush)
	{
		cout << "���� / ";

		if (pPlayer->bPushOnOff)
			cout << "ON" << endl;

		else
			cout << "OFF" << endl;
	}
		

	else
		cout << "�Ұ��� / OFF" << endl;
}

bool AddItem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if(pPlayer->iBombPower < 5)
			++pPlayer->iBombPower;

		return true;
	}

	else if (cItemType == '6')
	{
		pPlayer->bWallPush = true;
		pPlayer->bPushOnOff = true;
		return true;
	}

	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y - 1 >= 0)
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				// ���� ��ĭ�� 0���� ũ�ų� ���� ��� (���� üũ)
				if (pPlayer->tPos.y - 2 >= 0)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�.
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						// ����ȭ�� ���� ������ �� �ְ�
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;
					}

					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// ��ĭ�� ���̿��µ� ��� ������ش�.
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.y;
					}
				}

				else if(pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}

			// �� �бⰡ OFF ������ ���
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
		{
			--pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 20)
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' &&
			Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				// ���� ��ĭ�� 0���� ũ�ų� ���� ��� (���� üũ)
				if (pPlayer->tPos.y + 2 < 20)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�.
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						// ����ȭ�� ���� ������ �� �ְ�
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;
					}

					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// ��ĭ�� ���̿��µ� ��� ������ش�.
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.y;
					}
				}

				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}

			// �� �бⰡ OFF ������ ���
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}

		
		else if (pPlayer->bTransparency)
		{
			++pPlayer->tPos.y;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20)
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				// ���� ��ĭ�� 0���� ũ�ų� ���� ��� (���� üũ)
				if (pPlayer->tPos.x + 2 < 20)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�.
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						// ����ȭ�� ���� ������ �� �ְ�
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;
					}

					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// ��ĭ�� ���̿��µ� ��� ������ش�.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.x;
					}
				}

				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}

			// �� �бⰡ OFF ������ ���
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
		{
			++pPlayer->tPos.x;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		// ������ üũ�Ѵ�.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' &&
			Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}

		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0')
		{
			// �� �бⰡ ON ������ ���
			if (pPlayer->bPushOnOff)
			{
				// ���� ��ĭ�� 0���� ũ�ų� ���� ��� (���� üũ)
				if (pPlayer->tPos.x - 2 >= 0)
				{
					// ���� ��ĭ�� ���̾�� �бⰡ �����ϴ�. �׷��Ƿ� ������ üũ�Ѵ�.
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						// ����ȭ�� ���� ������ �� �ְ�
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;
					}

					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1')
					{
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// ��ĭ�� ���̿��µ� ��� ������ش�.
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.x;
					}
				}

				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}

			// �� �бⰡ OFF ������ ���
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
		{
			--pPlayer->tPos.x;
		}

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;
	}
}

// ������ ������ const�� �����ϸ� ����Ű�� ����� ���� ������ �� ����.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer,
	PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	// ���� ��ġ�� ���� ��쿡 ����
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	// �ߺ� ��ġ ��ġ ����
	for (int i = 0; i < *pBombCount; ++i)
	{
		if (pPlayer->tPos.x == pBombArr[i].x && 
			pPlayer->tPos.y == pBombArr[i].y)
			return;
	}
	
	// ���� ��ġ�� ��ź�� ��ġ�� ����Ѵ�.
	pBombArr[*pBombCount] = (*pPlayer).tPos;
	// ��ġ�� ��ź �� ����
	++(*pBombCount);
	// ������ ��ź�̶�� ǥ��
	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr,
	int* pBombCount)
{
	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		// ��ź�� �Ŀ��� ���� �ٸ��� �����Ű�� ���ؼ�
		for (int j = 1; j <= pPlayer->iBombPower; ++j)
		{
			// ��
			if (pBombArr[i].y - j >= 0)
			{
				// ���� ���� �� ���� Ȯ���� �������� ����ϵ���
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0')
				{
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';

						else if (iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}


				// �÷��̾ ��ź�� �¾��� �� ���������� ���ư���.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			// �Ʒ�
			if (pBombArr[i].y + j < 20)
			{
				// ���� ���� �� ���� Ȯ���� �������� ����ϵ���
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0')
				{
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';

						else if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

				// �÷��̾ ��ź�� �¾��� �� ���������� ���ư���.
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			// ����
			if (pBombArr[i].x - j >= 0)
			{
				// ���� ���� �� ���� Ȯ���� �������� ����ϵ���
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0')
				{
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';

						else if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}


				// �÷��̾ ��ź�� �¾��� �� ���������� ���ư���.
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			// ������
			if (pBombArr[i].x + j < 20)
			{
				// ���� ���� �� ���� Ȯ���� �������� ����ϵ���
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0')
				{
					// ������ ��� Ȯ���� ���Ѵ�.
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';

						else if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}


				// �÷��̾ ��ź�� �¾��� �� ���������� ���ư���.
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}

	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));

	// 20 x 20 �̷θ� ������ش�.
	char strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;
	POINT tBombPos[5] = {};

	// �̷θ� �����Ѵ�.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		// �̷θ� ����Ѵ�.
		Output(strMaze, &tPlayer);

		// �����ߴ��� üũ
		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y)
		{
			cout << "�����߽��ϴ�." << endl;
			system("pause");
			break;
		}

		cout << "[t : ��ź��ġ u : ��ź ��Ʈ���� i : ���б� ON/OFF]" << endl;
		cout << "[w : �� s : �Ʒ� a : ���� d : ������ q : ����] : ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cInput == 'u' || cInput == 'U')
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cInput == 'i' || cInput == 'I')
		{
			if (tPlayer.bWallPush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		else
			MovePlayer(strMaze, &tPlayer, cInput);
	}
	
	return 0;
}