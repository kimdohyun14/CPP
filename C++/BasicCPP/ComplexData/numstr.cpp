#include <iostream>
using namespace std;

// get(), getlien() 응용편!
// 특히 문자열과 수치 입력을 혼합할 때 주의해야 한다.
int main()
{
	cout << "지금 사시는 아파트에 언제 입주하셨나요?\n";
	int year;
	(cin >> year).get();
	cout << "사시는 도시를 말씀해 주시겠습니까?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "아파트 입주 연도 : " << year << endl;
	cout << "도시 : " << address << endl;
	cout << "등록이 완료되었습니다!\n";
	return 0;
}