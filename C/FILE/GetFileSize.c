#include <stdio.h>

long GetFileSize(FILE * fp) {
	long fpos;
	long fsize;
	
	fpos = ftell(fp); // 파일 위치 지시자 정보 백업

	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, fpos, SEEK_SET); // 파일 위치 지시자 정보 복구
	
	return fsize;
}

int main() {
	FILE* fp = fopen("text.txt", "rt");
	char str[100];
	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("파일의 크기: %ld \n", GetFileSize(fp));

	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("파일의 크기: %d \n", GetFileSize(fp));

	fgets(str, sizeof(str), fp);
	fputs(str, stdout);
	printf("파일의 크기: %d \n", GetFileSize(fp));
	return 0;
}