#include <stdio.h>

// ���ڿ� ��� �Լ� puts, fputs

// ������
// puts �Լ��� ȣ��Ǹ� ���ڿ� ��� �� �ڵ����� �����
// fputs�Լ��� ȣ��Ǹ� ���ڿ� ��� �� �ڵ����� ������� �ʴ´�.

int main() {
	char* str = "Simple String"; // ��� ������ ���ڿ�

	printf("1. puts test ------ \n");
	puts(str);
	puts("So Simple String");

	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");
	fputs("So Simple String", stdout); printf("\n");

	printf("3. end of main ---- \n");
	return 0;
}