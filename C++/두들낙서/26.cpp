// 배열 가리키기(배열 포인터)

#include <cstdio>

int main() {
	int arr[3] = { 1,2,3 };
	int* ptr = arr;

	for (int i = 0; i < 3; i++) {
		printf("%d ", *(ptr + i));
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");
	
	// arr[i] == *(arr + i) == *(ptr + i) == *(i + ptr) == i[ptr]
	// 아래의 표현은 가능하지만, 헷갈릴 수 있으므로 쓰지말자.
	for (int i = 0; i < 3; i++) {
		printf("%d ", i[ptr]);
	}
	printf("\n");

	/*
		1. ptr == &ptr[0]
		2. *ptr == ptr[0]
		3. ptr + 1 == ptr에 sizeof(*ptr)을 더한 값
	*/

	int arr2[3] = { 1,2,3 };
	printf("arr2 = %d\n", arr2);
	printf("arr2 + 1  = %d\n", arr2 + 1);

	printf("&arr2 = %d\n", &arr2);
	printf("&arr2 + 1 = %d\n", &arr2 + 1); // 3번에 의해서, sizeof(*arr2) = 12만큼 더해진다.

	int(*ptr_arr)[3]; // 길이 3인 int형 배열을 가리키는 포인터를 선언 (배열 포인터)
	ptr_arr = &arr;

	for (int i = 0; i < 3; i++) {
		printf("%d ", (*ptr_arr)[i]);
	}
	printf("\n");
}