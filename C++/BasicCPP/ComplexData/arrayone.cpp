#include <iostream>
using namespace std;
int main()
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 5;

	int yamcosts[3] = { 20, 30, 80 };
	cout << sizeof yams << endl;
	cout << sizeof yams[0] << endl;

	// 부분적 배열 초기화
	// 컴파일러가 나머지 원소들은 모두 0으로 초기화
	float hotelTips[5] = { 5.0, 2.5 };
	cout << hotelTips[2] << endl;

	// 배열의 모든 원소를 0으로 설정하고 싶을 때
	long totals[500] = { 0 };
	cout << totals[488] << endl;

	// 배열의 첫번째 원소만 1, 나머지는 모두 0으로 초기화
	long others[500] = { 1 };
	cout << others[412] << endl;

	// 컴파일러가 배열 원소의 개수를 결정하도록 위임하는 것은 좋지 않다.
	// => 프로그래머가 생각한 개수랑 컴파일러가 결정한 개수가 다를 수 있으므로
	// 다만 문자열같이 char형 배열은 오히려 안전하게 사용할 수 있다.
	char things[] = { 'a', 'b', 'c', 'z', '\0'};
	cout << "things 의 문자열 길이 : " << sizeof things / sizeof (char) << endl;
	cout << things << endl;

	return 0;
}