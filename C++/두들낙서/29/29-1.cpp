/*
100�� ������ ������ �Է¹޾�
ù �ٿ� ¦�� ��° ���ڵ��� ������� ����ϰ�,
���� �ٿ� Ȧ�� ��° ���ڵ��� ������� ����ϴ� ���α׷� �ۼ�

�Է� ��
7
3 1 4 1 5 9 2

��� ��
1 1 9
3 4 5 2
*/

#include <cstdio>

int main() {
	int n;
	int arr[105];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < n; i += 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i += 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}