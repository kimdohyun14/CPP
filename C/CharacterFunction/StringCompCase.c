#include <stdio.h>
#include <string.h>

// 문자열을 비교하는 함수 strcmp, strncmp

int main() {
	char str1[20];
	char str2[20];

	printf("문자열 입력 1 : "); scanf("%s", str1);
	printf("문자열 입력 2 : "); scanf("%s", str2);

	/*
		if(str1 == str2) // 주소 값을 비교하는 의미
	*/

	if (!strcmp(str1, str2)) // 문자열을 비교 (사전편찬 순으로)
		puts("두 문자열은 완벽히 동일하다. ");
	else {
		puts("두 문자열은 동일하지 않다. ");

		if (!strncmp(str1, str2, 3)) // 앞에서부터 3개의 문자가 동일하면 참
			puts("그러나 앞 세 글자는 동일하다.");
		else
			puts("이 역시 동일하지 않다. ");
	}

	return 0;
}