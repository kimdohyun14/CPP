#include <iostream>
using namespace std;

#define NAME_SIZE   50
#define BOOK_MAX    100
/*
관리프로그램 만들기
도서 대여 프로그램
1. 책등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여 금액, 책 번호, 대여여부가 필요하다.
책 목록을 선택하면 책 정보를 출력해준다.
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
	char	strBookName[NAME_SIZE];   // 책 이름
	int	iRentalAmount;            // 대여 금액
	int	iBookNumber;              // 책 번호
	bool	bRental;                  // 대여 여부
};

int main()
{
	_tagBook tBookArr[BOOK_MAX] = {};
	int iBookCount = 0;               // 등록된 책의 수
	int iBookNumber = 1;              // 책의 고유 번호

	char strRantalName[NAME_SIZE] = {};

	// 책을 찾았는지 체크하는 변수
	bool bFind = false;

	while (true)
	{
		system("cls");

		// 메뉴를 출력한다.
		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		// 예외처리
		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');
			continue;
		}

		// 종료
		if (iMenu == MENU_EXIT)
			break;

		// 메뉴에 따라서 다음을 동작한다.
		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "============== 책 등록 ==============" << endl;

			// 최대치가 되면, 더이상 책을 등록하지 못하게 된다.
			if (iBookCount == BOOK_MAX)
			{
				cout << "책을 더이상 등록할 수 없습니다." << endl;
				break;
			}

			// 남아있는 입력버퍼에서 '\n'을 지워준다.
			cin.ignore(1024, '\n');

			cout << "책 이름 : ";
			cin.getline(tBookArr[iBookCount].strBookName, NAME_SIZE);

			cout << "대여 금액 : ";
			cin >> tBookArr[iBookCount].iRentalAmount;

			// 책 번호는 고유 번호이므로, 등록하면 그 순서대로 번호를 부여해준다.
			tBookArr[iBookCount].iBookNumber = iBookNumber;

			// 책을 등록하면 대여 여부는 처음에는 무조건 빌릴 수 있게 설정한다.
			// 여기서의 false는 아직 아무도 대여를 하지 않았다는 뜻이다.
			tBookArr[iBookCount].bRental = false;

			++iBookNumber;
			++iBookCount;

			cout << "책 등록을 성공적으로 수행했습니다." << endl;
			break;
		case MENU_RENTAL:
			system("cls");
			cout << "============== 책 대여 ==============" << endl;

			// 남아있는 입력버퍼에서 '\n'을 지워준다.
			cin.ignore(1024, '\n');

			cout << "대여하고자 하는 책의 이름을 입력해주세요 : ";
			cin.getline(strRantalName, NAME_SIZE);

			// 처음에는 찾지 못했다고 가정하고 시작한다.
			bFind = false;
			for (int i = 0; i < iBookCount; ++i)
			{
				// 책을 찾았다면?
				if (strcmp(strRantalName, tBookArr[i].strBookName) == 0)
				{
					bFind = true;

					// 책의 대여 여부를 확인한다.
					if (tBookArr[i].bRental == false)
					{
						tBookArr[i].bRental = true;
						cout << "책을 대여하였습니다." << endl;
						break;
					}
					
					else
					{
						cout << "책을 대여할 수 없습니다." << endl;
						break;
					}
				}
			}

			if (bFind == false)
				cout << "대여하고자 하는 책을 찾을 수 없습니다." << endl;


			break;
		case MENU_RETURN:
			system("cls");
			cout << "============== 책 반납 ==============" << endl;

			// 남아있는 입력버퍼에서 '\n'을 지워준다.
			cin.ignore(1024, '\n');

			cout << "반납하고자 하는 책의 이름을 입력해주세요 : ";
			cin.getline(strRantalName, NAME_SIZE);

			// 처음에는 찾지 못했다고 가정하고 시작한다.
			bFind = false;
			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(strRantalName, tBookArr[i].strBookName) == 0)
				{
					bFind = true;
					tBookArr[i].bRental = false;

					cout << "책 반납을 하셨습니다." << endl;
					break;
				}
			}

			if (bFind == false)
				cout << "반납하고자 하는 책의 이름을 찾을 수 없습니다." << endl;

			break;
		case MENU_LIST:
			system("cls");
			cout << "============== 책 목록 ==============" << endl;
			
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "책 이름 : " << tBookArr[i].strBookName << endl;
				cout << "책 번호 : " << tBookArr[i].iBookNumber << endl;
				cout << "대여 금액 : " << tBookArr[i].iRentalAmount << endl;
				cout << "대여 여부 : ";

				if (tBookArr[i].bRental == false)
					cout << "가능" << endl;

				else
					cout << "불가능" << endl;

				cout << endl;
			}

			break;
		case MENU_EXIT:
			break;
		default:
			cout << "메뉴를 잘못선택했습니다." << endl;
			break;
		}

		system("pause");
	}

	cout << "도서 관리 프로그램을 이용해주셔서 감사합니다." << endl;

	return 0;
}
