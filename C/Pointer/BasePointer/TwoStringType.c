#include <stdio.h>

// 두 가지 형태의 문자열 표현을 기억하자.

int main() {
	char str1[] = "First String"; // 변수 형태의 문자열 (상수 형태의 포인터)
	char* str2 = "Second String"; // 상수 형태의 문자열 (변수 형태의 포인터)
	// 두 형태 모두 문자열 마지막에는 널문자가 포함된다. (문장의 끝을 표현하는)
	printf("%s, %s \n", str1, str2);

	str2 = "Third String"; // 가리키는 대상을 변경한다. (변수 형태의 포인터 이므로)
	printf("%s, %s \n", str1, str2);

	str1[0] = 'X'; // 문자열 변경한다.
	// str2[0] = 'X'; (상수 형태의 문자열은 변경할 수 없다)
	printf("%s, %s \n", str1, str2);
	return 0;
}