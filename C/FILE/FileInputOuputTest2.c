#include <stdio.h>

int main() {
	// 기존에 작성한 파일에 데이터 추가하기.
	FILE* fp = fopen("mystory.txt", "at");
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	puts("파일오픈 성공!");
	fputs("#즐겨먹는 음식: 짜장면, 탕수육 \n", fp);
	fputs("#취미: 코딩 \n", fp);
	fclose(fp);
	return 0;
}