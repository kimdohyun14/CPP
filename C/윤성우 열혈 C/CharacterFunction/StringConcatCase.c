#include <stdio.h>
#include <string.h>

// 문자열을 덧붙이는 함수 strcat, strncat

// strncpy 함수와 달리 strncat 함수는 문자열의 끝에 널 문자를 자동으로 삽입해준다.
int main() {
	char str1[20] = "First~";
	char str2[20] = "Second";

	char str3[20] = "Simple num: ";
	char str4[20] = "1234567890";

	// case 1
	strcat(str1, str2);
	puts(str1);

	// case 2
	strncat(str3, str4, 7); // str4 문자열 중 최대 7개를 str3에 덧붙이기.
	puts(str3);
	return 0;
}