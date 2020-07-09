#include <iostream>
using namespace std;

#define NAME_SIZE	50
#define BOOK_MAX    100
/*
�������α׷� �����
���� �뿩 ���α׷�
1. å���
2. å �뿩
3. å �ݳ�
4. å ���
5. ����

å ����ü�� �̸�, �뿩 �ݾ�, å ��ȣ, �뿩���ΰ� �ʿ��ϴ�.
å ����� �����ϸ� å ������ ������ش�.
*/

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_RENTAL,
	MENU_RETURN,
	MENU_LIST,
	MENU_EXIT
};

struct _tagBook
{
	char	strBookName[NAME_SIZE];   // å �̸�
	int		iRentalAmount;            // �뿩 �ݾ�
	int		iBookNumber;              // å ��ȣ
	bool	bRental;                  // �뿩 ����
};

int main()
{
	_tagBook tBookArr[BOOK_MAX] = {};
	int iBookCount = 0;               // ��ϵ� å�� ��
	int iBookNumber = 1;              // å�� ���� ��ȣ

	char strRantalName[NAME_SIZE] = {};

	// å�� ã�Ҵ��� üũ�ϴ� ����
	bool bFind = false;

	while (true)
	{
		system("cls");

		// �޴��� ����Ѵ�.
		cout << "1. å ���" << endl;
		cout << "2. å �뿩" << endl;
		cout << "3. å �ݳ�" << endl;
		cout << "4. å ���" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;

		// ����ó��
		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');
			continue;
		}

		// ����
		if (iMenu == MENU_EXIT)
			break;

		// �޴��� ���� ������ �����Ѵ�.
		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "============== å ��� ==============" << endl;

			// �ִ�ġ�� �Ǹ�, ���̻� å�� ������� ���ϰ� �ȴ�.
			if (iBookCount == BOOK_MAX)
			{
				cout << "å�� ���̻� ����� �� �����ϴ�." << endl;
				break;
			}

			// �����ִ� �Է¹��ۿ��� '\n'�� �����ش�.
			cin.ignore(1024, '\n');

			cout << "å �̸� : ";
			cin.getline(tBookArr[iBookCount].strBookName, NAME_SIZE);

			cout << "�뿩 �ݾ� : ";
			cin >> tBookArr[iBookCount].iRentalAmount;

			// å ��ȣ�� ���� ��ȣ�̹Ƿ�, ����ϸ� �� ������� ��ȣ�� �ο����ش�.
			tBookArr[iBookCount].iBookNumber = iBookNumber;

			// å�� ����ϸ� �뿩 ���δ� ó������ ������ ���� �� �ְ� �����Ѵ�.
			// ���⼭�� false�� ���� �ƹ��� �뿩�� ���� �ʾҴٴ� ���̴�.
			tBookArr[iBookCount].bRental = false;

			++iBookNumber;
			++iBookCount;

			cout << "å ����� ���������� �����߽��ϴ�." << endl;
			break;
		case MENU_RENTAL:
			system("cls");
			cout << "============== å �뿩 ==============" << endl;

			// �����ִ� �Է¹��ۿ��� '\n'�� �����ش�.
			cin.ignore(1024, '\n');

			cout << "�뿩�ϰ��� �ϴ� å�� �̸��� �Է����ּ��� : ";
			cin.getline(strRantalName, NAME_SIZE);

			// ó������ ã�� ���ߴٰ� �����ϰ� �����Ѵ�.
			bFind = false;
			for (int i = 0; i < iBookCount; ++i)
			{
				// å�� ã�Ҵٸ�?
				if (strcmp(strRantalName, tBookArr[i].strBookName) == 0)
				{
					bFind = true;

					// å�� �뿩 ���θ� Ȯ���Ѵ�.
					if (tBookArr[i].bRental == false)
					{
						tBookArr[i].bRental = true;
						cout << "å�� �뿩�Ͽ����ϴ�." << endl;
						break;
					}
					
					else
					{
						cout << "å�� �뿩�� �� �����ϴ�." << endl;
						break;
					}
				}
			}

			if (bFind == false)
				cout << "�뿩�ϰ��� �ϴ� å�� ã�� �� �����ϴ�." << endl;


			break;
		case MENU_RETURN:
			system("cls");
			cout << "============== å �ݳ� ==============" << endl;

			// �����ִ� �Է¹��ۿ��� '\n'�� �����ش�.
			cin.ignore(1024, '\n');

			cout << "�ݳ��ϰ��� �ϴ� å�� �̸��� �Է����ּ��� : ";
			cin.getline(strRantalName, NAME_SIZE);

			// ó������ ã�� ���ߴٰ� �����ϰ� �����Ѵ�.
			bFind = false;
			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(strRantalName, tBookArr[i].strBookName) == 0)
				{
					bFind = true;
					tBookArr[i].bRental = false;

					cout << "å �ݳ��� �ϼ̽��ϴ�." << endl;
					break;
				}
			}

			if (bFind == false)
				cout << "�ݳ��ϰ��� �ϴ� å�� �̸��� ã�� �� �����ϴ�." << endl;

			break;
		case MENU_LIST:
			system("cls");
			cout << "============== å ��� ==============" << endl;
			
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "å �̸� : " << tBookArr[i].strBookName << endl;
				cout << "å ��ȣ : " << tBookArr[i].iBookNumber << endl;
				cout << "�뿩 �ݾ� : " << tBookArr[i].iRentalAmount << endl;
				cout << "�뿩 ���� : ";

				if (tBookArr[i].bRental == false)
					cout << "����" << endl;

				else
					cout << "�Ұ���" << endl;

				cout << endl;
			}

			break;
		case MENU_EXIT:
			break;
		default:
			cout << "�޴��� �߸������߽��ϴ�." << endl;
			break;
		}

		system("pause");
	}

	cout << "���� ���� ���α׷��� �̿����ּż� �����մϴ�." << endl;

	return 0;
}