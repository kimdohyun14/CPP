#include <iostream>
using namespace std;
int main()
{
	int updates = 6;
	int* p_updates; // int* 형 (복합 데이터형, int형을 지시하는 포인터)

	// 포인터는 주소를 저장한다!
	p_updates = &updates; // p_updates가 int형을 지시한다.

	cout << "value : " << updates;
	cout << ", *p_value : " << *p_updates << endl;

	cout << "주소: " << &updates;
	cout << ", " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "변경된 value = " << updates << endl;
	return 0;
}