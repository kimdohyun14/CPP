#include <stdio.h>

// ���Ͽ� ����� �����͸� �о��.

int main() {
	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt");
	if (fp == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	ch = fgetc(fp);
	printf("%c \n", ch);
	ch = fgetc(fp);
	printf("%c \n", ch);

	// fgets �Լ��� ȣ���� ���ؼ� �о� ���� ���ڿ��� ������ �ݵ�� \n���ڰ� �����ؾ� �Ѵ�.
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fgets(str, sizeof(str), fp);
	printf("%s", str);

	fclose(fp);
	return 0;
}