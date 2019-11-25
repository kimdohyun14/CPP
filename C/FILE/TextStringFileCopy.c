#include <stdio.h>

// ���ڿ� ������ ���縦 ����

int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	// fgets �Լ��� ������ ���� �����ؼ� �� �̻� ���� �����Ͱ� �������� �ʰų�
	// ������ �߻��ϴ� ��쿡 NULL�� ��ȯ�Ѵ�.
	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);


	// ���������� ���Ϻ����� ������ Ȯ���ϱ� ���ؼ� feof�Լ��� ȣ���Ѵ�.
	if (feof(src) != 0)
		puts("���Ϻ��� �Ϸ�");
	else
		puts("���Ϻ��� ����");

	fclose(src);
	fclose(des);
	return 0;
}