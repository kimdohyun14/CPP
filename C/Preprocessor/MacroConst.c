#include <stdio.h>

// #define:Object-like macro (������ �ǹ̸� ���� ����̳� �繰)
#define NAME "�赵��"
#define AGE	24
#define PRINT_ADDR puts("�ּ�: �����~ \n");

int main() {
	printf("�̸�: %s \n", NAME);
	printf("����: %d \n", AGE);
	PRINT_ADDR;
	return 0;
}