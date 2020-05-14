#include <stdio.h>

// 2차원 배열의 포인터 형을 결정짓는 방법

int main() {
	int arr1[2][2] = {
		{1,2},{3,4}
	};
	int arr2[3][2] = {
		{1,2},{3,4},{5,6}
	};
	int arr3[4][2] = {
		{1,2},{3,4},{5,6},{7,8}
	};

	// arr1, arr2, arr3 모두 int형 2차원 배열이면서, 가로의 길이가 동일하므로
	// 배열이름의 포인터 형은 모두 같게 된다.
	int(*ptr)[2]; // <- 배열 포인터를 의미한다.
	int i;

	ptr = arr1;
	printf("*** Show 2,2 arr1 ** \n");
	for (i = 0; i < 2; i++)
		printf("%d %d \n", ptr[i][0], ptr[i][1]);

	ptr = arr2;
	printf("*** Show 3,2 arr2 ** \n");
	for (i = 0; i < 3; i++)
		printf("%d %d \n", ptr[i][0], ptr[i][1]);

	ptr = arr3;
	printf("*** Show 4,2 arr3 ** \n");
	for (i = 0; i < 4; i++)
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	return 0;
}