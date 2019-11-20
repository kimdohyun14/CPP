#include <stdio.h>

// 함수 내에서는 인자로 전달된 배열의 길이를 계산할 수 없기 때문에
// 함수를 호출할 때 미리 배열의 길이를 계산해서 인자로 넘겨줘야한다.
void ShowArrayElem(int* param, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}

// 배열의 주소 값을 이용해서 해당 메모리 공간에 접근해서 데이터를 수정한다.
// 이는 배열의 주소 값만 알고있다면 어디서든 배열에 접근해서 저장된 값을 참조하고 변경가능하다.
void AddArrayElem(int* param, int len, int add) {
	int i;
	for (i = 0; i < len; i++)
		param[i] += add;
}

int main() {
	int arr[3] = { 1,2,3 };
	AddArrayElem(arr, sizeof(arr) / sizeof(int), 1);
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));
	return 0;
}