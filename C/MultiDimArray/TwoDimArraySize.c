#include <stdio.h>

// ������ �迭�� 2���� �̻��� �迭�� �ǹ��Ѵ�.
// sizeof �����ڴ� 2���� �迭�� ũ�⸦ ��Ȯ�ϰ� ����Ѵ�.

int main() {
	int arr1[3][4];
	int arr2[7][9];
	printf("���� 3, ���� 4 : %d \n", sizeof(arr1));
	printf("���� 7, ���� 9 : %d \n", sizeof(arr2));
	return 0;
}