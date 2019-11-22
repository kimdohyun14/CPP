#include <stdio.h>

// 문자 입출력
// putchar, fputc 문자 출력 함수
// getchar, fgetc 문자 입력 함수

int main() {
	int ch1, ch2;

	ch1 = getchar(); // 문자 입력
	ch2 = fgetc(stdin); // 엔터 키 입력

	putchar(ch1); // 문자 출력
	fputc(ch2, stdout); // 엔터 키 출력
	return 0;
}

// 엔터 키도 하나의 문자이며,
// 아스키 코드 값이 10인 '\n'으로 표현되는 문자이다.
// 따라서 위의 코드는 두 개의 문자가 입력되고, 출력되는 코드이다.

// printf함수와 scanf함수를 사용해도 되나, 상대적으로 연산이 많다.
// 따라서 단순히 하나의 문자를 입출력하는 경우는 위의 함수를 사용하는 것이 좋다.