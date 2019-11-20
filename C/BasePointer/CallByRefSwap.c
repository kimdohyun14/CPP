#include <stdio.h>

// Call-by-reference 형태
void Swap(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

// 주소 값을 전달하는 형태로 인자를 넘기게 되면 결과값의 변경된다.
int main() {
	int num1 = 10, num2 = 20;
	printf("변경되기 전 num1 : %d, num2 : %d \n", num1, num2);
	Swap(&num1, &num2);
	printf("변경된 후 num1 : %d, num2 : %d \n", num1, num2);
	return 0;
}