#include <stdio.h>

// 문자열 입력 함수 gets, fgets

// 추가적으로 scanf함수는 공백이 포함된 형태의 문자열을 받는데 제한이 있지만
// 문자열 입력 함수는 공백을 포함하는 문자열도 입력 받을 수 있다.

// 문자열을 입력 받게 되면 문자열의 끝에 항상 자동으로 널 문자가 추가된다.

// fgets 함수는 \n을 만날 때까지 문자열을 읽어 들인다. 그래서 공백문자도 읽을 수 있는 것이다.

int main() {
	char str[7];
	int i;

	/*
		gets(str); // 미리 마련해 놓은 배열을 넘어버리게 되면 error
	*/

	for (i = 0; i < 3; i++) {
		fgets(str, sizeof(str), stdin); // 딱 sizeof(str)의 길이만큼만 저장
		printf("Read %d: %s \n", i + 1, str);
	}
	return 0;
}