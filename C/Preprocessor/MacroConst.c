#include <stdio.h>

// #define:Object-like macro (완전한 의미를 갖는 대상이나 사물)
#define NAME "김도현"
#define AGE	24
#define PRINT_ADDR puts("주소: 블라블라~ \n");

int main() {
	printf("이름: %s \n", NAME);
	printf("나이: %d \n", AGE);
	PRINT_ADDR;
	return 0;
}