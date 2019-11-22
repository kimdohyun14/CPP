#include <stdio.h>

// 포인터를 대상으로 하는 증가 및 감소연산이 가능하다.

int main() {

	int* ptr1 = 0x0010;
	double* ptr2 = 0x0010;

	printf("Origin : %p, %p \n", ptr1, ptr2);

	// 중요한 건 ptr1, ptr2 자체의 값이 바뀌는 것이 아니다.
	printf("%p, %p \n", ptr1 + 1, ptr2 + 1); // 4증가 8증가
	printf("%p, %p \n", ptr1 + 2, ptr2 + 2); // 8증가 16증가

	// 이번에는 포인터 변수에 저장된 값 자체를 변경시키는 연산이다.
	printf("Origin : %p, %p \n", ptr1, ptr2);
	ptr1++; // 4증가
	ptr2++; // 8증가
	printf("%p, %p \n", ptr1, ptr2);
	return 0;
}