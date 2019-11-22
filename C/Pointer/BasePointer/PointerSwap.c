#include <stdio.h>

// 포인터를 서로 스왑하는 과정

int main() {
	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* temp;

	(*ptr1) += 10;
	(*ptr2) -= 10;

	printf("변경되기 전\n");
	printf("%d %d \n", *ptr1, *ptr2);

	// Swap 과정
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;

	printf("변경된 후\n");
	printf("%d %d \n", *ptr1, *ptr2);
	return 0;
}