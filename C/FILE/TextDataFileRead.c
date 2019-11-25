#include <stdio.h>

// 파일에 저장된 데이터를 읽어보자.

int main() {
	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt");
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	ch = fgetc(fp);
	printf("%c \n", ch);
	ch = fgetc(fp);
	printf("%c \n", ch);

	// fgets 함수의 호출을 통해서 읽어 들일 문자열의 끝에는 반드시 \n문자가 존재해야 한다.
	fgets(str, sizeof(str), fp);
	printf("%s", str);
	fgets(str, sizeof(str), fp);
	printf("%s", str);

	fclose(fp);
	return 0;
}