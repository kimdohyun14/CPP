#include <stdio.h>

int main() {
	int i, j;

	/* 2차원 배열 초기화 예시 1 */
	int arr1[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	/* 2차원 배열 초기화 예시 2 */
	int arr2[3][3] = {
		{1},
		{4,5},
	    {7,8,9}
	};

	/* 2차원 배열 초기화 예시 3 */
	int arr3[3][3] = { 1,2,3,4,5,6,7 };

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr1[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr3[i][j]);
		printf("\n");
	}
	printf("\n");


	// 추가적으로 2차원 배열은 배열의 세로길이만 생략이 가능하다.
	int arr4[][2] = { 1,2,3,4,5,6,7,8 };
	return 0;
 }