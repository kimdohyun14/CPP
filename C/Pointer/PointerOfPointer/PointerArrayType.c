#include <stdio.h>

int main() {
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	// ptrArr의 배열 이름은 int형 더블 포인터라는 의미
	int* ptrArr[] = { ptr1, ptr2, ptr3 }; // 길이가 3인 int형 포인터 배열 ptrArr (더블 포인터)
	int** dptr = ptrArr; // 두 포인터형이 일치하므로 대입연산이 허용된다.

	printf("%d %d %d \n", *(ptrArr[0]), *ptrArr[1], *ptrArr[2]);
	printf("%d %d %d \n", *(dptr[0]), *dptr[1], *dptr[2]);
	return 0;
}