#include <stdio.h>

long GetFileSize(FILE * fp) {
	long fpos;
	long fsize;
	
	fpos = ftell(fp); // ���� ��ġ ������ ���� ���

	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, fpos, SEEK_SET); // ���� ��ġ ������ ���� ����
	
	return fsize;
}

int main() {
	FILE* fp = fopen("text.txt", "rt");
	char str[100];
	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("������ ũ��: %ld \n", GetFileSize(fp));

	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("������ ũ��: %d \n", GetFileSize(fp));

	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("������ ũ��: %d \n", GetFileSize(fp));
	return 0;
}