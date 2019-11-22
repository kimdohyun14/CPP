#include <stdio.h>

// 3차원 배열 역시 sizeof 연산자를 이용해서 배열의 크기가 나온다.

int main() {
	int arr1[2][3][4]; // 높이 2, 세로 3, 가로 4인 int형 3차원 배열
	double arr2[5][5][5];
	printf("높이 2, 세로 3, 가로 4인 int형 배열 : %d \n", sizeof(arr1));
	printf("높이 5, 세로 5, 가로 5인 double형 배열 : %d \n", sizeof(arr2));
	return 0;
}