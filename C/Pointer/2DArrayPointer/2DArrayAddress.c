#include <stdio.h>

// 2���� �迭�̸��� ����Ű�� �͵�

int main() {
	int arr2d[3][3];

	// 1���� ���� �ּ�
	printf("%d \n", arr2d);
	printf("%d \n", arr2d[0]);
	printf("%d \n\n", &arr2d[0][0]);

	// 2��
	printf("%d \n", arr2d[1]);
	printf("%d \n\n", &arr2d[1][0]);

	// 3��
	printf("%d \n", arr2d[2]);
	printf("%d \n\n", &arr2d[2][0]);

	// �߿��� ����
	// arr2d�� ù ��° ��Ҹ� ����Ų��. ���ÿ� �迭 ��ü�� �ǹ�
	// arr2d[1]�� ù ��° ��Ҹ� ����Ų��. �׷��� 1�ุ�� �ǹ�
	printf("sizeof(arr2d) : %d \n", sizeof(arr2d));
	printf("sizeof(arr2d[0]) : %d \n", sizeof(arr2d[0]));
	printf("sizeof(arr2d[1]) : %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]) : %d \n", sizeof(arr2d[2]));
	return 0;
}