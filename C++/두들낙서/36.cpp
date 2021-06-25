// 배열을 매개변수로 넘기는 방법 (1차원, 2차원 배열)

// call-by-value : 값만, 복사를 이용했기 때문에 따로 값을 변경해도 원본은 해치지 않음.
// call-by-reference : 참조, 주소를 이용해서 값 변경이 가능
#include <cstdio>

// int* arr와 같은 형태
// call-by-reference
void printArr(int arr[]) {
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}
}

// int (*arr)[3]와 같은 형태
// call-by-reference
void printArr2(int arr[][3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void func(int* arr) {
	for (int i = 0; i < 4; i++) {
		arr[i] *= 2; // *(arr + i) *= 2;
	}
}

int main() {
	int arr[4] = { 1,2,3,4 };
	printArr(arr);

	int arr2[2][3] = { {1,2,3}, {4,5,6} };
	printArr2(arr2);
}