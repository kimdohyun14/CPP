#include <stdio.h>

// �迭�� ���������� NULL�� ���Եȴٴ� ���� �� �� �ִ�.
int main(int argc, char* argv[]) {
	int i = 0;
	printf("���޵� ���ڿ��� �� : %d \n", argc);

	while (argv[i] != NULL) {
		printf("%d��° ���ڿ�: %s \n", i + 1, argv[i]);
		i++;
	}
	return 0;
}