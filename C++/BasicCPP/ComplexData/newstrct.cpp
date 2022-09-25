#include <iostream>
using namespace std;

struct inflatable
{
	char name[20];
	float volumn;
	double price;
	char tip[30];
};

int main()
{
	// ->, . 의 차이
	inflatable* ps = new inflatable;
	cout << "모형풍선의 이름을 입력하세요.";
	cin.get(ps->name, 20);
	cout << "부피를 세제곱 피트 단위로 입력하세요.";
	cin >> (*ps).volumn;
	cout << "가격을 달러 단위로 입력하세요.";
	cin >> ps->price;
	cout << "팁을 입력하세요.";
	cin.get(); // 항상 숫자 입력 다음에는 \n 개행을 버려주고 입력을 받자. (입력 버퍼 비우기)
	cin.get(ps->tip, 30);

	cout << "이름: " << ps->name << endl;
	cout << "부피: " << (*ps).volumn << " cubic feet\n";
	cout << "가격: " << ps->price << endl;
	cout << "팁: " << ps->tip << endl;
	delete ps;
	return 0;
}