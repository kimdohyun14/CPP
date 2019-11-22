#include <stdio.h>

// 배열이름 기반의 포인터 연산
// 2차원 배열이름의 포인터 형은 가로의 길이에 따라 달라진다.

int main() {
	int arr1[3][2];
	int arr2[2][3];

	// 8씩 증가
	printf("arr1: %p \n", arr1);
	printf("arr1+1: %p \n", arr1 + 1);
	printf("arr1+2: %p \n\n", arr1 + 2);

	// 12씩 증가
	printf("arr2: %p \n", arr2);
	printf("arr2+1: %p \n", arr2 + 1);
	return 0;
}