#include <stdio.h>
#include <stdlib.h>

// 동적할당에 대해서 알아보자.

int main() {
	int* ptr1 = (int*)malloc(sizeof(int));     // int형 변수의 주소 값은 int형 포인터로 저장
	int* ptr2 = (int*)malloc(sizeof(int) * 7); // 1차원 배열의 주소 값 역시 int형 포인터
	int i;

	if (ptr1 == NULL) {
		puts("ptr1 메모리 할당 실패");
		return -1;
	}

	if (ptr2 == NULL) {
		puts("ptr2 메모리 할당 실패");
		return -1;
	}
		

	*ptr1 = 20;
	for (i = 0; i < 7; i++)
		ptr2[i] = i + 1;

	printf("%d \n", *ptr1);
	for (i = 0; i < 7; i++)
		printf("%d ", ptr2[i]);

	free(ptr1); // 메모리 할당 해제
	free(ptr2); // 메모리 할당 해제
	return 0;
}