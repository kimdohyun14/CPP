#include <stdio.h>

int main() {
	// ������ �����ؼ� ����� �ۼ��ؼ� ���Ͽ� �����ϱ�.
	FILE* fp = fopen("mystory.txt", "wt");
	if (fp == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	puts("���Ͽ��� ����!");
	fputs("#�̸�: �赵�� \n", fp);
	fputs("#�ֹι�ȣ: 900208-1012589 \n", fp);
	fputs("#��ȭ��ȣ: 010-1111-2222 \n", fp);
	fclose(fp);
	return 0;
}