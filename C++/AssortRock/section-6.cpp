#include <iostream>
#include <time.h>
using namespace std;

/*
���� : �߱����� �����
1 ~ 9 ������ ������ ���� 3���� ���´�. ��, ���ڴ� �ߺ��Ǿ�� �ȵȴ�.
3���� ���ڴ� * * * �� ���·� ��µǰ� �� 3���� ���ڸ� ���ߴ� �����̴�.
����ڴ� �� 3���� ���ڸ� ���� ������ ����ؼ� 3���� ���ڸ� �Է��Ѵ�.
���� ������� ���ڰ� 7 3 8 �� ���
����ڴ� 3���� ���ڸ� ��� �Է��Ѵ�.

����)

�Է� : 1 2 4 �� �Է����� ���, 1 2 4 �� ������� ������ �ƹ��͵� �����Ƿ�
out�� ����Ѵ�.

�Է� : 7 5 9 �� �Է����� ���, 7�� ������� ������ �ְ� ��ġ�� �����Ƿ�
strike�̴�. 5 9�� �����Ƿ� ����� 1strike 0ball�� ����Ѵ�.

�Է� : 7 8 6 �� �Է����� ���, 1strike, 1ball�� ����Ѵ�.

�̷��� ����� �ϰ� �Է��� �����鼭 ���������� 3���� ���ڸ� �ڸ����� ��� ��ġ�ϰ�
�Է��ϸ� ������ ����ȴ�. ���� �Է¹��� ���� 3���� �Ѱ��� 0�� ���� ��� ������ �����Ѵ�.
*/

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = { 1,2,3,4,5,6,7,8,9 };
	bool bVisited[9] = {}; // �ߺ� üũ
	int iAnswer[3] = {};   // ���� �迭
	int iUser[3] = {};     // ������ ��
	

	// 1 ~ 9 ������ ������ ���� 3���� ���´�.
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

	cout << "�̹��� ������ ������ �����ϴ�." << endl;
	cout << iAnswer[0] << ' ' << iAnswer[1] << ' ' << iAnswer[2] << endl << endl;

	int iStrike = 0, iBall = 0, iGame_Count = 0;

	cout << "���� �߱� ���α׷��� �����մϴ�!!!" << endl;
	while (true)
	{
		++iGame_Count;
		iStrike = 0, iBall = 0;

		cout << "���� 3���� �Է��ϼ���[ex 1 2 3(�ߺ� ���X), ���࿡ 0�� �Է½� exit] : ";
		cin >> iUser[0] >> iUser[1] >> iUser[2];

		if (iUser[0] == 0) break;
		if (iUser[1] == 0) break;
		if (iUser[2] == 0) break;

		// �ߺ��� Ȯ���Ѵ�.
		if (iUser[0] == iUser[1]) continue;
		if (iUser[0] == iUser[2]) continue;
		if (iUser[1] == iUser[2]) continue;

		/*
		����� ������ ���� ���غ���.
		�ڸ��� ����, ���ڵ� ���ٸ�? strike
		�ڸ��� �ٸ���, ���ڰ� ���� ���� �ִٸ� ball

		�����̷���, strike�� 3�����;� �����̴�.
		*/

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				// ���ڵ� ����, �ڸ��� ���ٸ�?
				if (iAnswer[i] == iUser[j] && i == j)
				{
					++iStrike;
					break;
				}
				
				// ���ڴ� ������, �ڸ��� �ٸ���?
				else if (iAnswer[i] == iUser[j])
				{
					++iBall;
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "�����Դϴ�!! �� " << iGame_Count << "�� ���� Ǫ�̽��ϴ�." << endl;
			break;
		}

		else
		{
			cout << "�ƽ��Ե� ������ �ƴմϴ�." << endl;
			cout << "strike : " << iStrike << endl;
			cout << "ball : " << iBall << endl;
		}

		cout << endl;
	}

	cout << "���� �߱� ���α׷��� �����մϴ�." << endl;
	return 0;
}