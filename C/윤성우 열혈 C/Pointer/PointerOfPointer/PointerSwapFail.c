#include <stdio.h>

// Call-by-reference를 정의했지만, swap이 되지 않는 경우
void SwapIntPtr(int* p1, int* p2) {
	// p1과 p2는 ptr1과 ptr2와의 별개로 동작하기 때문
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}

int main() {
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	printf("변경 전 *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);
	SwapIntPtr(ptr1, ptr2);
	printf("변경 후 *ptr1 : %d , *ptr2 : %d \n", *ptr1, *ptr2);

	check(ptr1);
	printf("%d \n", *ptr1);
	return 0;
}