// �迭 ����Ű��(�迭 ������)

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
	// �Ʒ��� ǥ���� ����������, �򰥸� �� �����Ƿ� ��������.
	for (int i = 0; i < 3; i++) {
		printf("%d ", i[ptr]);
	}
	printf("\n");

	/*
		1. ptr == &ptr[0]
		2. *ptr == ptr[0]
		3. ptr + 1 == ptr�� sizeof(*ptr)�� ���� ��
	*/

	int arr2[3] = { 1,2,3 };
	printf("arr2 = %d\n", arr2);
	printf("arr2 + 1  = %d\n", arr2 + 1);

	printf("&arr2 = %d\n", &arr2);
	printf("&arr2 + 1 = %d\n", &arr2 + 1); // 3���� ���ؼ�, sizeof(*arr2) = 12��ŭ ��������.

	int(*ptr_arr)[3]; // ���� 3�� int�� �迭�� ����Ű�� �����͸� ���� (�迭 ������)
	ptr_arr = &arr;

	for (int i = 0; i < 3; i++) {
		printf("%d ", (*ptr_arr)[i]);
	}
	printf("\n");
}