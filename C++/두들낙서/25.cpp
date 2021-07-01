// 배열과 포인터와의 관계
#include <cstdio>

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("arr의 값 : %d\n", arr);
	for (int i = 0; i < 10; i++) {
		printf("&arr[%d] = %d\n", i, &arr[i]);
		printf("arr + %d = %d\n", i, arr + i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		// arr + i = &arr[i]
		printf("%d ", *(arr + i));
	}
	printf("\n");

	for (int* ptr = arr; ptr < arr + 10; ptr++) {
		printf("%d ", *ptr);
	}
}