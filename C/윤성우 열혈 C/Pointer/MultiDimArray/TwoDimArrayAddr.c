#include <stdio.h>

// 2차원 배열 역시 메모리상 구조는 1차원적 구조를 띄고 있다.
// 이는 2차원 배열도 메모리상에는 1차원의 형태로 존재하는 것을 의미한다.
int main() {
	int arr[3][2];
	int i, j;
	for (i = 0; i < 3; i++) 
		for (j = 0; j < 2; j++)
			printf("%p \n", &arr[i][j]);
	return 0;
}