#include <stdio.h>
#define STRING_JOB(A, B) #A "�� ������ " #B "�Դϴ�."

// ���ڿ� ������ ��ũ���� �Ű����� ġȯ�� #�����ڸ� �̿��ϴ� ���̴�.

int main() {
	printf("%s \n", STRING_JOB(�赵��, ���α׷���));
	printf("%s \n", STRING_JOB(��ź�ҳ��, ���̵�));
	return 0;
}