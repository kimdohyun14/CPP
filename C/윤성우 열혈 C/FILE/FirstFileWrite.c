#include <stdio.h>

int main() {
	FILE* fp = fopen("data.txt", "wt"); // 출력 스트림의 형성
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp); // 스트림의 종료
	return 0;
}