#include <stdio.h>
#include <stdlib.h>

/* 
	����ڷκ��� ������ �Է¹޴´�. (-1�� �Էµ� ������)
	���α׷� ������������ �Է¹��� ���� ���θ� ������� ����Ѵ�.
	�߿��� ���� ����ڰ� �� ���� ������ �Է����� �𸥴ٴµ� �ִ�.
*/
int main() {
	int arrlen = 5; // �ʱ� �迭�� ���̸� 5��� ����.
	int idx = 0;
	int i;
	int* arr = (int*)malloc(sizeof(int) * arrlen);

	while (1) {
		printf("���� �Է�(quit to -1): ");
		scanf("%d", &arr[idx]);

		if (arr[idx] == -1)
			break;

		if (arrlen == idx + 1) { // �迭�� Ȯ�强�� �˻��Ѵ�. (��ġ����)
			printf("�޸� Ȯ���Ѵ�.\n");
			arrlen += 3;
			arr = (int*)realloc(arr, sizeof(int) * arrlen);
		}
		idx++;
	}

	for (i = 0; i < idx; i++)
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}