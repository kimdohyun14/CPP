// �迭�� �Ű������� �ѱ�� ��� (1����, 2���� �迭)

// call-by-value : ����, ���縦 �̿��߱� ������ ���� ���� �����ص� ������ ��ġ�� ����.
// call-by-reference : ����, �ּҸ� �̿��ؼ� �� ������ ����
#include <cstdio>

// int* arr�� ���� ����
// call-by-reference
void printArr(int arr[]) {
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}
}

// int (*arr)[3]�� ���� ����
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