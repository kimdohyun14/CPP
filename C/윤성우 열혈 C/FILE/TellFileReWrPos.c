#include <stdio.h>

// ftell �Լ��� ���� ��ġ �������� ������ �ӽ÷� ������ �� �����ϴ�.

int main() {
	long fpos;
	int i;

	/* ���ϻ��� */
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	/* ���ϰ��� */
	fp = fopen("text.txt", "rt");

	for (i = 0; i < 4; i++) {
		putchar(fgetc(fp));
		fpos = ftell(fp); // ���� ���� ��ġ �������� ��ġ�� �� �� �ִ�.
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);
	return 0;
}