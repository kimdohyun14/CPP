#include <iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "몸매는 다음과 같습니다.\n";
	cout << "가슴 둘레 : " << chest << endl;
	cout << hex; // 진법을 바꾸는 조정자 (std 이름공간안에 있다.)
	cout << "허리 둘레 : " << waist << endl;
	cout << oct; // 진법을 바꾸는 조정자
	cout << "인심 길이 : " << inseam << endl;
	return 0;
}