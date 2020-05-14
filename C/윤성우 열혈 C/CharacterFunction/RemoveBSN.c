#include <stdio.h>
#include <string.h>

void RemoveBSF(char str[]) {
	int len = strlen(str); // strlen : 문자열의 길이를 반환하는 함수
	str[len - 1] = 0;
}

int main() {
	char str[100];
	printf("문자열 입력 : ");
	fgets(str, sizeof(str), stdin);
	printf("길이: %d, 내용: %s \n", strlen(str), str);

	RemoveBSF(str);
	printf("길이: %d, 내용: %s \n", strlen(str), str);
	return 0;
}