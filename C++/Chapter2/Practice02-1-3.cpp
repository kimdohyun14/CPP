#include <iostream>
using namespace std;

void SwapPointer(int *(&pref1), int *(&pref2)) {
	/*
	int temp = *pref1;
	*pref1 = *pref2;
	*pref2 = temp;
	*/
	//�ٸ� ���
	int * temp = pref1;
	pref1 = pref2;
	pref2 = temp;
}

int main() {
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	cout << "���ҵǱ� �� *ptr1 : " << (*ptr1) << " *ptr2 : " << (*ptr2) << endl;
	SwapPointer(ptr1, ptr2);
	cout << "���ҵ� �� *ptr1 : " << *ptr1 << " *ptr2 : " << *ptr2 << endl;
	return 0;
}