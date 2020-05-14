#include <stdio.h>

int main() {
	// 파일을 생성해서 양식을 작성해서 파일에 저장하기.
	FILE* fp = fopen("mystory.txt", "wt");
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	puts("파일오픈 성공!");
	fputs("#이름: 김도현 \n", fp);
	fputs("#주민번호: 900208-1012589 \n", fp);
	fputs("#전화번호: 010-1111-2222 \n", fp);
	fclose(fp);
	return 0;
}