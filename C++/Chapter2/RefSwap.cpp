#include <iostream>
using namespace std;

//cpp에서는 주소 값을 이용한 Call-by-reference가 있고,
//참조자를 이용한 Call-by-reference가 있다.

//참조자를 통해서 swap을 이용한 경우
void SwapByRef2(int &ref1, int &ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main() {
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	return 0;
}