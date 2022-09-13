#include <iostream>
using namespace std;
int main()
{
	int chest = 42;   // 10진 정수형 상수
	int waist = 0x42; // 16진 정수형 상수
	int inseam = 042; // 8진 정수형 상수
	
	// 기본적으로 cout은 정수를 10진수로 출력한다.
	cout << "손님의 몸매는 다음과 같습니다.\n";
	cout << "가슴 둘레 : " << chest << endl;
	cout << "허리 둘레 : " << waist << endl;  // 16 x 4 + 2 = 66
	cout << "인심 길리 : " << inseam << endl; // 8 x 4 + 2 = 34
	return 0;
}