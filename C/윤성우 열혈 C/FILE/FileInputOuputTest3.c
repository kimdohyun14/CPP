#include <stdio.h>

int main() {
	// ������ ���Ͽ� ����� ���� ��ü�� ����غ���.
	FILE* fp = fopen("mystory.txt", "rt");
	char str[100];
	int ch;
	if (fp == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	puts("���Ͽ��� ����!");

	// ���� ������ �д� ���
	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	// ���ڿ� ������ �д� ���
	/*
	while (fgets(str, sizeof(str), fp) != NULL) {
		printf("%s", str);
	}
	*/
	fclose(fp);
	return 0;
}