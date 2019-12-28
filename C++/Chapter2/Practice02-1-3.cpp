#include <iostream>
using namespace std;

void SwapPointer(int *(&pref1), int *(&pref2)) {
	/*
	int temp = *pref1;
	*pref1 = *pref2;
	*pref2 = temp;
	*/
	//다른 방법
	int * temp = pref1;
	pref1 = pref2;
	pref2 = temp;
}

int main() {
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	cout << "스왑되기 전 *ptr1 : " << (*ptr1) << " *ptr2 : " << (*ptr2) << endl;
	SwapPointer(ptr1, ptr2);
	cout << "스왑된 후 *ptr1 : " << *ptr1 << " *ptr2 : " << *ptr2 << endl;
	return 0;
}