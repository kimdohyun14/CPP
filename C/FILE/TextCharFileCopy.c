#include <stdio.h>

// ���Ϻ��� ���α׷�

int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	int ch;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	// ������ ������ �� ���ھ� �����Ѵ�.
	// fgetc �Լ��� ������ ���� ������ �� ��� EOF�� ��ȯ�ϴµ�,
	// ������ �߻��ϰ� �� ������ EOF�� ��ȯ�ϰ� �ȴ�.
	while ((ch = fgetc(src)) != EOF)
		fputc(ch, des);

	// ���� feof �Լ��� ȣ���� ���ؼ� EOF�� ��ȯ�� Ȯ������ Ȯ���Ѵ�.
	if (feof(src) != 0)
		puts("���Ϻ��� �Ϸ�");
	else
		puts("���Ϻ��� ����");

	fclose(src);
	fclose(des);
	return 0;
}