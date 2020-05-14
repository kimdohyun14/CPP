#include <stdio.h>

// 파일복사 프로그램

int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	int ch;

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	// 파일의 내용을 한 문자씩 복사한다.
	// fgetc 함수는 파일의 끝에 도달을 한 경우 EOF를 반환하는데,
	// 오류가 발생하게 될 때에도 EOF를 반환하게 된다.
	while ((ch = fgetc(src)) != EOF)
		fputc(ch, des);

	// 따라서 feof 함수의 호출을 통해서 EOF의 반환이 확실한지 확인한다.
	if (feof(src) != 0)
		puts("파일복사 완료");
	else
		puts("파일복사 실패");

	fclose(src);
	fclose(des);
	return 0;
}