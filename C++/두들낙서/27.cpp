// 2차원 배열과 배열 포인터
/*
	1. arr == &arr[0]
	2. *arr == arr[0]
	3. ptr + 1 == ptr에 sizeof(*ptr)을 더한값
*/
#include <cstdio>

int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };

	printf("%d\n", sizeof(arr)); // 24byte
	printf("%d\n", sizeof(arr[0])); // 12byte
	printf("%d\n", sizeof(arr[0][0])); // 4byte

	printf("%d\n", &arr);
	printf("%d\n", &arr[0]);
	printf("%d\n", &arr[0][0]);

	// 1. ptr[i] == arr[i]
	// 2. ptr[i][j] == arr[i][j]
	// 3. ptr == arr

	int(*ptr)[3] = arr;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}

	for (int(*row)[3] = arr; row < arr + 2; row++) {
		for (int* col = *row; col < *row + 3; col++) {
			printf("%d ", *col);
		}
		printf("\n");
	}

}