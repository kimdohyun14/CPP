#include <stdio.h>

int main() {
	// ������ �ۼ��� ���Ͽ� ������ �߰��ϱ�.
	FILE* fp = fopen("mystory.txt", "at");
	if (fp == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	puts("���Ͽ��� ����!");
	fputs("#��ܸԴ� ����: ¥���, ������ \n", fp);
	fputs("#���: �ڵ� \n", fp);
	fclose(fp);
	return 0;
}