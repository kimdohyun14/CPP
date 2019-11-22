#include <stdio.h>

// 인자전달의 기본방식은 값의 복사이며,
// 배열의 경우는 배열의 주소 값을 전달하는 방식으로 함수를 작성한다.
// 또한, 주소 값만 알면 해당 메모리 공간에 얼마든지 접근이 가능하다.

void ShowArrayElem(int* param, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}

int main() {
	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };
	ShowArrayElem(arr1, sizeof(arr1) / sizeof(int));
	ShowArrayElem(arr2, sizeof(arr2) / sizeof(int));
	return 0;
}