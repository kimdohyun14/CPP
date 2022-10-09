/*
각 타입 별 읽는 방법

input : 38.5 19.2

char ch;
cin >> ch;
첫 문자는 3, 이 숫자에 해당하는 문자 코드가 대입된다.
입력 구문이 끝난 후에, 입력 큐에 있는 다음 문자는 숫자 8이다.

int n;
cin >> n;
숫자 3과 숫자 8을 읽고 다음에 읽을 문자로 소수점을 입력 큐에 남겨둔다.

double x;
cin >> x;
부동소주점 수의 일부가 아닌 첫 문자가 나올 때까지 읽는다.
숫자3, 숫자 8, 소수점. 문자, 숫자 5를 읽고, 다음에 읽을 문자로 빈칸을 입력 큐에 남겨둔다.

char word[50];
cin >> word;
빈칸 문자가 나올 때까지 읽는다.
숫자3, 숫자8, 소수점 문자. , 숫자 5를 읽고, 다음에 읽을 문자로 빈칸을 입력 큐에 남겨둔다.
문자 코드들을 배열 word에 저장하고, 끝에 널 문자를 추가한다.

char word[50];
cin.getline(word, 50);
개행 문자가 나올 때까지 읽는다.
모든 숫자를 저장하고, 끝에 널 문자를 추가한다.
단, 개행 문자는 폐기한다!


#### 파일 출력을 사용하는 기본 절차 ####
1. fstream 헤더 파일을 포함
2. ofstream 객체를 생성
3. ofstream 객체를 파일에 연결
4. ofstream 객체를 cout과 동일한 방식으로 사용
*/

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; // 출력을 위한 객체 생성
	outFile.open("carinfo.txt"); // 파일에 연결

	cout << "자동차 메이커와 차종을 입력하세요: ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하세요 : ";
	cin >> year;
	cout << "구입 가격을 입력하세요: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout으로 스크린에 정보를 디스플레이

	cout << fixed;
	cout.precision(2); // 정밀도 2사용
	cout.setf(ios_base::showpoint);
	cout << "메이커와 차종: " << automobile << endl;
	cout << "연식: " << year << endl;
	cout << "구입 가격 $" << a_price << endl;
	cout << "현재 가격 $" << d_price << endl;

	// cout 대신 outFile을 사용하여 똑같은 일을 처리할 수 있다.
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종: " << automobile << endl;
	outFile << "연식: " << year << endl;
	outFile << "구입 가격 $" << a_price << endl;
	outFile << "현재 가격 $" << d_price << endl;

	outFile.close(); // 파일 처리 종료
	return 0;
}