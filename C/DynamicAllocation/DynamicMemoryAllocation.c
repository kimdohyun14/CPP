#include <stdio.h>
#include <stdlib.h>

// �����Ҵ翡 ���ؼ� �˾ƺ���.

int main() {
	int* ptr1 = (int*)malloc(sizeof(int));     // int�� ������ �ּ� ���� int�� �����ͷ� ����
	int* ptr2 = (int*)malloc(sizeof(int) * 7); // 1���� �迭�� �ּ� �� ���� int�� ������
	int i;

	if (ptr1 == NULL) {
		puts("ptr1 �޸� �Ҵ� ����");
		return -1;
	}

	if (ptr2 == NULL) {
		puts("ptr2 �޸� �Ҵ� ����");
		return -1;
	}
		

	*ptr1 = 20;
	for (i = 0; i < 7; i++)
		ptr2[i] = i + 1;

	printf("%d \n", *ptr1);
	for (i = 0; i < 7; i++)
		printf("%d ", ptr2[i]);

	free(ptr1); // �޸� �Ҵ� ����
	free(ptr2); // �޸� �Ҵ� ����
	return 0;
}