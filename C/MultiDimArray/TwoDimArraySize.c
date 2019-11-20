#include <stdio.h>

// 다차원 배열은 2차원 이상의 배열을 의미한다.
// sizeof 연산자는 2차원 배열의 크기를 정확하게 계산한다.

int main() {
	int arr1[3][4];
	int arr2[7][9];
	printf("세로 3, 가로 4 : %d \n", sizeof(arr1));
	printf("세로 7, 가로 9 : %d \n", sizeof(arr2));
	return 0;
}