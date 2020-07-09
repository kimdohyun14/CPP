#include <iostream>
using namespace std;

#define NAME_SIZE	32

/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능이다.
사용자정의 변수 타입이다.
형태 : struct 구조체명 {};

배열과 구조체의 공통점
1. 데이터의 집합이다.
2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다.
*/

// 구조체
struct _tagStudent
{
	// 멤버 변수들
	char	strName[NAME_SIZE];
	int     iNumber;
	int     iKor;
	int	iEng;
	int	iMath;
	int	iTotal;
	float	fAvg;
};

int main()
{
	_tagStudent tStudent = {}; // 구조체 전체를 0으로 초기화가 된다. (구조체도 초기화를 안해주면 쓰레기 값이 들어가게 된다.)
	_tagStudent tStudentArr[100] = {}; // 이렇게 배열로도 선언이 가능하다.

	// 구조체 멤버에 접근할때는 . 을 이용해서 접근하게 된다.
	tStudent.iKor = 100;

	//tStudent.strName = "adqwewq가나다라마바사";
	// 문자열을 배열에 넣어줄 때에는 단순 대입으로는 불가능하다.
	// strcpy_s 라는 함수를 이용해서 문자열을 복사해 주어야 한다.
	// 이 함수는 오른쪽에 있는 문자열을 왼쪽으로 복사해준다.
	// 마지막에 0(NULL)문자를 자동으로 넣어준다.
	// 한글은 하나당 2바이트(2의 길이로)
	strcpy_s(tStudent.strName, "가나다라 asdf");

	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	// strcat_s 함수는 문자열을 붙여주는 기능이다.
	// 오른쪽에 있는 문자열을 왼쪽에 붙여준다.
	// 마지막에 0(NULL)문자를 자동으로 넣어준다.
	strcat_s(tStudent.strName, " 문자열 붙이기");

	// strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고 다를 경우
	// 0이 아닌 값을 반환한다. (string compare)
	strcpy_s(tStudent.strName, "홍길동");

	cout << "비교할 이름을 입력하세요 : ";
	char	strName[NAME_SIZE] = {};
	cin >> strName;


	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "학생을 찾았습니다." << endl;
	}

	else
	{
		cout << "찾는 학생이 없습니다." << endl;
	}

	// 문자열의 끝은 항상 0(NULL)로 끝나야 한다.
	// 그런데 쓰레기값이 들어가있는 상태에서 아래처럼 각 배열 요소에 값을 넣어주게 되면 그 값이 출력되고
	// 넣어주지 않은 부분은 쓰레기값으로 그대로 출력된다.
	// 왜냐하면 출력될 때 문자열의 끝을 인식할 수 없기 때문이다.
	tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'b';
	tStudent.strName[2] = 0;
	

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}
