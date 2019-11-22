#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[30];
	printf("정수 입력 : "); scanf("%s", str);
	printf("%d \n", atoi(str)); // 문자열 -> 정수 변환
	
	printf("실수 입력 : "); scanf("%s", str);
	printf("%g \n", atof(str)); // 문자열 -> 실수 변환
	return 0;
}