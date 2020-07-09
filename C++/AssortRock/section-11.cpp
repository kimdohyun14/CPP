#include <iostream>
using namespace std;

#define NAME_SIZE    32
#define ADDRESS_SIZE 128
#define PHONE_SIZE   14  // 000-0000-0000\n
#define STUDENT_MAX  10

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int	iNumber;
	int	iKor;
	int	iEng;
	int	iMath;
	int	iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// 배열에 추가된 개수를 저장할 변수를 만들어준다.
	int iStudentCount = 0;
	int iStdNumber = 1;

	char strName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");

		// 메뉴를 출력한다.
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 학생종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		// cin은 만약 오른쪽에 int변수가 오면 정수를 입력해야 한다.
		// 오른쪽에 오는 변수 타입에 맞춰서 값을 입력해야 하는데
		// 실수로 정수가 아닌 문자를 입력할 경우 에러가 발생한다.
		// 그렇기 때문에 예외처리로 에러가 발생했는지를 여기서 체크하여
		// 에러가 발생하면 cin 내부의 에러버퍼를 비워주고 cin 내부에
		// 입력버퍼가 있는데 입력버퍼는 입력한 값을 저장해놓고 그 값을
		// 변수에 넣어주는 역할을 한다. 이 입력버퍼에 \n이 남아있으므로
		// 버퍼를 순회하여 \n을 지워준다.
		// 버퍼 : 임시 저장공간이다.
		// 먼저 에러를 체크한다.
		// cin.fail()을 했을 때 입력 에러가 발생했을경우 true를 반환한다.
		if(cin.fail())
		{ 
			// 에러버퍼를 지워준다.
			cin.clear();

			// 입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.
			// 첫번째에는 검색하고자 하는 버퍼 크기를 지정한다. 넉넉하게 1024 지정
			// 두번째에는 찾고자하는 문자를 넣어준다. delim
			// 입력버퍼 처음부터 \n이 있는 곳까지 찾아서 그 부분을 모두 지워줘서
			// 다시 입력받을 수 있도록 해준다.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			system("cls");
			cout << "================ 학생추가 ================" << endl;

			// 등록된 학생이 등록할 수 있는 최대치일 경우 더이상 등록이
			// 안되도록 막는다.
			if (iStudentCount == STUDENT_MAX)
				break;

			// 학생정보를 추가한다. 
			// 학생정보는 이름, 주소, 전화번호,국어, 영어, 수학 점수는 입력받고
			// 학번, 총점, 평균은 연산을 통해 계산해준다.
			// 이름을 입력받는다.
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');

			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal +=
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "================ 학생삭제 ================" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록되어있는 학생 수만큼 반복하면 학생을 찾는다.
			for (int i = 0; i < iStudentCount; ++i)
			{
				// 학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; ++j)
					{
						// 뒤에 있는 데이터를 앞으로 한 칸씩 땡겨온다.
						tStudentArr[j] = tStudentArr[j + 1];
					}

					--iStudentCount;
					cout << "학생을 삭제했습니다." << endl;
					break;
				}
			}

			break;
		case MENU_SEARCH:
			system("cls");
			cout << "================ 학생탐색 ================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록되어있는 학생 수만큼 반복하면 학생을 찾는다.
			for (int i = 0; i < iStudentCount; ++i)
			{
				// 학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "================ 학생출력 ================" << endl;

			// 등록된 학생 수만큼 반복하며 학생정보를 출력한다.
			for (int i = 0; i < iStudentCount; ++i)
			{
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}

			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}

		system("pause");
	}

	return 0;
}
