#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

/*
���� : ���ں�������� ������.
1 ~ 25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5 x 5�� ����Ѵ�.
�÷��̾�� ���ڸ� �Է¹޴´�. 1 ~ 25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.
0�� �Է��ϸ� ������ �����Ѵ�.

���ڸ� �Է¹޾����� ���ڸ���� �Է¹��� ���ڸ� ã�Ƽ� * �� ������ش�.
���ڸ� * �� ���� �Ŀ� ���� �� ���� üũ�Ѵ�. 5 x 5 �̱� ������
���� 5�� ���� 5�� �밢�� 2���� ���� �� �ִ�.
�������� �� ������ üũ�ؼ� ȭ�鿡 �����ش�.

�� �ϼ��Ѱ� 5�� �̻��� ��� ������ �����Ѵ�.
*/

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	bool bCheckStar[25] = {};

	// 1 ~ 25������ ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	// �� ���ڵ��� ���� �����ش�. Shuffle
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

		// ���� �������� �����ش�.
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

		cout << "1 ~ 25 ���� �߿��� ���ְ� ���� ���ڸ� �Է��ϼ���(0�� ����) : ";
		cin >> iInput;

		// ���� ó��
		if (iInput == 0) break;
		if (iInput < 1 || iInput > 25)
		{
			cout << "������ ��� ���ڸ� �Է��߽��ϴ�." << endl << endl;
			continue;
		}

		// �Է��� ���ڸ� ã�Ƽ� * �� ������ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				bCheckStar[i] = true;
				break;
			}
		}

		/*
		���� ����� Ȯ���ϱ�.
		���� 5�� : ���� �κ��� �ε����� 0, 5, 10, 15, 20
		���� 5�� : ���� �κ��� �ε����� 0, 1, 2, 3, 4
		�밢�� 2�� : 0, 6, 12, 18, 24 / 4, 8, 12, 16, 20
		
		üũ�� ���� ��� * �̿��߸� ����� ī��Ʈ ���ش�.
		*/

		bool bCheck = true; // ���� �Ǿ����� üũ���ִ� ����
		iBingoCount = 0;    // �� �� �� ���� ���������

		// ���� ���� üũ
		for (int i = 0; i < 25; i += 5)
		{
			bCheck = true; // �ϴ� ���� ��ٰ� üũ�Ѵ�.

			for (int j = 0; j < 5; ++j)
			{
				// �ϳ��� ���� ���ٸ�
				if (bCheckStar[i + j] == false) 
				{
					// ���� ����
					bCheck = false;
					break;
				}
			}

			// �������� üũ�ؼ�, ���� �´ٸ� ���� Ƚ�� ����
			if (bCheck == true)
				++iBingoCount;
		}

		// ���� ���� üũ
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

		// �밢�� üũ : 0, 6, 12, 18, 24
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

		// �밢�� üũ : 4, 8, 12, 16, 20
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


		// ���� �� ���� 5�� �̻��̶�� ������ �����Ѵ�.
		if (iBingoCount >= 5)
		{
			cout << "5�� �̻� Bingo �Ǿ����ϴ�!!" << endl;
			break;
		}
	}

	cout << "������ �����մϴ�." << endl;
	return 0;
}