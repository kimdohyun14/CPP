#include <iostream>
#define ZERO 0
#include <climits>

// 오버플로우와 언더플로우의 전형적인 예시
// 표현할 수 있는 한계를 벗어나면, 그 표현 범위의 반대편에서부터 다시 시작하게 된다.
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;       // 음수 표현이 가능하다.
	unsigned short Insuk = Dohee; // 음수를 표현할 수 없다.

	cout << "도희 계좌 : " << Dohee << ", ";
	cout << "인숙 계좌 : " << Insuk << endl;
	cout << "각 계좌에 1원씩 추가 입금 진행" << endl << endl;

	Dohee += 1; // 오버플로우 발생!
	Insuk += 1;
	cout << "도희 계좌 : " << Dohee << ", ";
	cout << "인숙 계좌 : " << Insuk << endl << endl;

	cout << "모두 값을 0으로 되돌린 후 각 계좌에서 1원씩 차감 진행" << endl;

	Dohee = ZERO;
	Insuk = ZERO;
	cout << "도희 계좌 : " << Dohee << ", ";
	cout << "인숙 계좌 : " << Insuk << endl;

	Dohee -= 1;
	Insuk -= 1; // 언더플로우 발생!
	cout << "도희 계좌 : " << Dohee << ", ";
	cout << "인숙 계좌 : " << Insuk << endl;
	return 0;
}