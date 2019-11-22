#include <stdio.h>

// Call-by-reference의 성공적 사례
// int형 포인터 변수를 대상으로 Swap함수
void SwapIntPtr(int** dp1, int** dp2) {
	int* temp = *dp1;
	*dp1 = *dp2;
	*dp2 = temp;
}

int main() {
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	printf("변경 전 *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);
	SwapIntPtr(&ptr1, &ptr2); // ptr1과 ptr2의 주소 값을 전달
	printf("변경 후 *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);
	return 0;
}