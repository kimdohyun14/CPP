#include <iostream>
// 자주 쓰이는 모듈러 연산의 예시이다.
// 기본적으로 % m 으로 진행하면 결과는 0 ~ m - 1 사이의 값으로 나오게 된다.
int main()
{
	using namespace std;
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "당신의 체중을 파운드 단위로 입력하세요. ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;  // 몫은 스톤으로
	int pounds = lbs % Lbs_per_stn; // 나머지는 파운드로
	cout << lbs << " 파운드는 " << stone
		<< " 스톤, " << pounds << " 파운드입니다.\n";
	return 0;
}