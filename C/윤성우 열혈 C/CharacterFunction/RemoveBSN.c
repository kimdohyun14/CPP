#include <stdio.h>
#include <string.h>

void RemoveBSF(char str[]) {
	int len = strlen(str); // strlen : ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
	str[len - 1] = 0;
}

int main() {
	char str[100];
	printf("���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin);
	printf("����: %d, ����: %s \n", strlen(str), str);

	RemoveBSF(str);
	printf("����: %d, ����: %s \n", strlen(str), str);
	return 0;
}