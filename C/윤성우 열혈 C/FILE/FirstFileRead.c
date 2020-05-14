#include <stdio.h>

int main() {
	int ch, i;
	FILE* fp = fopen("data.txt", "rt"); // 입력 스트림 형성
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	for (i = 0; i < 3; i++) {
		ch = fgetc(fp);
		printf("%c \n", ch);
	}
	fclose(fp);
	return 0;
}