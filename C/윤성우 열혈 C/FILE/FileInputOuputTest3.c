#include <stdio.h>

int main() {
	// 생성한 파일에 저장된 정보 전체를 출력해보기.
	FILE* fp = fopen("mystory.txt", "rt");
	char str[100];
	int ch;
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	puts("파일오픈 성공!");

	// 문자 단위로 읽는 방법
	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	// 문자열 단위로 읽는 방법
	/*
	while (fgets(str, sizeof(str), fp) != NULL) {
		printf("%s", str);
	}
	*/
	fclose(fp);
	return 0;
}