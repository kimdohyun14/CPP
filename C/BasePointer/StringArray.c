#include <stdio.h>

// 문자열을 저장하는 포인터 배열에 대해서 보자.

int main() {
	char* strArr[3] = { "First", "Second", "Third" }; // 상수 형태의 문자열을 저장한다.
	printf("%s \n", strArr[0]); // strArr[0] -> First\n 문자열의 첫 번째 문자의 주소 값을 이용해서 출력
	printf("%s \n", strArr[1]); // strArr[1] -> Second\n 문자열의 첫 번째 문자의 주소 값을 이용해서 출력
	printf("%s \n", strArr[2]); // strArr[2] -> Third\n 문자열의 첫 번째 문자의 주소 값을 이용해서 출력
	return 0;
}