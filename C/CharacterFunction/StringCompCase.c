#include <stdio.h>
#include <string.h>

// ���ڿ��� ���ϴ� �Լ� strcmp, strncmp

int main() {
	char str1[20];
	char str2[20];

	printf("���ڿ� �Է� 1 : "); scanf("%s", str1);
	printf("���ڿ� �Է� 2 : "); scanf("%s", str2);

	/*
		if(str1 == str2) // �ּ� ���� ���ϴ� �ǹ�
	*/

	if (!strcmp(str1, str2)) // ���ڿ��� �� (�������� ������)
		puts("�� ���ڿ��� �Ϻ��� �����ϴ�. ");
	else {
		puts("�� ���ڿ��� �������� �ʴ�. ");

		if (!strncmp(str1, str2, 3)) // �տ������� 3���� ���ڰ� �����ϸ� ��
			puts("�׷��� �� �� ���ڴ� �����ϴ�.");
		else
			puts("�� ���� �������� �ʴ�. ");
	}

	return 0;
}