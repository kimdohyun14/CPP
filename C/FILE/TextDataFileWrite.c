#include <stdio.h>

// 파일을 생성해서 문자와 문자열을 저장해보기.

int main() {
	FILE* fp = fopen("simple.txt", "wt");
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Hong \n", fp); // 문자열에 개행문자가 포함되어 있으므로 반드시 텍스트 모드로 파일을 개방해야 한다.
	fputs("Your name is Yoon \n", fp);
	fclose(fp);
	return 0;
}