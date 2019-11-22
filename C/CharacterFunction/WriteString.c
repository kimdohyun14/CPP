#include <stdio.h>

// 문자열 출력 함수 puts, fputs

// 차이점
// puts 함수가 호출되면 문자열 출력 후 자동으로 개행됨
// fputs함수가 호출되면 문자열 출력 후 자동으로 개행되지 않는다.

int main() {
	char* str = "Simple String"; // 상수 형태의 문자열

	printf("1. puts test ------ \n");
	puts(str);
	puts("So Simple String");

	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");
	fputs("So Simple String", stdout); printf("\n");

	printf("3. end of main ---- \n");
	return 0;
}