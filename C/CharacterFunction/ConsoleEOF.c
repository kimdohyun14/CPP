#include <stdio.h>

int main() {
	int ch;

	while (1) {
		ch = getchar(); // 문자 입력
		if (ch == EOF) // EOF (End of File) 파일의 끝을 표현
			break;
		putchar(ch);  // 문자 출력
	}
	return 0;
}

// 무한 루프 탈출 CTRL + Z