#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};
	
	// 1 ~ 9 ���� ���ڸ� �����Ѵ�.
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	// ������ ���ڸ� �����ش�. (Shuffle �ܼ� �˰���)
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
		cout << iGameCount << " ȸ" << endl;
		cout << "1 ~ 9 ������ ������ ���� 3���� �Է��ϼ���(0 : ����) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		// ����ó�� (����ڴ� �̻��� ������� �����ϴ� ���� ������ �̸� ���´�.)
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0) break;

		else if (iInput[0] < 0 || iInput[0] > 9 ||
			iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			continue;
		}

		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] ||
			iInput[1] == iInput[2])
		{
			cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			continue;
		}

		// �Ź� Strike�� Ball�� ���� �޶����� ������ 0���� �ʱ�ȭ�ϰ� �ٽ� ����Ѵ�.
		iStrike = iBall = 0;

		// i�� for���� ����� �� ������ �ε����� ���Ѵ�.
		for (int i = 0; i < 3; ++i)
		{
			// j�� for���� �Է¹��� ������ �ε����� ���Ѵ�.
			for (int j = 0; j < 3; ++j)
			{
				// ����� �� ���ڿ� �Է��� ���� ���ٸ�?
				if (iNumber[i] == iInput[j])
				{
					// �ڸ��� ���ٸ�?
					if (i == j)
						++iStrike;
					else
						++iBall;

					/*
					���� ���� �ִٸ�, �� �ڷδ� ���̻� ���� ���� �����Ƿ� ���� ������� ���ڷ�
					�ٷ� ���ϸ� �ȴ�. �׷��� break������ j�� for���� ���������� �ϰ�
					���� ����� �� ���ڿ� �ٽ� ���ϰ� �ȴ�.
					*/

					break; // j�� for���� ����������.
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "���ڸ� ��� ������ϴ�." << endl;
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