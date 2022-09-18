#include <iostream>
using namespace std;

int main()
{
	int donuts = 6;
	double cups = 4.5;

	// 주소 연산자 &를 변수 앞에 붙이면 그 변수의 주소를 알 수 있다.
	cout << "donuts의 값 = " << donuts;
	cout << ", donuts의 주소 = " << &donuts << endl;

	cout << "cups의 값 = " << cups;
	cout << ", cups의 주소 = " << &cups << endl;
	return 0;
}