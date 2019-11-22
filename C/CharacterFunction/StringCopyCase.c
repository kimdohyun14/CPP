#include <stdio.h>
#include <string.h>

// 문자열을 복사하는 함수들 strcpy, strncpy

int main() {
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	// case 1
	strcpy(str2, str1);
	puts(str2);

	// case 2
	// strncpy는 단순하게 문자열을 복사만 하지, 널 문자가 포함되어있는지 검사를 하지 않는다.
	strncpy(str3, str1, sizeof(str3)); 
	puts(str3);

	// case 3
	// 배열의 실제 길이보다 하나 작은 값을 전달해서 널 문자가 삽입될 공간을 마련한다.
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0; // 널 문자 삽입(아스키 코드 값 0)
	puts(str3);
	return 0;
}