#include <stdio.h>

// ������ �����ؼ� ���ڿ� ���ڿ��� �����غ���.

int main() {
	FILE* fp = fopen("simple.txt", "wt");
	if (fp == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp); // ���ڿ��� ���๮�ڰ� ���ԵǾ� �����Ƿ� �ݵ�� �ؽ�Ʈ ���� ������ �����ؾ� �Ѵ�.
	fputs("Your name is Yoon \n", fp);
	fclose(fp);
	return 0;
}